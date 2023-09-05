/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/05 19:14:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int iteration = 0;

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

double getTimeStamp()
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_usec / 1000) + (time.tv_sec * 1000);
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

bool comparator(const GroupIterator<IntVectIte> &lhs, const int &rhs)
{
    return *lhs < rhs;
}

void continuationRanking(GroupIterator<IntVectIte>begin, GroupIterator<IntVectIte> end)
{
    size_t size = begin.distance(end);

    // if size less than 2 meaning there's not enough of elements/group to compare
    if (size < 2) return;

    // check if there's a left over, ensure that when comparing, the number of group should be a even number
    bool hasLeftover = size % 2 != 0;
    GroupIterator<IntVectIte> endIte = hasLeftover ? --end : end;

    // pairing & compare
    for (GroupIterator<IntVectIte> it = begin; it != endIte; it += 2)
    {
        if (*(it + 1) < *it)
            swapRange(it, it + 1);
    }

    // continue to rank the groups, group size multiply by 2 in each recursive call    
    continuationRanking(GroupIterator<IntVectIte>(begin, begin.size() * 2), GroupIterator<IntVectIte>(endIte, endIte.size() * 2));

    // construct main chain and pend here.
    MainChain mainChain;
    Pend pend;
    
    // The first pair comprises the smallest larger number among all the pairs. (begin + 1)
    // Also, the smaller number in the pair is guarantee to be smaller than that smallest larget number, so
    // we can push it onto the vector too. (begin)
    mainChain.push_back(begin);
    mainChain.push_back(begin + 1);

    // ok... this seems like a magic number (4 - 1). let's recap a bit.
    // since we sorted everything in pairwise, so each element/group will be in this order: [small, large], [small, large], ...
    // and before this we already push the element in the first pair to the main chain. so we need to skip 2 index (0, 1).
    // ok... but why do we need to skip another one? because we are just pushing the larger number of each pair to main chain.
    // hence, if we look at the order again, the next larger one in a pair is actually at index 3. Yup, that's it.
    size_t index = (4 - 1);
    for (; index < (hasLeftover ? size - 1 : size); index += 2)
    {
        MainChainIte loc = mainChain.insert(std::end(mainChain), (begin + index));
        pend.push_back(loc);
    }

    // binary insertion
    Pend::iterator currentPend = pend.begin();
    GroupIterator<IntVectIte> pendValue = begin + 2;
    // iterate through all the pends element
    for (; currentPend != pend.end(); currentPend += 1)
    {
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), *currentPend, *pendValue, comparator);
        mainChain.insert(insertPos, pendValue);
        pendValue += 2;
    }

    // TODO: Insert leftover to pend instead
    // handle the leftover, insert it to the mainChain
    if (hasLeftover)
    {
        MainChainIte insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), *endIte, comparator);
        mainChain.insert(insertPos, endIte);
    }

    // sync the main chain to the original chain here.
    IntVect cache;
    
    for (MainChainIte it = mainChain.begin(); it != mainChain.end(); ++it)
    {
        GroupIterator<IntVectIte> groupIter = *it;
        IntVectIte begin = groupIter.base();
        IntVectIte end = begin + groupIter.size();
        std::move(begin, end, std::back_inserter(cache));
    }
    std::move(std::begin(cache), std::end(cache), begin.base());
}

/**
 * @brief The heart of the program. Ford-Johnson Algorithm (Merge-Insertion sort)
 * 1. Initial pairing (first round matches)
 *      - Implement the initial pairing of elements and perform comparision to establish an initial ranking.
 * 2. Continuation ranking (advancing winners)
 *      - Determine how winners from the previous round will advance to the next round, and implement necessary
 *        comparisons and ranking updates
 * 3. Main chain insertion (efficient ranking)
 *      - Insert additional players into the main chain efficiently. Use binary search to search for the insertion location.
 */
static void fordJohnsonSort(IntVectIte begin, IntVectIte end)
{
    /**
     * Initial ranking & continuation ranking
     * 1. Initial ranking - Establish the initial ranking of the elements. [small, big]
     * 2. Continuation ranking - The group size will multiply by 2 in each recursive call, do the same thing as initial ranking.
    */
    continuationRanking(GroupIterator<IntVectIte>(begin, 1), GroupIterator<IntVectIte>(end, 1));
}

static void fordJohnsonSort(IntDeq &elements)
{
    (void)elements;
}

void showTimeStamp(size_t size, double elapsedTime, e_cont_type cont_type)
{
    std::cout << "Time to process a range of " << std::right << std::setw(6) << size << " elements with std::" << std::left << std::setw(6) << (cont_type == VECTOR ? "vector" : "deque") << " : " << std::fixed << std::setprecision(5) << elapsedTime << " μs" << std::endl;
}

/**
 * @brief Main function
 * 1. Parse elements
 * 2. Show elements (before & after)
 * 3. Show time to process
 *
 * ./PmergeMe `jot -r 5 1 100000 | tr '\n' ' '`
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
        fordJohnsonSort(elementsVector.begin(), elementsVector.end());
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
