/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:15:48 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 17:09:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <ICharacter.hpp>
# include <AMateria.hpp>

typedef enum e_storage_type {
    INVENTORY,
    DUSTBIN
} t_storage_type;

class Character : public ICharacter {
    public:
        Character( void );
        Character( std::string name );
        ~Character( void );
        Character( const Character &other );
        Character	&operator=( const Character &other );

        // override
        std::string const &getName( void ) const;
        void equip( AMateria* m );
        void unequip( int idx );
        void use( int idx, ICharacter& target );

        // helper function
        void    throwAway(AMateria *m);
        void    showSlots( t_storage_type type ) const;
        void    showMateriaTypeAsEmoji( int idx, t_storage_type type ) const;
    private:
        static const int MAX_INVENTORY = 4;
        static const int MAX_BIN_CAPACITY = 10;
        int         _inventorySize;
        AMateria    *_inventory[MAX_INVENTORY];
        int         _dustbinSize;
        AMateria    *_dustbin[MAX_BIN_CAPACITY];
        std::string _name;
};

#endif
