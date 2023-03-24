/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:36:14 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 14:14:48 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// that weird looking syntax is called "initializer list"
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
    this->name = name;
}

HumanA::~HumanA(void) {}

void    HumanA::attack(void) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}