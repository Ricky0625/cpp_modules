/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 15:02:46 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	print_test_title(std::string title) {
	std::cout << BCYAN << "\n[TEST]:" << title << DEF << std::endl;
}

int main(void) {

	{
		print_test_title("ScavTrap says hello");
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus();
	}
	{
		print_test_title("ScavTrap runs out of energy points and wants to take a power nap");
		int			i = -1;
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus();
		while (++i < 50)
			bruce.attack("JOKER");
		bruce.showStatus();
		bruce.attack("JOKER");
		bruce.guardGate();
	}
	{
		print_test_title("ScavTrap guards the gate for 50 rounds and wants to take a power nap");
		int			i = -1;
		ScavTrap	bruce("BRUCE");
	
		bruce.showStatus();
		while (++i < 50)
			bruce.guardGate();
		bruce.showStatus();
		bruce.guardGate();
		bruce.attack("JOKER");
	}
	{
		print_test_title("I'm ScavTrap. No, I mean ClapTrap. No! I mean ScavTrap... What's wrong with me?!");
		ScavTrap bruce("BRUCE");
	
		bruce.showStatus();
		bruce.attack("JOKER");
		bruce.showStatus();
		bruce.takeDamage(20);
		bruce.showStatus();
		bruce.beRepaired(5);
		bruce.showStatus();
		bruce.guardGate();
		bruce.showStatus();
	}
}
