/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:45:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 19:46:24 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap [" << name << "]: Booting up... System online. Hello world!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other ) {
	*this = other;
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap [" << _name << "]: SELF-DESTRUCT SEQUENCE ACTIVATED. Goodbye, cruel world." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

/**
 * @brief Helper function to print message (no hit points)
*/
static void	print_no_hp_msg(e_trap trap, std::string name) {

	switch (trap)
	{
	case CLAPTRAP:
		std::cout << "ClapTrap [" << name << "]: Bro, I'm literally dead. Let me rest." << std::endl;
		break;
	case FRAGTRAP:
		std::cout << "FragTrap [" << name << "]: zzzZZZZzzz..." << std::endl;
		break;
	case SCAVTRAP:
		std::cout << "ScavTrap [" << name << "]: Bro, I don't touch my buttons. Let me have a power nap first." << std::endl;
		break;
	case DIAMONDTRAP:
		std::cout << "DiamondTrap [" << name << "]: " << std::endl;
		break;
	default:
		break;
	}
}

/**
 * @brief Helper function to print message (no energy points)
*/
static void	print_no_ep_msg(e_trap trap, std::string name) {

	switch (trap)
	{
	case CLAPTRAP:
		std::cout << "ClapTrap [" << name << "]: No energy points left! I'm useless now lol." << std::endl;
		break;
	case FRAGTRAP:
		std::cout << "FragTrap [" << name << "]: Uhhh, about that... I actually don't have any energy points left... sorry..." << std::endl;
		break;
	case SCAVTRAP:
		std::cout << "ScavTrap [" << name << "]: Sorry, can't do that right now... need a power nap to recharge my circuits." << std::endl;
		break;
	case DIAMONDTRAP:
		std::cout << "DiamondTrap [" << name << "]: " << std::endl;
		break;
	default:
		break;
	}
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
bool	ClapTrap::canAct(e_trap trap, e_check check) {
	if (_hitPoints == 0 && (check == ALL || check == HP)) {
		print_no_hp_msg(trap, _name);
		return false;
	}
	if (_energyPoints == 0 && (check == ALL || check == EP)) {
		print_no_ep_msg(trap, _name);
		return false;
	}
	return true;
}

/**
 * @brief Just an extra member function that show the status of ClapTrap
*/
void	ClapTrap::showStatus(e_trap trap) {

	std::string	displayName = _name;
	std::string trapBody[16] = {
		" |  | ", " [<>] ", "/|CT|\\", "  ()  ",
		"  ∩∩  ", " [00] ", "/|ST|\\", "  \\/  ",
		"  \\/  ", " [00]/", "/|FT| ", "  00  ",
		"  \\∩  ", " [00]/", "/|DT| ", "  0/  "
	};
	

	if (displayName.length() > 10)
		displayName = displayName.substr(0, 10) += ".";
	std::cout << std::setw(22) << "+-------------+" << "\n"
	          << trapBody[trap * 4 + 0] << " | " << std::setw(11) << displayName << " |" << "\n"
	          << trapBody[trap * 4 + 1] << " | " << "HP: " << std::setw(7) << _hitPoints << " |" << "\n"
	          << trapBody[trap * 4 + 2] << " | " << "EP: " << std::setw(7) << _energyPoints << " |" << "\n"
	          << trapBody[trap * 4 + 3] << " | " << "AD: " << std::setw(7) << _attackDamage << " |" << "\n"
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
	if (canAct(CLAPTRAP, ALL) == false)
		return ;
	--this->_energyPoints;
	std::cout << "ClapTrap [" << _name << "]: Zappp! I just hit [" << target << "] for " << _attackDamage << " points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	
	unsigned int	hitPoints = this->_hitPoints;

	if (canAct(CLAPTRAP, HP) == false)
		return ;
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	_hitPoints = hitPoints;
	std::cout << "ClapTrap [" << _name << "]: I'm hit! I'm hit! Damage report: " << amount << " points. Time to return fire!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (canAct(CLAPTRAP, ALL) == false)
		return ;
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap [" << _name << "]: Wohoo! I feel alive again! Recovered " << amount << " hit points!" << std::endl;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return _energyPoints;
}
