/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:33 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:10:47 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(void) : ClapTrap() {}

/**
 * @brief Parameter constructor
 * @attention
 * Was trying to use initializer list to initialize the hp, ep and ad but
 * does not work. The reason behind this is because you can't "reinitialize"
 * the attribute of the parent class. So, if the attribute value is different,
 * you have to initialize it in the body of the constructor by modifying them
 * if the derived class has the access to the parent class' attribute.
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap [" << _name << "]: Just woke up from a power nap. Let's make some noise!" << std::endl;
}

/**
 * @brief Copy constructor
 * @details Calling ClapTrap's copy constructor
*/
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap [" << _name << "]: Initiating power nap. I'll be back, don't touch my buttons while I'm gone." << std::endl;
}

/**
 * @brief Assignation operator overload
*/
ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

/**
 * @overriden
 * @brief Attack function
 * @details Same as ClapTrap's attack function but with different message
*/
void	ScavTrap::attack(const std::string& target) {
	if (canAct(SCAVTRAP, ALL) == false)
		return ;
	--_energyPoints;
	std::cout << "ScavTrap [" << _name << "]: Eat laser, [" << target << "]! That's " << _attackDamage << " points of damage for you!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (canAct(SCAVTRAP, ALL) == false)
		return ;
	--_energyPoints;
	std::cout << "ScavTrap [" << _name << "]: GATE KEEPER MODE ACTIVATED! Thou shall not pass!" << std::endl;
}
