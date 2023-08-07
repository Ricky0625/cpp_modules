/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:59:38 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 18:58:28 by wricky-t         ###   ########.fr       */
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
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
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

void ScalarConverter::convert(const std::string &str)
{
    int converted[4] = {E_CONVERTABLE, E_CONVERTABLE, E_CONVERTABLE, E_CONVERTABLE};

    // check if the string is one of the pseudo literal
    if (isPseudoLiteral(str, converted))
    {
        printConverted(converted);
        return;
    }

    double value;
    size_t precision;

    // check if the string is convertable, according to the specification of each data type
    if (isConvertable(str, value, precision))
    {
        printConverted(converted, value, precision);
        return;
    }

    std::cout << BRED "The given string cannot be converted." RESET << std::endl;
    return;
}
