/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:46:46 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 22:12:32 by wricky-t         ###   ########.fr       */
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed;
}

/**
 * @brief Setter for _fixed
*/
void    Fixed::setRawBits(int const raw) { 
    this->_fixed = raw;
}
