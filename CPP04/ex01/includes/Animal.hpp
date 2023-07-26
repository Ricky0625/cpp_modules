/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:37 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 14:11:35 by wricky-t         ###   ########.fr       */
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
        const std::string&     getType( void ) const;
        virtual std::string &getIdea(int index) const = 0;

        // setters
        virtual void setIdea(int index, const std::string& idea) = 0;

    protected:
        std::string type;
};

#endif
