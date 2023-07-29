/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:28:02 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/27 21:17:38 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <iostream>
# include <AMateria.hpp>

class AMateria;

// Character Interface - pure abstract class
class ICharacter {
    public:
        virtual ~ICharacter( void ) {}
        virtual std::string const &getName( void ) const = 0;
        virtual void equip( AMateria* m ) = 0;
        virtual void unequip( int idx ) = 0;
        virtual void use( int idx, ICharacter& target ) = 0;
};

#endif
