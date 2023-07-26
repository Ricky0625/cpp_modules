/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:21:34 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 14:33:54 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// default constructor
Animal::Animal() : type("Animal")
{
    std::cout << "🐾: Animal default constructor called" << std::endl;
}

// copy constructor
Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "🐾: Animal copy constructor called" << std::endl;
}

// assignment operator (overload)
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "🐾: Animal assignment operator called" << std::endl;
    return *this;
}

// destructor
Animal::~Animal()
{
    std::cout << "🐾: Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "🐾: Unknown sound!" << std::endl;
}

// getters: get type
const std::string &Animal::getType(void) const
{
    return this->type;
}
