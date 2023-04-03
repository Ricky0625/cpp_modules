/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/03 15:52:40 by wricky-t         ###   ########.fr       */
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

		johnny.showStatus();
	}
	{
		int	i = -1;
		print_test_title("FragTrap asking for high fives until it runs out of energy points ;(");
		FragTrap	johnny("JOHNNY");
		
		johnny.showStatus();
		while (++i < 100)
			johnny.highFivesGuys();
		johnny.showStatus();
		johnny.highFivesGuys();
	}
	{
		print_test_title("FragTrap is having an identity crisis");
		FragTrap	johnny("JOHNNY");

		johnny.showStatus();
		johnny.attack("TIMMY");
		johnny.showStatus();
		johnny.takeDamage(30);
		johnny.showStatus();
		johnny.beRepaired(10);
		johnny.showStatus();
		johnny.highFivesGuys();
		johnny.showStatus();
	}
}
