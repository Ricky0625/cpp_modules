/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:13 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// default constructor
PmergeMe::PmergeMe() {}

// copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

// assignment operator (overload)
PmergeMe    &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

// destructor
PmergeMe::~PmergeMe() {}

// utils
// A util function to show all the elements
void showElements(const IntVector &elements)
{
    for (IntVector::const_iterator it = elements.begin(); it != elements.end(); it++)
        std::cout << *it << " ";
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
static void parseElements(StrVector &args, IntVector &elements)
{
    for (StrVector::iterator it = args.begin(); it != args.end(); it++)
    {
        checkIfPositiveIntegerString(*it);
        elements.push_back(convertToInt(*it));
    }
}

/**
 * @brief The heart of the program. Ford-Johnson Algorithm (Merge-Insertion sort)
*/
static void fordJohnsonSort(IntVector &elements)
{
    (void)elements;
}

void showTimeStamp(size_t size, unsigned long long elapsedTime)
{
    std::cout << "Time to process a range of " << std::setw(6) << size << " elements with std::[..] : " << elapsedTime << std::endl;
}

/**
 * @brief Main function
 * 1. Parse elements
 * 2. Show elements (before & after)
 * 3. Show time to process
 * 
 * ./PmergeMe `jot -r 5 1 100000 | tr '\n' ' '`
*/
void PmergeMe::mergeMe(StrVector &args)
{
    IntVector elements;

    try
    {
        parseElements(args, elements);
        std::cout << std::left << std::setw(10) << "Before:";
        showElements(elements);
        
        // Record the start time
        unsigned long long start = getCurrentTimeInMicroseconds();
        // Sort
        fordJohnsonSort(elements);
        // Record the end time
        unsigned long long end = getCurrentTimeInMicroseconds();
        
        unsigned long long elapsedMicroseconds = end - start;
        
        std::cout << std::left << std::setw(10) << "After:";
        showElements(elements);
        showTimeStamp(elements.size(), elapsedMicroseconds);
    }
    catch (const std::exception &ex)
    {
        std::cout << BYELLOW << ex.what() << RESET << std::endl;
    }
}

// exceptions

const char *PmergeMe::PmergeMeInvalidArgument::what() const throw()
{
    std::string msg("[ERROR]: Invalid argument -> " + _args);

    char *msgCStr = new char[msg.size() + 1];
    std::strcpy(msgCStr, msg.c_str());
    return msgCStr;
}

const char *PmergeMe::PmergeMeValueExceedRange::what() const throw()
{
    std::string msg("[ERROR]: Argument exceed range! (0 - INT_MAX) -> " + _args);

    char *msgCStr = new char[msg.size() + 1];
    std::strcpy(msgCStr, msg.c_str());
    return msgCStr;
}
