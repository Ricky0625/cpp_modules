/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:16:38 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 14:28:37 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// default constructor
WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "🦁: WrongCat default constructor called" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
    this->type = other.type;
    std::cout << "🦁: WrongCat copy constructor called" << std::endl;
}

// assignment operator (overload)
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

// destructor
WrongCat::~WrongCat()
{
    std::cout << "🦁: WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "🦁: Roar! Meow?" << std::endl;
}
