/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 11:05:10 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	print_test_title(std::string title) {
	std::cout << BCYAN << "\n[TEST]:" << title << DEF << std::endl;
}

int main(void) {

	{
		print_test_title("JOE is dead and can't do anything lmao");
		ClapTrap joe("JOE");

		joe.showStatus(CLAPTRAP);
		joe.takeDamage(10);
		joe.showStatus(CLAPTRAP);
		joe.attack("MAMA");
		joe.beRepaired(100);
	}
	{
		print_test_title("JOE runs out of energy points so he's basically useless");
		ClapTrap joe("JOE");

		joe.showStatus(CLAPTRAP);
		while (joe.getEnergyPoints() != 0)
			joe.beRepaired(0);
		joe.showStatus(CLAPTRAP);
		joe.attack("MAMA");
	}
	{
		print_test_title("The battle ends because JOE is tired lmao");
		ClapTrap joe("JOE");
		ClapTrap mama("MAMA");

		while (joe.getEnergyPoints() != 0) {
			joe.showStatus(CLAPTRAP);
			mama.showStatus(CLAPTRAP);
			joe.attack("MAMA");
			mama.takeDamage(0);
			mama.attack("JOE");
			joe.takeDamage(0);
		}
		joe.attack("MAMA");
		joe.showStatus(CLAPTRAP);
	}
}
