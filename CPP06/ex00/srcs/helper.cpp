/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:26:03 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/14 14:36:26 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include "ScalarConverter.hpp"

/*************************
 *         HELPER        *
 *************************/

/**
 * Verify if a string has an occurrence of that character.
 * 1. If the first occurrence is not npos, meaning there's an occurrence of the character.
 * 2. If there's an occurrence, check if the last occurrence's position is the same as the first occurrence's position.
 */
bool hasOneOccurrence(const std::string &str, char ch)
{
    size_t firstOccurrence = str.find_first_of(ch);
    size_t lastOccurrence = str.find_last_of(ch);

    return (firstOccurrence != std::string::npos) && (firstOccurrence == lastOccurrence);
}

/**
 * Get the number of digit behind the decimal point
 */
size_t getPrecision(const std::string &str)
{
    size_t len = str.length();
    size_t decimalPointPos = str.find('.');

    // since the precision is calculated based on the position of decimal point and length, 'f' should not be considered
    if (str[len - 1] == 'f')
        len--;

    // when the given string is recognized as int; float and double should at least has 1 precision
    // OR
    // when there's a decimal point but it's at the end of the string, float and double should at least has 1 precision
    if (decimalPointPos == std::string::npos || (decimalPointPos == len - 1))
        return 1;

    // if the decimalPointPos is less than the length of the string
    // get the precision using len - (decimalPointPos + 1)
    // the reason behind that "+ 1" is len start counting from 1, index start counting from 0
    if (decimalPointPos < len)
        return len - (decimalPointPos + 1);

    // for whatever reason, just return 1 as default
    return 1;
}

/*************************
 *        PRINTER        *
 *************************/

/**
 * Print the data type identifier
 */
static void printDataType(e_type type)
{
    if (!(type >= CHAR && type <= DOUBLE))
        return;
    switch (type)
    {
    case CHAR:
        std::cout << std::setw(6) << "char";
        break;
    case INT:
        std::cout << std::setw(6) << "int";
        break;
    case FLOAT:
        std::cout << std::setw(6) << "float";
        break;
    case DOUBLE:
        std::cout << std::setw(6) << "double";
        break;
    }
    std::cout << ": ";
}

/**
 * Print pseudo literals
 */
static void printPseudoLiterals(e_convert_type ctype)
{
    switch (ctype)
    {
    case E_IMPOSSIBLE:
        std::cout << "impossible";
        break;
    case E_NANF:
        std::cout << "nanf";
        break;
    case E_NAN:
        std::cout << "nan";
        break;
    case E_PINFF:
        std::cout << "+inff";
        break;
    case E_PINF:
        std::cout << "+inf";
        break;
    case E_NINFF:
        std::cout << "-inff";
        break;
    case E_NINF:
        std::cout << "-inf";
        break;
    case E_CONVERTABLE:
        break;
    }
}

void printConvertedValue(e_type type, const double &value, const size_t &precision)
{
    if (!(type >= CHAR && type <= DOUBLE))
    {
        std::cout << BRED "UNKNOWN TYPE!" RESET;
        exit(EXIT_FAILURE);
    }

    if (type == CHAR)
    {
        if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
            std::cout << "overflow";
        else if ((value <= 31) || value == 127)
            std::cout << "non-displayable";
        else
            std::cout << "'" << static_cast<unsigned char>(value) << "'";
        return;
    }

    if (type == INT)
    {
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            std::cout << "overflow";
        else
            std::cout << static_cast<int>(value);
        return;
    }

    if (type == FLOAT)
    {
        if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
            std::cout << "overflow";
        else
            std::cout << std::fixed << std::setprecision((precision > FLOAT_MAX_PRECISION ? FLOAT_MAX_PRECISION : precision)) << static_cast<float>(value) << "f";
        return;
    }

    if (type == DOUBLE)
    {
        if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
            std::cout << "overflow";
        else
            std::cout << std::fixed << std::setprecision((precision > DOUBLE_MAX_PRECISION ? DOUBLE_MAX_PRECISION : precision)) << value;
        return;
    }
}

/**
 * The function that print out everything
 */
void printConverted(int *converted, const double value, const size_t precision)
{
    e_convert_type cvtype = E_CONVERTABLE;

    for (int i = 0; i < 4; i++)
    {
        cvtype = (e_convert_type)converted[i];
        printDataType((e_type)i);
        if (cvtype != E_CONVERTABLE)
            printPseudoLiterals(cvtype);
        else
            printConvertedValue((e_type)i, value, precision);
        std::cout << std::endl;
    }
}

/*************************
 *        DETECTOR       *
 *************************/

/**
 * Check if the string is one of the pseudo literal.
 * If it is, set the value of each data type to the relevant enum.
 * Return true if it's one of the pseudo literal. Otherwise, false.
 */
