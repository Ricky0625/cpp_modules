/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:35:28 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:06:14 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie() {}

// Destructor
Zombie::~Zombie() {
    std::cout << this->name << ": Byyyyeeee bbbyeeeee...\n";
}

// Let the zombie to announce itself
void    Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

// Setter: set zombie's name
// @attention: using *this* keyword here because there's a name conflict 
// with the parameter name and our data member name. By doing so, we're
// telling the compiler that we want to set the data member name to the
// value of the parameter name.
void    Zombie::setName(const std::string& name) {
    this->name = name;
}
