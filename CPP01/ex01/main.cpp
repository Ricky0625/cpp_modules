/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:41:31 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 15:05:30 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Parse input
 * 
*/
static void parse_input(int ac, char **av) {

    const char *numStr;

    if (ac != 3) {
        std::cout << "./moar_brainz <Number of zombie> <Zombie name>\n";
        exit(EXIT_FAILURE);
    }
    numStr = av[1];
    for (int i = 0; i < (int)strlen(numStr); i++) {
        if (isdigit(numStr[i]) == false) {
            std::cout << "Invalid argument for <Number of zombie>!\n";
            exit(EXIT_FAILURE);
        }
    }
}

/**
 * @brief Create a zombie horde
 * 
 * @details
 * 1. Parse the inputs
 * 2. Create a zombie horde
 * 3. Announce each zombie
 * 4. Delete the zombie horde
*/
int main(int ac, char **av)
{
    int         i = -1;
    Zombie      *horde;

    parse_input(ac, av);
    horde = zombieHorde(atoi(av[1]), av[2]);
    while (++i < atoi(av[1]))
    {
        std::cout << "Number " << i + 1 << ": ";
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
