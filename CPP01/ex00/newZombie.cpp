/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:44:01 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:41:54 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a pointer to a new Zombie object
 * 
 * @details
 * Allocate memory for a new Zombie object using the *new* keyword. This
 * creates a new instance of the Zombie on the heap. The Zombie object
 * will then be set to the name passed in as a parameter.
*/
Zombie  *newZombie(std::string name) {

    Zombie  *newZombie = new Zombie();

    newZombie->setName(name);
    return (newZombie);    
}
