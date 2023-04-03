/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 13:49:08 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	print_test_title(std::string title) {
	std::cout << BCYAN << "\n[TEST]:" << title << DEF << std::endl;
}

int main(void) {

	{
		print_test_title("ClapTrap is dead and can't do anything lmao");
		ClapTrap joe("JOE");

		joe.showStatus();
		joe.takeDamage(10);
		joe.showStatus();
		joe.attack("MAMA");
		joe.beRepaired(100);
	}
	{
		print_test_title("ClapTrap runs out of energy points so he's basically useless");
		ClapTrap joe("JOE");

		int	i = -1;
		joe.showStatus();
		while (++i < 10)
			joe.beRepaired(0);
		joe.showStatus();
		joe.attack("MAMA");
	}
	{
		print_test_title("The Battle that will never ends - JOE vs MAMA");
		ClapTrap joe("JOE");
		ClapTrap mama("MAMA");

		joe.showStatus();
		mama.showStatus();
		joe.attack("MAMA");
		mama.takeDamage(joe.getAttackDamage());
		joe.showStatus();
		mama.showStatus();
		mama.attack("JOE");
		joe.takeDamage(mama.getAttackDamage());
		joe.showStatus();
		mama.showStatus();
		joe.attack("MAMA");
		mama.takeDamage(joe.getAttackDamage());
		joe.showStatus();
		mama.showStatus();
		mama.attack("JOE");
		joe.takeDamage(mama.getAttackDamage());
		joe.showStatus();
		mama.showStatus();
	}
}
