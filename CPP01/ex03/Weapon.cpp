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

// default constructor
Weapon::Weapon() {}

// overload constructor
Weapon::Weapon(const std::string& type) : _type(type) {}

// destructor
Weapon::~Weapon() {}

// getter
const std::string& Weapon::getType(void) const {
    return (_type);
}

// setter
void    Weapon::setType(const std::string& newType) {
    _type = newType;
}
