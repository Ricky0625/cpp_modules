/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:59:38 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/03 20:33:50 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/************************************************************
 * The member below has no meaning, will not be using these *
 *      Static class should not be able to instantiate      *
 ************************************************************/

// default constructor
ScalarConverter::ScalarConverter() {}

// copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

// assignment operator (overload)
ScalarConverter    &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

// destructor
ScalarConverter::~ScalarConverter() {}

/**
 * Specification for each data if we were to identify the given
 * string belongs to which data type
 * 
 * char:
 *  - one character: A, a, -, 0, *, ;
 *  - three character: 'A', 'a', '-', '0', '*', ';', surrounded by ''
 * 
 * int:
 *  - can have +/- character (one only and optional)
 *  - numeric value
 *  - in between INT_MIN & INT_MAX (inclusive)
 * 
 * float:
 *  - can have +/- character (one only and optional)
 *  - numeric value
 *  - end with 'f' character, if no 'f' means it's double
 *  - has only one '.'
 *  - can start with '.'
 *  - in between float min and float max (inclusive)
 *  - pseudo literals: -inff, +inff, nanf
 * 
 * double:
 *  - can have +/- character (one only and optional)
 *  - numeric value
 *  - has only one '.'
 *  - can start with '.'
 *  - in between double min and double max
 *  - pseudo literals: -inf, +inf, nan
 * 
 * Should convert to double first then downcast from it.
 * double > float > int > char
*/

bool hasOneOccurrence(const std::string &str, char ch)
{
    size_t  firstOccurrence = str.find_first_of(ch);
    size_t  lastOccurrence = str.find_last_of(ch);

    return (firstOccurrence != std::string::npos) && (firstOccurrence == lastOccurrence);
}

// void    isConvertable(const std::string &str, int &res)
// {}

/**
 * FLOW OF SCALAR CONVERTER
 * 1. Check if the string has only one set of value.
 * 2. Check if the string is convertable by identify the type
 *      - check if it's one of the pseudo literals (+/-inf, +/-inff, nan)
 *      - does the string fulfill the specification of each of the data type? (char, int, float, double)
 *      - if not convertable, what does that string means in each of the data type? (impossible)
 *          - non-displayable (for char)
 *          - out-of-range (self-defined, quite descriptive enough, only for numeric values)
 * 3. Supposingly, if the string can pass all the checking above, meaning it's convertable. From here,
 *    we want to perform down-casting. But before we do so, we need to check if the value is within range.
 *    If it is, then ok, down-cast it. The order should be double > float > int > char so that the accuracy
 *    and precision of the value will lose in process. Store the value in an array.
 * 4. Print the value of the array.
 * 5. RMB to free the array.
 * 
 * Edge cases:
 * 1. will not accept something like so: "3.14 44". strtod will handle it but it does not make sense for me.
 * 2. this is ok. " 3.14        ". as long as there's no second set of value
 * 
*/
void    ScalarConverter::convert(const std::string &str)
{
    // int     *res = new int(4);
    char    *remainer;
    double number = strtod(str.c_str(), &remainer);
    
    // if (remainer != NULL)
        std::cout << std::string(remainer).length() << std::endl;
        
    std::cout << "ScalarConverter: " << BGREEN << str << RESET << std::endl;
    // std::cout << number << std::endl;
    std::cout << static_cast<int>(number) << std::endl;
    std::cout << static_cast<float>(number) << std::endl;
    std::cout << static_cast<char>(365) << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    // std::cout << std::numeric_limits<double>::min() << std::endl; // the smallest positive value a double can hold
    // std::cout << -std::numeric_limits<double>::max() << std::endl; // the largest negative value that can be represented by a double
}

/**
 * min/max of each data type
 * int:
 *      min: std::numeric_limits<int>::min()
 *      max: std::numeric_limits<int>::max()
 *
 * char:
 *      min: std::numeric_limits<unsigned char>::min()
 *      max: std::numeric_limits<unsigned char>::max()
 * 
 * float:
 *      min: -std::numeric_limits<float>::max()
 *      max: std::numeric_limits<float>::max()
 * 
 * double:
 *      min: -std::numeric_limits<double>::max()
 *      max: std::numeric_limits<double>::max()
*/
