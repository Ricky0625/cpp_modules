/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/28 21:04:34 by wricky-t         ###   ########.fr       */
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

unsigned long long getCurrentTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<unsigned long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
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
    for (StrVect::iterator it = args.begin(); it != args.end(); it++)
    {
        checkIfPositiveIntegerString(*it);
        elements.push_back(convertToInt(*it));
    }
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
static void fordJohnsonSort(GroupIterator<IntVectIte> begin, GroupIterator<IntVectIte> end)
{
    // check if there's leftover
    size_t  size = begin.distance(end);
    
    if (size < 2) return;

    bool hasLeftover = size % 2 != 0;
    GroupIterator<IntVectIte> endIte = hasLeftover ? --end : end;
    
    // initial pairing
    for (GroupIterator<IntVectIte> it = begin; it != endIte; it += 2)
    {
        std::cout << "comparing: " << *(it + 1) << " & " << *it << std::endl;
        if (*(it + 1) < *it)
            swapRange(it, it + 1);
    }
    std::cout << std::endl;
    
    // continuation ranking
    fordJohnsonSort(GroupIterator<IntVectIte>(begin, begin.size() * 2), GroupIterator<IntVectIte>(endIte, endIte.size() * 2));

    // construct main chain, pend chain

    // insertion sort (jacob number, binary search, insert)
}

static void fordJohnsonSort(IntDeq &elements)
{
    (void)elements;
}

void showTimeStamp(size_t size, unsigned long long elapsedTime, e_cont_type cont_type)
{
    std::cout << "Time to process a range of " << std::right << std::setw(6) << size << " elements with std::" << std::left << std::setw(6) << (cont_type == VECTOR ? "vector" : "deque") << " : " << elapsedTime << std::endl;
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
        unsigned long long startVector = getCurrentTimeInMicroseconds();
        // Sort
        fordJohnsonSort(GroupIterator<IntVectIte>(elementsVector.begin(), 1), GroupIterator<IntVectIte>(elementsVector.end(), 1));
        // Record the end time
        unsigned long long endVector = getCurrentTimeInMicroseconds();
        unsigned long long elapsedMicrosecondsVector = endVector - startVector;

        // Record the start time (for deque)
        unsigned long long startDeque = getCurrentTimeInMicroseconds();
        // Sort
        fordJohnsonSort(elementsDeque);
        // Record the end time
        unsigned long long endDeque = getCurrentTimeInMicroseconds();
        unsigned long long elapsedMicrosecondsDeque = endDeque - startDeque;

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

const char *PmergeMe::PmergeMeNotEnoughElements::what() const throw()
{
    return "[ERROR]: Not enough elements to compare!";
}
