/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:37:47 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 15:27:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/**
 * References vs Pointers
 * 
 * 1. Use a reference when an object is guaranteed to exist throughout the lifetime
 *    of the referring object. In this case, HumanA's weapon is guarantee to exist
 *    so can use reference to initialize weapon for HumanA.
 * 2. Use a pointer when an object may or may not exist throughout the lifetime of
 *    the referring object. In this case, HumanB's weapon is not guaranteed to exist.
 *    So it should be able to set to NULL. Hence, pointer is a better option here.
*/

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    {
        Weapon club = Weapon("banana");
        HumanB monke("Monke");
        monke.setWeapon(club);
        monke.attack();
        club.setType("rocks");
        monke.attack();
    }
    return 0;
}
