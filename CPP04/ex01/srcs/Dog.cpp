/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:17 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 14:36:39 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// default constructor
Dog::Dog() : brain(NULL)
{
    this->type = "Dog";
    brain = new Brain();
    std::cout << "🐶: Dog default constructor called" << std::endl;
}

// copy constructor
Dog::Dog(const Dog &other)
{
    this->type = other.type;
    brain = new Brain(*other.brain);
    std::cout << "🐶: Dog copy constructor called" << std::endl;
}

// assignment operator (overload)
Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
        if (brain == NULL)
            brain = new Brain();
        *brain = *other.brain; // should be using brain's copy assignment operator
    }
    return *this;
}

// destructor
Dog::~Dog()
{
    delete brain;
    std::cout << "🐶: Dog destructor called" << std::endl;
}

// Override method
void Dog::makeSound() const
{
    std::cout << "🐶: Woof woof!" << std::endl;
}

void    Dog::setIdea(int index, const std::string& idea)
{
    this->brain->setIdea(index, idea);
}

std::string &Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}
