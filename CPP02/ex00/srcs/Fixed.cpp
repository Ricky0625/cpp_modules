/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:46:46 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/27 18:30:10 by wricky-t         ###   ########.fr       */
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
 * @details intialize data members using initialization list
*/
Fixed::Fixed(const Fixed& other) : _fixed(other._fixed) {
    std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator overload
 * @attention Will prevent self-assignment by comparing the addreses
 *            of the object being assigned
 * @attention this keyword holds the memory address of the current instance of a class
*/
Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    
    this->_fixed = other._fixed; 
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
    return _fixed;
}

/**
 * @brief Setter for _fixed
*/
void    Fixed::setRawBits(int const raw) { 
    _fixed = raw;
}
