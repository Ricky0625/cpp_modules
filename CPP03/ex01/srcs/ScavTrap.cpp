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


ScavTrap::ScavTrap(void) : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap [" << _name << "]: Just woke up from a power nap. Let's make some noise!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap [" << _name << "]: Initiating power nap. I'll be back, don't touch my buttons while I'm gone." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

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
