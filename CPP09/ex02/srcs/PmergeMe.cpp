/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/06 15:15:01 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

typedef enum e_cont_type
{
    VECTOR,
    DEQUE
} e_cont_type;

// default constructor
PmergeMe::PmergeMe() {}

// copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

// assignment operator (overload)
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

// destructor
PmergeMe::~PmergeMe() {}

// utils
// A util function to show all the elements
void showElements(IntVect::iterator start, IntVect::iterator end)
{
    for (; start != end; start++)
        std::cout << *start << " ";
    std::cout << std::endl;
}

// get timestamp in microseconds unit
double getTimeStamp()
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return time.tv_usec + (time.tv_sec * 1000000);
}

// show timestamp
static void showTimeStamp(size_t size, double elapsedTime, e_cont_type cont_type)
{
    std::cout << "Time to process a range of " << std::right << std::setw(6) << size << " elements with std::" << std::left << std::setw(6) << (cont_type == VECTOR ? "vector" : "deque") << " : " << std::fixed << std::setprecision(5) << elapsedTime << " μs" << std::endl;
}

// Parsing
/**
 * @brief Check if the given string is a valid positive integer string
 *
 * @details
 * A string is consider a valid positive integer string if:
 * 1. Has a '+' a the start of the string (optional)
 * 2. Only consists of digits
 */
static void checkIfPositiveIntegerString(std::string &intStr)
{
    std::string newStr = intStr;

    // if it's something like '+123', erase the '+' sign and let str to become '123'
    if (!newStr.empty() && newStr[0] == '+')
        newStr.erase(newStr.begin());
    for (std::string::const_iterator it = newStr.begin(); it != newStr.end(); it++)
    {
        if (!isdigit(*it))
            throw PmergeMe::PmergeMeInvalidArgument(intStr);
    }
    intStr = newStr;
}

/**
 * @brief Convert the string into an integer
 *
 * @details
 * 1. Convert the string into a long value
 * 2. Check if the value exceed 0 OR INT_MAX
 * 3. Return the value as int
 */
static int convertToInt(const std::string &instStr)
{
    long valueAsLong = strtol(instStr.c_str(), NULL, 10);

    if (valueAsLong < 0 || valueAsLong > std::numeric_limits<int>::max())
        throw PmergeMe::PmergeMeValueExceedRange(instStr);
    return static_cast<int>(valueAsLong);
}

/**
 * @brief Parsing
 * 1. Check if the string is a positive integer string
 * 2. Check if the value is within range
 * 3. Create a int vector
 */
static void parseElements(StrVect &args, IntVect &elements)
{
    int value;
    IntVect::iterator searchResult;

    for (StrVect::iterator it = args.begin(); it != args.end(); it++)
    {
        checkIfPositiveIntegerString(*it);
        value = convertToInt(*it);
        searchResult = std::find(elements.begin(), elements.end(), value);
        if (searchResult != elements.end())
            throw PmergeMe::PmergeMeDuplicateElement(*it);
        elements.push_back(value);
    }
}

/**
 * @brief Custom comparator function for lower_bound
*/
bool comparator(const GroupIterator<IntVectIte> &lhs, const int &rhs)
{
    return *lhs < rhs;
}

/**
 * @brief Sort and swap pairs. Each pair consist of two element/group. The ideal order of the pair is [small, large].
*/
static void sortAndSwapPairs(GroupIterator<IntVectIte> begin, GroupIterator<IntVectIte> end)
{
    for (GroupIterator<IntVectIte> it = begin; it != end; it += 2)
    {
        if (*(it + 1) < *it)
            swapRange(it, it + 1);
    }
}

/**
 * @brief Set up main chain and pend
 * 
 * Definition:
 * -- Main Chain --
 * The main chain is a list that stores all our sorted elements or groups.
 * 
 * -- Pend --
 * The pend is used to record the ideal insertion locations for the remaining elements.
 * These ideal locations are used as starting points for binary insertion, avoiding unnecessary search.
 * 
 * 
 * Key Points / Facts:
 * 1. After sorting the pairs, the first pair comprises:
 *      a. The smallest larger number among all the pairs (begin + 1).
 *      b. The smaller number in the pair is guaranteed to be smaller than all the larger numbers in all pairs (begin).
 *    Therefore, it's safe to initialize the main chain with these two numbers first.
 * 
 * 2. For all the smaller numbers in each pair (excluding the first one, which is already in the main chain),
 *    they will be inserted before their corresponding larger number pair. We record these 'ideal locations' in pend.
 *    Pend stores iterators indicating where the smaller elements should be inserted during binary insertion.
*/
static void setupChainAndPend(GroupIterator<IntVectIte> begin, size_t size, MainChain &mainChain, Pend &pend)
{   
    mainChain.push_back(begin);
    mainChain.push_back(begin + 1);

    size_t index = (4 - 1);
    for (; index < size; index += 2)
    {
        MainChainIte loc = mainChain.insert(std::end(mainChain), (begin + index));
        pend.push_back(loc);
    }
}

