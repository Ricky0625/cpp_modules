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
        std::string name;
        Weapon      *weapon;
};

#endif