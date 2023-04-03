/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:33 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 15:42:07 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(void) : ClapTrap() {}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap [" << getName() << "]: Uh, hey, so, umm, hi. I mean, hello. Uh, how do I say this? Hello hello!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap [" << getName() << "]: Ummm, is it ok if I take a power nap? I won't be gone long, I prooomise... zzzZZZZ" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
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
		std::cout << "FragTrap [" << name << "]: zzzZZZZzzz..." << std::endl;
		return false;
	}
	if (energyPoints == 0 && (check == ALL || check == EP)) {
		std::cout << "ScavTrap [" << name << "]: Uhhh, about that... I actually don't have any energy points left... sorry..." << std::endl;
		return false;
	}
	return true;
}

void	FragTrap::highFivesGuys(void) {
	if (canAct(getName(), getHitPoints(), getEnergyPoints(), ALL) == false)
		return ;
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap [" << getName() << "]: Hey, uh, do you want to, like, do a thing with our hands? You know, like a high five? ✋🥺" << std::endl;
}

/**
 * @brief Just an extra member function that show the status of ClapTrap
*/
void	FragTrap::showStatus(void) {

	std::string	displayName = getName();
	int			nameLength = displayName.length();

	if (nameLength > 10)
		displayName = displayName.substr(0, 10) += ".";
	std::cout << "      " << std::setw(16) << "+-------------+" << "\n"
	          << "  \\/  " << " | " << std::setw(11) << displayName << " |" << "\n"
	          << " [00]/" << " | " << "HP: " << std::setw(7) << getHitPoints() << " |" << "\n"
	          << "/|FT| " << " | " << "EP: " << std::setw(7) << getEnergyPoints() << " |" << "\n"
	          << "  00  " << " | " << "AD: " << std::setw(7) << getAttackDamage() << " |" << "\n"
			  << std::setw(22) << "+-------------+" << std::endl;
}
