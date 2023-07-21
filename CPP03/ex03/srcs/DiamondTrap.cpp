/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:17:35 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/21 21:03:15 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap() {}

// parameter constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name)
{
    _hitPoints = FragTrap::_maxHitPoints;
    _energyPoints = ScavTrap::_maxEnergyPoints;
    _attackDamage = FragTrap::_maxAttackDamage;
    std::cout << "DiamondTrap [" << _name << "]: Behold, for I am Diamond, the shiniest and most magnificent creation! 💎✨" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : _name(other._name)
{
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

// assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap [" << _name << "]: Farewell, mere mortals! Remember, I shall always shine brighter than the stars in the sky! Until we meet again!" << std::endl;
}

// member function
void    DiamondTrap::whoAmI()
{
    if (canAct(DIAMONDTRAP, ALL) == false)
        return ;
    --_energyPoints;
    std::cout << "DiamondTrap [" << ClapTrap::_name << "]: Behold, I, " << ClapTrap::_name << " the dazzling Diamond! LOOK AT ME! 💎 #AttentionGrabber" << std::endl;
    std::cout << "DiamondTrap [" << _name << "]: Behold, I, " << _name << " the dazzling Diamond! LOOK AT ME! 💎 #AttentionGrabber" << std::endl;
}

std::string   DiamondTrap::getName() const
{
    return _name;
}