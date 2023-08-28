/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:42:38 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/28 21:08:25 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap( void );
        DiamondTrap( std::string name );
        ~DiamondTrap( void );
        DiamondTrap( const DiamondTrap &other );
        DiamondTrap	&operator=( const DiamondTrap &other );
        void	whoAmI( void );
        std::string    getName( void ) const;
        using ScavTrap::attack;

    private:
        std::string _name;
};

#endif