/**
 * @brief Insert pending elements from 'pend' into 'mainChain' at ideal insertion locations.
 * 
 * This function iterates through the 'pend' container in parallel with the smaller values of each pair.
 * For each pending element, it performs a binary search within 'mainChain' to find the ideal insertion
 * location and then inserts the element at that position.
 * 
 * If there's a leftover element ('leftOver') during this recursive call, it is also inserted into 'mainChain.'
 * For the leftover element, since we don't know the ideal location, we perform a binary search within 'mainChain.'
*/
static void insertPendToMainChain(MainChain &mainChain, Pend &pend, GroupIterator<IntVectIte> &begin, bool hasLeftover, GroupIterator<IntVectIte> &leftOver)
{
    Pend::iterator currentPend = pend.begin();
    GroupIterator<IntVectIte> pendValue = begin + 2; // the 2nd smaller value in all pairs
    
    for (; currentPend != pend.end(); currentPend += 1)
    {
        // Find insertion position using binary search
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), *currentPend, *pendValue, comparator);
        mainChain.insert(insertPos, pendValue);
        pendValue += 2;
    }
    
    if (hasLeftover)
    {
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), *leftOver, comparator);
        mainChain.insert(insertPos, leftOver);
    }
}

/**
 * @brief Synchronize changes from the main chain back to the original data structure.
 * 
 * This function is responsible for copying the sorted elements from the main chain
 * back to the original data structure indicated by 'begin'. It utilizes a temporary
 * cache to efficiently store the sorted elements before moving them back.
*/
static void syncChanges(MainChain &mainChain, GroupIterator<IntVectIte> &begin)
{
    IntVect cache;

    for (MainChainIte it = mainChain.begin(); it != mainChain.end(); ++it)
    {
        // Get the group iterator from the main chain
        GroupIterator<IntVectIte> groupIter = *it;

        // Extract the begin and end iterators for the group
        IntVectIte begin = groupIter.base();
        IntVectIte end = begin + groupIter.size();

        // Move the elements from the group to the cache
        std::move(begin, end, std::back_inserter(cache));
    }
    // Move the sorted elements from the cache back to the original data structure
    std::move(std::begin(cache), std::end(cache), begin.base());
}

/**
 * @brief Ford-Johnson Algorithm (Merge-Insertion sort)
 * 
 * Ford-Johnson algorithm is a recursive sorting algorithm.
 * Base case: When the number of elements/groups is less than 2.
 * 
 * The flow of Ford-Johnson algorithm:
 * 1. Check if there is a leftover element. This occurs if the number of elements/groups is odd.
 *      a. If there's a leftover, initialize an iterator to point to it, ensuring it's not passed during iteration.
 * 2. Pair the elements/groups into n/2 pairs and sort them pairwise. The order should be [Small, Large].
 * 3. Populate main chain & pend:
 *      a. Main chain stores the sorted list.
 *      b. Pend stores iterators indicating where smaller elements should be inserted during binary insertion.
 * 4. Insert elements in pend to the main chain using binary insertion.
 * 5. Synchronize the main chain with the original data structure (e.g., vector, list, deque).
 * 
 * In each recursive call, the size of each group doubles, and all steps are executed recursively.
 * 
 * <>: leftover, ||: group/element
 * 
 *                               16 , 91 , 61 , 30 , 8 , 44 , 72 , 17 , 19 , 34 
 * 0-     Initial pairing:      |16|,|91|,|61|,|30|,|8|,|44|,|72|,|17|,|19|,|34|
 *          Sort pairwise:      |16|,|91|,|30|,|61|,|8|,|44|,|17|,|72|,|19|,|34| (when we sort, we look at the last number of that group, ensure that it's |small|, |large|, |small|, |large|, ...)
 * 1-Continuation ranking:      |16 , 91|,|30 , 61|,|8 , 44|,|17 , 72|,<19 , 34> (pair them again, but this time group size is 2 * 2)
 *          Sort pairwise:      |30 , 61|,|16 , 91|,|8 , 44|,|17 , 72|
 * 2-Continuation ranking:      |30 , 61 , 16 , 91|,|8 , 44 , 17 , 72|
 *    Sort pairwise again:      |8 , 44 , 17 , 72|,|30 , 61 , 16 , 91|
 * 3-Continuation ranking:      |8 , 44 , 17 , 72 , 30 , 61 , 16 , 91| (opps, number of element is < 2. Stop recursion. PS:|| should consider as one element.)
 * 
 * 2-          Main chain:      72 , 91
 *                   Pend:      (empty)
 * 1-          Main chain:      44 , 72 , 91
 *                   Pend:      61 , <34> (leftover)
 *              Insertion:      34 , 44 , 61 , 72 , 91
 * 0-          Main chain:      19 , 34 , 44 , 61 , 72 , 91
 *                   Pend:      8  , 30 , 17 , 16
 *              Insertion:      8 , 16 , 17 , 19 , 30 , 34 , 44 , 61 , 72 , 91 (SORTED)
 */
