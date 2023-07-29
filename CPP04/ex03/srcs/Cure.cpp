/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:45:30 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:58:50 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// default constructor
Cure::Cure() : AMateria("cure")
{
    // std::cout << "💊 Cure spawned!" << std::endl;
}

// copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
    // std::cout << "💊 Cure copied!" << std::endl;
}

// assignment operator (overload)
Cure    &Cure::operator=(const Cure &other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

// destructor
Cure::~Cure()
{
    // std::cout << "💊 Cure expired!" << std::endl;
}

// override
AMateria *Cure::clone(void) const
{
    return new Cure(*this);
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
