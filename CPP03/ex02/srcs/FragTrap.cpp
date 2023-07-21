/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:58:33 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:29:19 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap(void) : ClapTrap() {}

// parameter constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap [" << _name << "]: Uh, hey, so, umm, hi. I mean, hello. Uh, how do I say this? Hello hello!" << std::endl;
}

// copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

// destructor
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap [" << _name << "]: Ummm, is it ok if I take a power nap? I won't be gone long, I prooomise... zzzZZZZ" << std::endl;
}

// assignation operator overload
FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// FragTrap action
void	FragTrap::highFivesGuys(void) {
	if (canAct(FRAGTRAP, ALL) == false)
		return ;
	--_energyPoints;
	std::cout << "FragTrap [" << _name << "]: Hey, uh, do you want to, like, do a thing with our hands? You know, like a high five? ✋🥺" << std::endl;
}
