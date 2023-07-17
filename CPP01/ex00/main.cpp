/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:41:31 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:42:15 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief
 * Demonstrate the behavior of allocating an object on the stack vs on the heap
 * 
 * @details
 * The `zombie` and the zombie created by `randomChump` are created on the stack.
 * `zombie` will be cleaned up when the function (main) scope ends. The zombie
 * created by `randomChump` will be cleaned up when the function (randomChump)
 * scope ends. For `newborn`, it's allocated on the heap, so it will not be
 * cleaned up until we call `delete` on it.
*/
int main()
{
    Zombie  zombie;
    Zombie  *newborn = newZombie("Abu");

    zombie.setName("Ali");
    zombie.announce();
    newborn->announce();
    randomChump("Aki");
    delete newborn;
}
