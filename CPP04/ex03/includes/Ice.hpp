/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:49:09 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/27 21:03:59 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include <iostream>
# include <AMateria.hpp>
# include <ICharacter.hpp>

class Ice : public AMateria {
    public:
        Ice( void );
        ~Ice( void );
        Ice( const Ice &other );
        Ice	&operator=( const Ice &other );

        // override
        AMateria* clone( void ) const; 
        void use( ICharacter& target );
};

#endif
