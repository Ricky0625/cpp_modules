/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:35:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:43:45 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>

class Zombie
{
    public:
        Zombie( void );
        ~Zombie( void );
        void    announce( void );
        void    setName( std::string name );
    private:
        std::string name;
};

Zombie  *zombieHorde( int N, std::string name );

#endif