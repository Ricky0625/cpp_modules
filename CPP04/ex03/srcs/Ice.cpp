/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:53:29 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:58:55 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// default constructor
Ice::Ice() : AMateria("ice")
{
    // std::cout << "🧊 Ice spawned!" << std::endl;
}

// copy constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
    // std::cout << "🧊 Ice copied!" << std::endl;
}

// assignment operator (overload)
Ice &Ice::operator=(const Ice &other)
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

// destructor
Ice::~Ice()
{
    // std::cout << "🧊 Ice melted!" << std::endl;
}

// override AMateria::clone
AMateria *Ice::clone(void) const
{
    return new Ice(*this);
}

// override AMateria::use
void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
