/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:59:38 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/04 20:47:08 by wricky-t         ###   ########.fr       */
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

bool hasOneOccurrence(const std::string &str, char ch)
{
    size_t firstOccurrence = str.find_first_of(ch);
    size_t lastOccurrence = str.find_last_of(ch);

    return (firstOccurrence != std::string::npos) && (firstOccurrence == lastOccurrence);
}

// void    isConvertable(const std::string &str, int &res)
// {}

/**
 * FLOW OF SCALAR CONVERTER
 * 1. Check if the string has only one set of value. [DONE] (NOT NECESSARY)
 * 2. Check if the string is convertable by identify the type
 *      - check if it's one of the pseudo literals (+/-inf, +/-inff, nan) [DONE]
 *      - does the string fulfill the specification of each of the data type? (char, int, float, double)
 *          - as long as it fulfill one of the specification of the data type, it means it's convertable.
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

// static bool hasOnlyOneSetValue(char *remainder)
// {
//     while (*remainder != '\0')
//     {
//         if (!isspace(*remainder))
//         {
//             std::cout << "The given string consists of more than one set of value." << std::endl;
//             return false;
//         }
//         remainder++;
//     }
//     return true;
// }

bool isPseudoLiteral(const std::string &str, int *res)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "inf" || str == "inff")
    {
        res[CHAR] = E_IMPOSSIBLE;
        res[INT] = E_IMPOSSIBLE;
    }
    if (str == "nan" || str == "nanf")
    {
        res[FLOAT] = E_NANF;
        res[DOUBLE] = E_NAN;
        return true;
    }
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
    {
        res[FLOAT] = E_PINFF;
        res[DOUBLE] = E_PINF;
        return true;
    }
    else if (str == "-inf" || str == "-inff")
    {
        res[FLOAT] = E_NINFF;
        res[DOUBLE] = E_NINF;
        return true;
    }
    return false;
}

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
    case E_NON_DISPLAYABLE:
        break;
    case E_CONVERTABLE:
        break;
    }
}

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

static void printConverted(int *res)
{
    (void)res;
    for (int i = 0; i < 4; i++)
    {
        printDataType((e_type)i);
        printPseudoLiterals((e_convert_type)res[i]);
        std::cout << std::endl;
    }
}

/**
 * 1.
 */
void ScalarConverter::convert(const std::string &str)
{
    int res[4] = {E_CONVERTABLE, E_CONVERTABLE, E_CONVERTABLE, E_CONVERTABLE};
    // char *remainder;
    // double number = strtod(str.c_str(), &remainder);
    if (isPseudoLiteral(str, res) == true)
    {
        printConverted(res);
        return;
    }

    // std::cout << "ScalarConverter: " << BGREEN << str << RESET << std::endl;
    // printConverted(res);
    // std::cout << number << std::endl;
    // std::cout << static_cast<int>(number) << std::endl;
    // std::cout << static_cast<float>(number) << std::endl;
    // std::cout << std::setprecision(15) << static_cast<double>(number) << std::endl;
    // std::cout << std::numeric_limits<int>::max() << std::endl;
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