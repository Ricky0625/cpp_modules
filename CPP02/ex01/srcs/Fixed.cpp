/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:46:46 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/27 18:41:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::_fractBits = 8;

/**
 * @brief Default constructor
*/
Fixed::Fixed(void) : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(val << this->_fractBits);
}

Fixed::Fixed(const float val) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits(std::roundf(val * (1 << this->_fractBits)));
}

/**
 * @brief Copy constructor
 * @details Implement using assignment operator
*/
Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

/**
 * @brief Assignment operator overload
 * @attention Will prevent self-assignment by comparing the addreses
 *            of the object being assigned
*/
Fixed &Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_fixed = fixed.getRawBits(); 
    return *this;
}

/**
 * @brief Destructor
*/
Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
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
    return ((float)this->getRawBits() / (float)(1 << this->_fractBits));
}

/**
 * @brief Convert Fixed point number to Int
 * @details
 * 
*/
int Fixed::toInt(void) const {
    return (getRawBits() >> this->_fractBits);
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
