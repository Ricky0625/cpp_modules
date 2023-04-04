/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:29:59 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	print_test_title(std::string title) {
	std::cout << BCYAN << "\n[TEST]:" << title << DEF << std::endl;
}

int main(void) {

	{
		print_test_title("FragTrap says hello");
		FragTrap	johnny("JOHNNY");

		johnny.showStatus(FRAGTRAP);
	}
	{
		print_test_title("FragTrap asking for high fives until it runs out of energy points ;(");
		FragTrap	johnny("JOHNNY");
		
		johnny.showStatus(FRAGTRAP);
		while (johnny.getEnergyPoints())
			johnny.highFivesGuys();
		johnny.showStatus(FRAGTRAP);
		johnny.highFivesGuys();
	}
	{
		print_test_title("FragTrap is having an identity crisis");
		FragTrap	johnny("JOHNNY");

		johnny.showStatus(FRAGTRAP);
		johnny.attack("TIMMY");
		johnny.showStatus(FRAGTRAP);
		johnny.takeDamage(30);
		johnny.showStatus(FRAGTRAP);
		johnny.beRepaired(10);
		johnny.showStatus(FRAGTRAP);
		johnny.highFivesGuys();
		johnny.showStatus(FRAGTRAP);
	}
}