static void fordJohnsonSort(GroupIterator<IntVectIte> begin, GroupIterator<IntVectIte> end)
{
    size_t size = begin.distance(end);

    // base case
    if (size < 2) return;

    // checks for leftover element
    bool hasLeftover = size % 2 != 0;
    GroupIterator<IntVectIte> endIte = hasLeftover ? --end : end;

    // pair elements into n/2 pairs and sort them pairwise
    sortAndSwapPairs(begin, endIte);

    // recursively create pairs and sort
    fordJohnsonSort(GroupIterator<IntVectIte>(begin, begin.size() * 2), GroupIterator<IntVectIte>(end, end.size() * 2));

    // populate main chain and pend
    MainChain mainChain;
    Pend pend;
    setupChainAndPend(begin, (hasLeftover ? size - 1 : size), mainChain, pend);

    // binary insertion
    insertPendToMainChain(mainChain, pend, begin, hasLeftover, endIte);

    // synchronize main chain to the original data structure
    syncChanges(mainChain, begin);
}

static void fordJohnsonSort(IntDeq &elements)
{
    (void)elements;
}

/**
 * @brief Main function
 * 1. Parse elements
 * 2. Show elements (before & after)
 * 3. Show time to process
 *
 * ./PmergeMe `jot -r 5 1 100000 | tr '\n' ' '`
 * ./PmergeMe `python -c "import random; print(' '.join(map(str, random.sample(range(1, 100000), 10000))))"`
 */
void PmergeMe::mergeMe(StrVect &args)
{
    IntVect elementsVector;
    IntDeq elementsDeque;

    if (args.size() < 2)
        throw PmergeMe::PmergeMeNotEnoughElements();

    try
    {
        parseElements(args, elementsVector);
        // copy the value of vector into deque
        std::copy(elementsVector.begin(), elementsVector.end(), std::inserter(elementsDeque, elementsDeque.end()));

        // Display all the elements before sorting
        std::cout << std::left << std::setw(10) << "Before:";
        showElements(elementsVector.begin(), elementsVector.end());

        // Record the start time (for vector)
        double startVector = getTimeStamp();
        // Sort (vector)
        fordJohnsonSort(GroupIterator<IntVectIte>(elementsVector.begin(), 1), GroupIterator<IntVectIte>(elementsVector.end(), 1));
        // Record the end time
        double endVector = getTimeStamp();
        double elapsedMicrosecondsVector = endVector - startVector;

        // Record the start time (for deque)
        double startDeque = getTimeStamp();
        // Sort (deque)
        fordJohnsonSort(elementsDeque);
        // Record the end time
        double endDeque = getTimeStamp();
        double elapsedMicrosecondsDeque = endDeque - startDeque;

        // Display all the elements after sorting
        std::cout << std::left << std::setw(10) << "After:";
        showElements(elementsVector.begin(), elementsVector.end());
        showTimeStamp(elementsVector.size(), elapsedMicrosecondsVector, VECTOR);
        showTimeStamp(elementsDeque.size(), elapsedMicrosecondsDeque, DEQUE);
    }
    catch (const std::exception &ex)
    {
        std::cout << BYELLOW << ex.what() << RESET << std::endl;
    }
}

// exceptions
const char *PmergeMe::PmergeMeInvalidArgument::what() const throw()
{
    static char msg[1024];
    strcpy(msg, "[ERROR]: Invalid argument -> ");
    strcat(msg, _args.c_str());
    return msg;
}

const char *PmergeMe::PmergeMeValueExceedRange::what() const throw()
{
    static char msg[1024];
    strcpy(msg, "[ERROR]: Argument exceed range! (0 - INT_MAX) -> ");
    strcat(msg, _args.c_str());
    return msg;
}

const char *PmergeMe::PmergeMeDuplicateElement::what() const throw()
{
    static char msg[1024];
    strcpy(msg, "[ERROR]: Found duplicate element! -> ");
    strcat(msg, _args.c_str());
    return msg;
}

const char *PmergeMe::PmergeMeNotEnoughElements::what() const throw()
{
    return "[ERROR]: Not enough elements to compare!";
}
