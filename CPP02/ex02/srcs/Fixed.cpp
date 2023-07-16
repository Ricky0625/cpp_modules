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

const int   Fixed::_fractBits = 8;

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
Fixed::Fixed(const Fixed& fixed) : _fixed(fixed._fixed) {}

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
Fixed &Fixed::operator=(const Fixed& fixed) {
    if (this != &fixed)
        this->_fixed = fixed.getRawBits(); 
    return *this;
}

/**
 * @brief Getter for _fixed
*/
int Fixed::getRawBits(void) const {
    return this->_fixed;
}

/**
 * @brief Setter for _fixed
*/
void    Fixed::setRawBits(int const raw) { 
    this->_fixed = raw;
}

/**
 * @brief Convert Fixed point number to Floating point number
 * @details
 * The reason for two typecast is that we want to ensure that the result of
 * the division is a floating point number. If we didn't perform these typecasts,
 * the division operation would be performed using integer division, which would
 * truncate any fractional part and produce an incorrect result.
*/
float   Fixed::toFloat(void) const {
    return ((float)this->_fixed / (float)(1 << this->_fractBits));
}

/**
 * @brief Convert Fixed point number to Int
*/
int Fixed::toInt(void) const {
    return (this->_fixed >> this->_fractBits);
}

/**
 * @overload
 * @brief Greater than operator overload
*/
bool    Fixed::operator>(const Fixed& rightOperand) const {
    return this->toFloat() > rightOperand.toFloat();
}

/**
 * @overload
 * @brief Less than operator overload
*/
bool    Fixed::operator<(const Fixed& rightOperand) const {
    return this->toFloat() < rightOperand.toFloat();
}

/**
 * @overload
 * @brief Greater and equal than operator overload
*/
bool    Fixed::operator>=(const Fixed& rightOperand) const {
    return this->toFloat() >= rightOperand.toFloat();
}

/**
 * @overload
 * @brief Less and equal than operator overload
*/
bool    Fixed::operator<=(const Fixed& rightOperand) const {
    return this->toFloat() <= rightOperand.toFloat();
}

/**
 * @overload
 * @brief Equal operator overload
*/
bool    Fixed::operator==(const Fixed& rightOperand) const {
    return this->toFloat() == rightOperand.toFloat();
}

/**
 * @overload
 * @brief Not equal operator overload
*/
bool    Fixed::operator!=(const Fixed& rightOperand) const {
    return this->toFloat() != rightOperand.toFloat();
}

Fixed   Fixed::operator+(const Fixed& rightOperand) {
    return this->toFloat() + rightOperand.toFloat();
}

Fixed   Fixed::operator-(const Fixed& rightOperand) {
    return this->toFloat() - rightOperand.toFloat();
}

Fixed   Fixed::operator*(const Fixed& rightOperand) {
    return this->toFloat() * rightOperand.toFloat();
}

Fixed   Fixed::operator/(const Fixed& rightOperand) {
    if (this->toFloat() == 0.0f && rightOperand.toFloat() > 0.0f)
    {
        std::cout << "(undefined) ";
        return 0;
    }
    else if (rightOperand.toFloat() == 0.0f)
        return 0;
    return this->toFloat() / rightOperand.toFloat();
}

/**
 * @brief Pre-increment
 * @details Increment value and return the object itself
*/
Fixed   Fixed::operator++(void) {
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
const Fixed Fixed::operator++(int) {
    const Fixed tmp(*this);

    this->_fixed++;
    return tmp;
}

/**
 * @brief Pre-decrement
 * @details Decrement value and return the object itself
*/
Fixed   Fixed::operator--(void) {
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
const Fixed Fixed::operator--(int) {
    const Fixed tmp(*this);

    this->_fixed--;
    return tmp;
}

/**
 * @brief Get the smallest one between two fixed point number 
*/
Fixed   &Fixed::min(Fixed &a, Fixed &b) {
    return (a.toFloat() <= b.toFloat()) ? a : b;
}

/**
 * @brief Get the smallest one between two fixed point number 
*/
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a.toFloat() <= b.toFloat()) ? a : b;
}

/**
 * @brief Get the largest one between two fixed point number 
*/
Fixed   &Fixed::max(Fixed &a, Fixed &b) {
    return (a.toFloat() >= b.toFloat()) ? a : b;
}

/**
 * @brief Get the largest one between two fixed point number 
*/
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
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
std::ostream    &operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}