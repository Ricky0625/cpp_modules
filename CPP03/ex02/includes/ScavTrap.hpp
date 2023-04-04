/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:38:36 by wricky-t          #+#    #+#             */
/*   Updated: 2023/04/04 14:02:41 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/**
 * Access modifiers in OOP are used to control the visibility and accessibility
 * of class members (variables, methods) to other parts of the program.
 * 
 * | Public    | Accessible from any part of the program.                |
 * | Protected | Accessible within the class and from the derived class. |
 * | Private   | Accessible within the class that defines them.          |
 * 
 * | Specifiers | Same class | Derived Class | Outside Class |
 * | ========== | ========== | ============= | ============= |
 * | public     | YES        | YES           | YES           |
 * | private    | YES        | NO            | NO            |
 * | protected  | YES        | YES           | NO            |
*/

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other );
		~ScavTrap( void );

		ScavTrap		&operator=(const ScavTrap &other);

		void			attack( const std::string& target );
		void			guardGate( void );
};

#endif
