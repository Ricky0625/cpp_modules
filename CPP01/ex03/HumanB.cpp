/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:51:39 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 15:22:52 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// constructor. Initially set weapon to NULL
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

// destructor
HumanB::~HumanB(void) {}

/**
 * @brief setter to set weapon for HumanB
 * newWeapon is a reference to the weapon.
 * Hence, we need to use &newWeapon to get the address of the weapon.
*/
void    HumanB::setWeapon(Weapon &newWeapon) {
    _weapon = &newWeapon;
}

/**
 * @brief attack function
 * If weapon is NULL, then attack with bare hands.
 * Else, attack with the weapon.
*/
void    HumanB::attack(void) {
    if (_weapon == NULL)
        std::cout << _name << " attacks with bare hands\n";
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}
