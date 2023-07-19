/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:46:46 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 14:10:45 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

/**
 * @brief Default constructor
 * @details _fixed is set to 0 initially
 */
Fixed::Fixed(void) : _fixed(0) {}

/**
 * @overload
 * @brief Constructor, initialize value based on int data type
 * @details _fixed is set to the given int value after convert to fixed point number
 */
Fixed::Fixed(const int val) : _fixed(std::roundf(val << _fractBits)) {}

/**
 * @overload
 * @brief Constructor, initialize value based on float data type
 * @details _fixed is set to the given float value after convert to fixed point number
 */
Fixed::Fixed(const float val) : _fixed(std::roundf(val * (1 << _fractBits))) {}

/**
 * @brief Copy constructor
 */
Fixed::Fixed(const Fixed &fixed) : _fixed(fixed._fixed) {}

/**
 * @brief Destructor
 */
Fixed::~Fixed(void) {}

/**
 * @overload
 * @brief Assignment operator overload
 * @attention Will prevent self-assignment by comparing the addreses
 *            of the object being assigned
 */
Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        _fixed = fixed.getRawBits();
    return *this;
}

/**
 * @brief Getter for _fixed
 */
int Fixed::getRawBits(void) const
{
    return _fixed;
}

/**
 * @brief Setter for _fixed
 */
void Fixed::setRawBits(int const raw)
{
    _fixed = raw;
}

/**
 * @brief Convert Fixed point number to Floating point number
 * @details
 * The reason for two typecast is that we want to ensure that the result of
 * the division is a floating point number. If we didn't perform these typecasts,
 * the division operation would be performed using integer division, which would
 * truncate any fractional part and produce an incorrect result.
 * 
 * @formula
 * float value = fixed value / scaling factor
 * scaling factor is used to scale the fixed point number to the desired decimal places
 * scaling factor is typically 2 to the power of the number of fractional bits in the fixed point number
 * 
 * 2 ^ (fractional bits) == 1 << (fractional bits)
 */
float Fixed::toFloat(void) const
{
    return ((float)_fixed / (float)(1 << _fractBits));
}

/**
 * @brief Convert Fixed point number to Int
 * 
 * @formula
 * int value = fixed value >> fractional bits
 * Using right shift operator to perform the division by 2 ^ fractional bits,
 * to effectively remove the fractional bits from the fixed point number.
 */
int Fixed::toInt(void) const
{
    return (_fixed >> _fractBits);
}

/**
 * @overload
 * @brief Greater than operator overload
 * @attention
 * Convert the fixed point number to float first, then compare.
 * This is to ensure that the comparison is done between two floating point numbers,
 * because this can take advantage of the floating-point representation's dynamic
 * precision, which leads to more accurate results when comparing fixed-point numbers.
 */
bool Fixed::operator>(const Fixed &other) const
{
    return toFloat() > other.toFloat();
}

/**
 * @overload
 * @brief Less than operator overload
 */
bool Fixed::operator<(const Fixed &other) const
{
    return toFloat() < other.toFloat();
}

/**
 * @overload
 * @brief Greater and equal than operator overload
 */
bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

/**
 * @overload
 * @brief Less and equal than operator overload
 */
bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

/**
 * @overload
 * @brief Equal operator overload
 */
bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

/**
 * @overload
 * @brief Not equal operator overload
 */
bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

/**
 * @overload
 * @brief Addition operator overload
 * @return a new instance of Fixed
*/
Fixed Fixed::operator+(const Fixed &other) const
{
    float newFixed = this->toFloat() + other.toFloat();
    return Fixed(newFixed);
}

/**
 * @overload
 * @brief Subtraction operator overload
 * @return a new instance of Fixed
*/
Fixed Fixed::operator-(const Fixed &other) const
{
    float newFixed = this->toFloat() - other.toFloat();
    return Fixed(newFixed);
}

/**
 * @overload
 * @brief Multiplication operator overload
 * @return a new instance of Fixed
*/
Fixed Fixed::operator*(const Fixed &other) const
{
    float newFixed = this->toFloat() * other.toFloat();
    return Fixed(newFixed);
}

/**
 * @overload
 * @brief Division operator overload
 * @return a new instance of Fixed
*/
Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._fixed == 0) {
        std::cout << "(undefined) ";
        return Fixed(0);
    }

    float newFixed = this->toFloat() / other.toFloat();
    return Fixed(newFixed);
}

/**
 * @brief Pre-increment
 * @details Increment value and return the object itself
 */
Fixed& Fixed::operator++(void)
{
    this->_fixed++;
    return *this;
}

/**
 * @brief Post-increment
 * @details Create a temporary object, increment the value is the ori object,
 *          return the old object. Return const Fixed is just to amplify that
 *          the ori object remain unchanged.
 * @attention the `int` parameter in the function prototype is useless,
 *            it's just use to differentiate between pre- and post-.
 */
Fixed Fixed::operator++(int)
{
    Fixed copy(*this);

    this->_fixed++;
    return copy;
}

/**
 * @brief Pre-decrement
 * @details Decrement value and return the object itself
 */
Fixed& Fixed::operator--(void)
{
    this->_fixed--;
    return *this;
}

/**
 * @brief Post-decrement
 * @details Create a temporary object, decrement the value is the ori object,
 *          return the old object. Return const Fixed is just to amplify that
 *          the ori object remain unchanged.
 * @attention the `int` parameter in the function prototype is useless,
 *            it's just use to differentiate between pre- and post-.
 */
Fixed Fixed::operator--(int)
{
    Fixed copy(*this);

    this->_fixed--;
    return copy;
}

/**
 * @overload
 * @param a the first fixed point number
 * @param b the second fixed point number
 * @brief Get the smallest one between two fixed point number
 */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a.toFloat() <= b.toFloat()) ? a : b;
}

/**
 * @overload
 * @param a the first const fixed point number
 * @param b the second const fixed point number
 * @brief Get the smallest one between two fixed point number
 */
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() <= b.toFloat()) ? a : b;
}

/**
 * @overload
 * @param a the first fixed point number
 * @param b the second fixed point number
 * @brief Get the largest one between two fixed point number
 */
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a.toFloat() >= b.toFloat()) ? a : b;
}

/**
 * @overload
 * @param a the first const fixed point number
 * @param b the second const fixed point number
 * @brief Get the largest one between two fixed point number
 */
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a.toFloat() >= b.toFloat()) ? a : b;
}

/**
 * @brief Override operator (<<)
 * @param os the output stream that we are writing to
 * @param fixed the reference to fixed object
 * @details
 * std::ostream is a C++ standard library class that represents an output stream,
 * which can be used to write data to an output device or file. One of the example
 * of output stream are std::cout, which represents the standard output stream for
 * console output.
 *
 * The reason this overloadded function return `os` at the end is to allow chaining
 * of multiple `<<` operators.
 *
 * @return os
 */
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
