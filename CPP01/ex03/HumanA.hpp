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
        std::string name;
        Weapon      &weapon;
};

#endif