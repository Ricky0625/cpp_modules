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