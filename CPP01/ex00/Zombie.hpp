/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:35:40 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 14:41:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    public:
        Zombie(); // constructor
        ~Zombie(); // destructor
        void    announce( void ); 
        void    setName( const std::string& name ); // setter
    private:
        std::string name;
};

void    randomChump( std::string name );
Zombie  *newZombie( std::string name );

#endif