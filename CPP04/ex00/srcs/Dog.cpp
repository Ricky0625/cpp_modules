/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:17 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 13:00:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// default constructor
Dog::Dog()
{
    this->type = "Dog";
    std::cout << "🐶: Dog default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other)
{
    this->type = other.type;
    std::cout << "🐶: Dog copy constructor called" << std::endl;
}

// assignment operator (overload)
Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

// destructor
Dog::~Dog()
{
    std::cout << "🐶: Dog destructor called" << std::endl;
}

// Override method
void Dog::makeSound() const
{
    std::cout << "🐶: Woof woof!" << std::endl;
}
