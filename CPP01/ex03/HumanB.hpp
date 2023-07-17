/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:51:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 21:05:19 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB( std::string name );
        ~HumanB( void );
        void        attack( void );
        void        setWeapon( Weapon &weapon );
    private:
        std::string _name;
        Weapon      *_weapon;
};

/**
 * Using pointer to the weapon because the weapon is not required for HumanB to be constructed.
 * Hence, it should be able to set to NULL. If we are using reference, it can't be NULL.
*/

#endif