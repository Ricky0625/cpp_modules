/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:09:24 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:41:45 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a Zombie object on the stack
 * 
 * @details
 * When this function is called, a new Zombie object will be created on the
 * stack. The Zombie object will then be set to the name passed in as a
 * parameter. This zombie object is automatically destroyed when the function
 * scope ends. Don't have to call `delete` on it!
*/
void    randomChump(std::string name) {
    Zombie  zombie;

    zombie.setName(name);
    zombie.announce();
}
