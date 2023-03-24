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

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = nullptr;
}

HumanB::~HumanB(void) {}

void    HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
}

void    HumanB::attack(void) {
    if (this->weapon == nullptr)
        std::cout << this->name << " attacks with bare hands\n";
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}
