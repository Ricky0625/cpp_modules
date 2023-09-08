/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:14:13 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/08 15:34:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"
# include "Test.hpp"
# include "Color.hpp"

/**
 * Circular dependencies typically occur when header files include each other in a way
 * that creates a loop in the inclusion hierarchy. This can lead to compilation errors.
 * To deal with this, we need to use forward declarations to break circular dependencies.
*/

// Forward declaration - break circular dependency
class ICharacter;

// Abstract class for materia
class AMateria {
    public:
        AMateria( std::string const &type );
        virtual ~AMateria( void );
        AMateria( const AMateria &other );
        AMateria	&operator=( const AMateria &other );

        std::string const  &getType( void ) const; // Returns the materia type

        // Clone the materia, should be implemented by the derived class
        virtual AMateria* clone( void ) const = 0;
        // AMateria should have its own implementation but it's should be a "undefined behavior"
        virtual void use( ICharacter& target );

    protected:
        std::string _type;
};

#endif
