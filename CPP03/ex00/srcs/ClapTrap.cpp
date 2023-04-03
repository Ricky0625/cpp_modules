/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:45:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 14:38:51 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

enum	e_check {
	HP,
	EP,
	ALL	
};

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap [" << name << "]: Booting up... System online. Hello world!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other ) {
	*this = other;
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap [" << this->_name << "]: SELF-DESTRUCT SEQUENCE ACTIVATED. Goodbye, cruel world." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
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
		std::cout << "ClapTrap [" << name << "]: Bro, I'm literally dead. Let me rest." << std::endl;
		return false;
	}
	if (energyPoints == 0 && (check == ALL || check == EP)) {
		std::cout << "ClapTrap [" << name << "]: No energy points left! I'm useless now lol." << std::endl;
		return false;
	}
	return true;
}

/**
 * @brief Just an extra member function that show the status of ClapTrap
*/
void	ClapTrap::showStatus(void) {

	std::string	displayName = this->_name;
	int			nameLength = this->_name.length();

	if (nameLength > 10)
		displayName = this->_name.substr(0, 10) += ".";
	std::cout << std::setw(22) << "+-------------+" << "\n"
	          << " [<>] " << " | " << std::setw(11) << displayName << " |" << "\n"
	          << "/|CT|\\" << " | " << "HP: " << std::setw(7) << this->_hitPoints << " |" << "\n"
	          << " |  | " << " | " << "EP: " << std::setw(7) << this->_energyPoints << " |" << "\n"
	          << "  ()  " << " | " << "AD: " << std::setw(7) << this->_attackDamage << " |" << "\n"
			  << std::setw(22) << "+-------------+" << std::endl;
}

/**
 * @brief ClapTrap's attack action
 * @details
 * 1. Check if ClapTrap can perform any action
 * 2. Spend one enery point
 * 3. ClapTrap declare itself that it attacks someone
*/
void	ClapTrap::attack(const std::string& target) {
	if (canAct(this->_name, this->_hitPoints, this->_energyPoints, ALL) == false)
		return ;
	this->setEnergyPoints(--this->_energyPoints);
	std::cout << "ClapTrap [" << getName() << "]: Zappp! I just hit [" << target << "] for " << getAttackDamage() << " points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	unsigned int	hitPoints = this->getHitPoints();

	if (canAct(this->_name, hitPoints, this->_energyPoints, HP) == false)
		return ;
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	this->setHitPoints(hitPoints);
	std::cout << "ClapTrap [" << getName() << "]: I'm hit! I'm hit! Damage report: " << amount << " points. Time to return fire!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	
	unsigned int	energyPoints = this->getEnergyPoints();

	if (canAct(this->_name, this->_hitPoints, this->_energyPoints, ALL) == false)
		return ;
	this->setEnergyPoints(--energyPoints);
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << "ClapTrap [" << getName() << "]: Wohoo! I feel alive again! Recovered " << amount << " hit points!" << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->_energyPoints = energyPoints;
}
