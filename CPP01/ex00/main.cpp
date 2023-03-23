/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:41:31 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/22 21:18:05 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  zombie("Ali");
    Zombie  *newborn = zombie.newZombie("Abu");

    zombie.announce();
    newborn->announce();
    zombie.randomChump("Aki");
    delete newborn;
}
