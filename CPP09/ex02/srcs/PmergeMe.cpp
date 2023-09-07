/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:30:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/07 14:09:15 by wricky-t         ###   ########.fr       */
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
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

// destructor
PmergeMe::~PmergeMe() {}

// util
// get timestamp in microseconds unit
double getTimeStamp()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return time.tv_usec + (time.tv_sec * 1000000);
}

// show timestamp
void showTimeStamp(size_t size, double elapsedTime, e_cont_type cont_type)
{
    std::cout << "Time to process a range of " << std::right << std::setw(6) << size << " elements with " << (cont_type == VECTOR ? BYELLOW : BGREEN) << "std::" << std::left << std::setw(6) << (cont_type == VECTOR ? "vector" : "deque") << RESET << " : " << std::fixed << std::setprecision(5) << (cont_type == VECTOR ? BYELLOW : BGREEN) << elapsedTime << " μs" << RESET << std::endl;
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
    IntVect original;

    if (args.size() < 2)
        throw PmergeMe::PmergeMeNotEnoughElements();

    try
    {
        double parsingStartTime = getTimeStamp();
        double parsingEndTime;
        
        parseElements(args, original);
        parsingEndTime = getTimeStamp();
        std::cout << "Parsing time: " << parsingEndTime - parsingStartTime << std::endl;
        vectorRunner(original, parsingEndTime - parsingStartTime);
        std::cout << std::endl;
        dequeRunner(original, parsingEndTime - parsingStartTime);
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
