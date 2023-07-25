/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 11:06:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat()
{
    this->type = "Cat";
    std::cout << "🐱: Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat &other)
{
    this->type = other.type;
    std::cout << "🐱: Cat copy constructor called" << std::endl;
}

// assignment operator (overload)
Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

// destructor
Cat::~Cat()
{
    std::cout << "🐱: Cat destructor called" << std::endl;
}

// Override method
void Cat::makeSound() const
{
    std::cout << "🐱: Meow meow!" << std::endl;
}
