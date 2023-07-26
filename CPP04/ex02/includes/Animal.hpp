/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:03:37 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 19:05:26 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <Color.hpp>
# include <Test.hpp>

/**
 * In this exercise, we are required to make this class not instantiable.
 * Constructor(s) are used to initialize the object. If the class is not instantiable,
 * it make sense to make the constructor(s) inaccessible.
 * To prevent this, we can make the constructor(s) protected or private.
 * To enforce the rule, assignment operator should also be protected or private.
 * Otherwise it doesn't make sense.
 * 
 * Oh wait. Why is destructor still public? If a class is not instantiable, it shouldn't
 * be able to be destroyed right...? Well, actually the answer is no. A virtual destructor
 * is still needed if we declare a pointer to the abstract class and instantiate it with
 * a derived class. The pointer will be pointing to the derived class, but the destructor
 * will be called from the abstract class. If the destructor is not virtual, the derived
 * class destructor will not be called, and the derived class will not be destroyed properly.
*/

/**
 * @attention Cannot be instantiated
*/
class Animal {
    public:
        virtual ~Animal( void );
        virtual void    makeSound( void ) const = 0;

        // getters
        const std::string&     getType( void ) const;
        virtual std::string &getIdea(int index) const = 0;

        // setters
        virtual void setIdea(int index, const std::string& idea) = 0;

    protected:
        Animal( void );
        Animal( const Animal &other );
        Animal  &operator=( const Animal &other );
        std::string type;
};

#endif
