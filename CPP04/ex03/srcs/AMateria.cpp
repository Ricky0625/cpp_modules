/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:50:28 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:58:10 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Parameter constructor
AMateria::AMateria(std::string const &type) : _type(type)
{
    // std::cout << "🧱 AMateria created! " << BBLUE << "[TYPE]: " << type << RESET << std::endl;
}

// copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type)
{
    // std::cout << "🧱 AMateria copied!" << std::endl;
}

// assignment operator (overload)
AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->_type = other._type;
    // std::cout << "🧱 AMateria assignment operator called!" << std::endl;
    return *this;
}

// destructor
AMateria::~AMateria()
{
    // std::cout << "🧱 AMateria destructed!" << std::endl;
}

// getter - type
std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "Unknown Materia was used on " << target.getName() << " but the effect is unknown." << std::endl;
}
