/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:42:39 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/27 21:08:09 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include <iostream>
# include <AMateria.hpp>
# include <ICharacter.hpp>

class Cure : public AMateria {
    public:
        Cure( void );
        ~Cure( void );
        Cure( const Cure &other );
        Cure	&operator=( const Cure &other );

        // override
        AMateria* clone( void ) const;
        void    use( ICharacter& target );
};

#endif
