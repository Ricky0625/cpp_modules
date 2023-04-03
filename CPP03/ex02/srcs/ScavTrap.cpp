/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:33 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 14:57:53 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void) : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap [" << getName() << "]: Just woke up from a power nap. Let's make some noise!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	*this = other;
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap [" << getName() << "]: Initiating power nap. I'll be back, don't touch my buttons while I'm gone." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

/**
 * @brief To check if ClapTrap can perform any action based on the hitPoints and energyPoints
 * @details
 * 1. Check if ClapTrap is still alive
 * 2. Check if ClapTrap has energyPoints left to do an action
 * 
 * If one of the checking failed, it will return false to indicate that ClapTrap can't do anything.
 * Else return true.
*/
static bool	canAct(std::string name, unsigned int hitPoints, unsigned int energyPoints, e_check check) {
	if (hitPoints == 0 && (check == ALL || check == HP)) {
		std::cout << "ScavTrap [" << name << "]: Bro, I don't touch my buttons. Let me have a power nap first." << std::endl;
		return false;
	}
	if (energyPoints == 0 && (check == ALL || check == EP)) {
		std::cout << "ScavTrap [" << name << "]: Sorry, can't do that right now... need a power nap to recharge my circuits." << std::endl;
		return false;
	}
	return true;
}

void	ScavTrap::attack(const std::string& target) {
	if (canAct(getName(), getHitPoints(), getEnergyPoints(), ALL) == false)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap [" << getName() << "]: Eat laser, [" << target << "]! That's " << getAttackDamage() << " points of damage for you!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (canAct(getName(), getHitPoints(), getEnergyPoints(), ALL) == false)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "ScavTrap [" << getName() << "]: GATE KEEPER MODE ACTIVATED! Thou shall not pass!" << std::endl;
}

/**
 * @brief Just an extra member function that show the status of ClapTrap
*/
void	ScavTrap::showStatus(void) {

	std::string	displayName = getName();
	int			nameLength = displayName.length();

	if (nameLength > 10)
		displayName = displayName.substr(0, 10) += ".";
	std::cout << "      " << std::setw(16) << "+-------------+" << "\n"
	          << "  ∩∩  " << " | " << std::setw(11) << displayName << " |" << "\n"
	          << " [00] " << " | " << "HP: " << std::setw(7) << getHitPoints() << " |" << "\n"
	          << "/|ST|\\" << " | " << "EP: " << std::setw(7) << getEnergyPoints() << " |" << "\n"
	          << "  \\/  " << " | " << "AD: " << std::setw(7) << getAttackDamage() << " |" << "\n"
			  << std::setw(22) << "+-------------+" << std::endl;
}
