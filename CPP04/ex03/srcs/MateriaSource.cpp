/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:42:20 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:59:11 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// default constructor
MateriaSource::MateriaSource() : _slots(0)
{
    for (int i = 0; i < MAX_SLOTS; i++)
        _shelf[i] = NULL;
    // std::cout << "📚 MateriaSource spawned!" << std::endl;
}

// copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) : _slots(other._slots)
{
    for (int i = 0; i < MAX_SLOTS; i++)
        _shelf[i] = NULL;
    for (int i = 0; i < MAX_SLOTS; i++)
        _shelf[i] = other._shelf[i];
    // std::cout << "📚 MateriaSource copy constructor called!" << std::endl;
}

// assignment operator (overload)
MateriaSource    &MateriaSource::operator=(const MateriaSource &other)
{
    if (this == &other)
        return *this;

    _slots = other._slots;
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        delete _shelf[i];
        _shelf[i] = NULL;
    }
    
    for (int i = 0; i < MAX_SLOTS; i++)
        _shelf[i] = other._shelf[i];
    
    // std::cout << "📚 MateriaSource assignment operator called!" << std::endl;
    return *this;
}

// destructor
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MAX_SLOTS; i++)
        delete _shelf[i];
    // std::cout << "📚 MateriaSource destroyed!" << std::endl;
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (_slots < MAX_SLOTS)
    {
        AMateria *clone = m->clone();
        _shelf[_slots] = clone;
        _slots++;
    }
    // else
        // std::cout << "📚 MateriaSource is full!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < MAX_SLOTS; i++)
    {
        if (_shelf[i] && _shelf[i]->getType() == type)
            return _shelf[i]->clone();
    }
    // std::cout << "📚 MateriaSource doesn't have this materia!" << std::endl;
    return NULL;
}