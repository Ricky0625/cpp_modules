/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:31:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 21:44:04 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
    public:
        HumanA( std::string name, Weapon &weapon );
        ~HumanA( void );
        void        attack( void );
    private:
        std::string _name;
        Weapon      &_weapon;
};

/**
 * Using reference for the weapon because the weapon is a required for HumanA to be constructed.
 * HumanA will always be armed with a weapon.
 * 
 * Using reference for the weapon have a few advantages:
 * 1. Avoids create a new copy of the weapon object when constructing HumanA.
 * 2. Ensure that changes made to the weapon object will be reflected in the HumanA object.
*/

#endif