bool isPseudoLiteral(const std::string &str, int *converted)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "inf" || str == "inff")
    {
        converted[CHAR] = E_IMPOSSIBLE;
        converted[INT] = E_IMPOSSIBLE;
    }
    if (str == "nan" || str == "nanf")
    {
        converted[FLOAT] = E_NANF;
        converted[DOUBLE] = E_NAN;
        return true;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        converted[FLOAT] = E_PINFF;
        converted[DOUBLE] = E_PINF;
        return true;
    }
    else if (str == "-inf" || str == "-inff")
    {
        converted[FLOAT] = E_NINFF;
        converted[DOUBLE] = E_NINF;
        return true;
    }
    return false;
}

/**
 * Check if the string matches the specification of a char. Should be able to accept something like:
 * 1. a
 * 2. 'a'
 */
static bool isChar(const std::string &str, double &value)
{
    size_t len = str.length();

    if (!(len == 1 || (len == 3 && (str[0] == '\'' && str[2] == '\''))))
        return false;

    // if length is 3 and can run the code below, it's definitely something like this: 'a'.
    // in this case, value is str[1]. else, value is str[0].
    value = (len == 3) ? str[1] : str[0];
    return true;
}

/**
 * Check if the string matches the specification of an int. Should be able to accept something like:
 * 1. 123123124123
 * 2. -123123123
 * 3. +123124123
 *
 * NOTE: Not consider if it overflows or not. Will consider before static_cast
 */
static bool isInt(const std::string &str, double &value)
{
    size_t index = 0;
    size_t len = str.length();

    // if the first character is a '+'/'-', skip it.
    if (str[0] == '+' || str[0] == '-')
        index++;
    // iterate through the string, check if every character is a digit
    for (; index < len; index++)
    {
        if (!isdigit(str[index]))
            return false;
    }
    // if the loop can iterate through the string, meaning it's convertable, convert it to double.
    value = strtod(str.c_str(), NULL);
    return true;
}

/**
 * Check if the string matches the specification of a float. Should be able to accept something like:
 * 1. .0f
 * 2. 0.f
 * 3. 1.123124f
 * 4. -.0f
 * 5. +.0f
 * 6. -0.f
 * 7. +0.f
 */
static bool isFloat(const std::string &str, double &value)
{
    // check if the string has a 'f' & '.'. If not, it does not matches the specification of a float.
    if (!(hasOneOccurrence(str, 'f') && hasOneOccurrence(str, '.')))
        return false;

    size_t index = 0;
    size_t len = str.length();

    // to prevent something like this: 123f23. 'f' character should always at the end of the string.
    if (str.find('f') != len - 1)
        return false;

    // if the first character is a '+'/'-', skip it.
    if (str[0] == '+' || str[0] == '-')
        index++;

    // if the code below can run, meaning that there's a 'f' and a '.' in the string
    // the minimum possible length of the string is 2, which if '.f'.
    // another possible combination: '-.f', '+.f'
    if (len == 2 || (len == 3 && index == 1))
        return false;

    // iterate through the string and check if every character is a digit. If encounter a '.' or 'f', skip it (should only detect one)
    for (; index < len; index++)
    {
        if (str[index] == 'f' || str[index] == '.')
            continue;
        if (!isdigit(str[index]))
            return false;
    }
    // if the loop can iterate through the string, meaning it's convertable, convert it to double.
    value = strtod(str.c_str(), NULL);
    return true;
}

/**
 * Check if the string matches the specification of a float. Should be able to accept something like:
 * 1. .0
 * 2. 0.
 * 3. 1.123124
 * 4. -.0
 * 5. +.0
 * 6. -0.
 * 7. +0.
 */
static bool isDouble(const std::string &str, double &value)
{
    // check if the string has one occurrence of '.'. double must has one '.'
    if (!(hasOneOccurrence(str, '.')))
        return false;

    size_t index = 0;
    size_t len = str.length();

    // if the first character is a '+'/'-', skip it.
    if (str[0] == '+' || str[0] == '-')
        index++;

    // if the code below can run, meaning that there's a '.' in the string
    // the minimum possible length of the string is 1, which is '.' (even though this will be treated as CHAR at the beginning)
    // another possible combination: '-.', '+.' (len == 2 && index == 1)
    if (len == 1 || (len == 2 && index == 1))
        return false;

    // iterate through the string and check if every character is a digit. If encounter a '.' skip it (should only detect one)
    for (; index < len; index++)
    {
        if (str[index] == '.')
            continue;
        if (!isdigit(str[index]))
            return false;
    }
    // if the loop can iterate through the string, meaning it's convertable, convert it to double.
    value = strtod(str.c_str(), NULL);
    return true;
}

/**
 * Check if the given string matches one of the specification of data type.
 * If true, meaning it's convertable. Otherwise, false.
 */
bool isConvertable(const std::string &str, double &value, size_t &precision)
{
    if (str.length() == 0)
        return false;

    // The order matters! 1 should be treated as 1 not chararcter '1' which has a value of 49
    if (isInt(str, value) || isFloat(str, value) || isDouble(str, value) || isChar(str, value))
    {
        precision = getPrecision(str);
        return true;
    }
    return false;
}
