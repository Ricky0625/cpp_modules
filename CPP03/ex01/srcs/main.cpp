/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:14:45 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	print_test_title(std::string title) {
	std::cout << BCYAN << "\n[TEST]:" << title << DEF << std::endl;
}

int main(void) {

	{
		print_test_title("BRUCE says hello");
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus(SCAVTRAP);
	}
	{
		print_test_title("BRUCE runs out of energy points and wants to take a power nap");
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus(SCAVTRAP);
		while (bruce.getEnergyPoints())
			bruce.attack("JOKER");
		bruce.showStatus(SCAVTRAP);
		bruce.attack("JOKER");
		bruce.guardGate();
	}
	{
		print_test_title("BRUCE guards the gate for 50 rounds and wants to take a power nap");
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus(SCAVTRAP);
		while (bruce.getEnergyPoints())
			bruce.guardGate();
		bruce.showStatus(SCAVTRAP);
		bruce.guardGate();
		bruce.attack("JOKER");
	}
	{
		print_test_title("I'm ScavTrap. No, I mean ClapTrap. No! I mean ScavTrap... What's wrong with me?!");
		ScavTrap bruce("BRUCE");
	
		bruce.showStatus(SCAVTRAP);
		bruce.attack("JOKER");
		bruce.showStatus(SCAVTRAP);
		bruce.takeDamage(20);
		bruce.showStatus(SCAVTRAP);
		bruce.beRepaired(5);
		bruce.showStatus(SCAVTRAP);
		bruce.guardGate();
		bruce.showStatus(SCAVTRAP);
	}
}
