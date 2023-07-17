/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:43:55 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:44:23 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a zombie horde
 * 
 * @details
 * 1. Create a zombie horde
 * 2. Set the name of each zombie
 * 3. Return the zombie horde
 * 
 * @attention
 * new[] - this is to allocate an array of objects on heap
 */
Zombie  *zombieHorde(int N, std::string name) {
    
    int     i = -1;
    Zombie  *zombieHorde = new Zombie[N];

    while (++i < N)
        zombieHorde[i].setName(name);
    return zombieHorde;
}
