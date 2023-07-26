/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 15:05:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat() : brain(NULL)
{
    this->type = "Cat";
    brain = new Brain();
    std::cout << "🐱: Cat default constructor called" << std::endl;
}

// copy constructor
Cat::Cat(const Cat &other)
{
    this->type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "🐱: Cat copy constructor called" << std::endl;
}

// assignment operator (overload)
Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
        *brain = *other.brain; // should be using brain's copy assignment operator
    }
    std::cout << "🐱: Cat assignment operator called" << std::endl;
    return *this;
}

// destructor
Cat::~Cat()
{
    delete brain;
    std::cout << "🐱: Cat destructor called" << std::endl;
}

// Override method
void Cat::makeSound() const
{
    std::cout << "🐱: Meow meow!" << std::endl;
}

void    Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string &Cat::getIdea(int index) const
{
    return brain->getIdea(index);
}
