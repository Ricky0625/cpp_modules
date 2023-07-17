/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:53:12 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/24 15:20:52 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:
        Weapon( void );
        Weapon(const std::string& type);
        ~Weapon( void );
        const std::string&  getType( void ) const;
        void                setType( const std::string& newType );
    private:
        std::string _type;
};

#endif
