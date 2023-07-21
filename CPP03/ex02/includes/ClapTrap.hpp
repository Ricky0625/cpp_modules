/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:26:56 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:15:27 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <iomanip>

# define BCYAN "\033[1;34m"
# define DEF "\033[0m"

enum	e_check {
	HP,
	EP,
	ALL	
};

enum	e_trap {
	CLAPTRAP,
	SCAVTRAP,
	FRAGTRAP,
	DIAMONDTRAP
};

class ClapTrap
{
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &other );
		// Informing the compiler to call the most derived class's destructor first
		// when deleting objects through a base class pointer.
		virtual ~ClapTrap( void );

		ClapTrap		&operator=(const ClapTrap &other);

		// Member functions
		// NOTE: virtual keyword is used to allow derived class to override the function
		// Since ScavTrap will also have attack function, we can make it virtual so that
		// it can override this function to have different implementation.
		virtual void	attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void 			beRepaired( unsigned int amount );

		// Helper member functions
		bool			canAct( e_trap trap, e_check check );
		void			showStatus( e_trap trap );
		unsigned int	getEnergyPoints( void ) const;
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif