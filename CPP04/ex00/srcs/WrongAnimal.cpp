/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:16:50 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 14:25:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// default constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "🤨: WrongAnimal default constructor called" << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "🤨: WrongAnimal copy constructor called" << std::endl;
}

// assignment operator (overload)
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

// destructor
WrongAnimal::~WrongAnimal()
{
    std::cout << "🤨: WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "🤨: Konnichiwa? Bonjour?" << std::endl;
}

// getters: get type
std::string WrongAnimal::getType(void) const
{
    return this->type;
}
