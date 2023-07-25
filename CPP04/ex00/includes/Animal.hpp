/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:37 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 12:52:57 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <Color.hpp>
# include <Test.hpp>

class Animal {
    public:
        Animal( void );
        virtual ~Animal( void );
        Animal( const Animal &other );
        Animal  &operator=( const Animal &other );

        // virtual function
        virtual void    makeSound( void ) const;

        // getters
        std::string     getType( void ) const;

    protected:
        std::string type;
};

#endif
