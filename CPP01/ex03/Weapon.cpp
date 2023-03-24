/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:03:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 21:39:26 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) {
    this->setType(type);
}

Weapon::~Weapon() {}

const std::string& Weapon::getType(void) {
    return (this->type);
}

void    Weapon::setType(std::string type) {
    this->type = type;
}
