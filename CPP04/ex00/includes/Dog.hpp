/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:09:10 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 11:16:24 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <Animal.hpp>

class Dog : public Animal {
    public:
        Dog( void );
        ~Dog( void );
        Dog( const Dog &other );
        Dog	&operator=( const Dog &other );
        virtual void   makeSound( void ) const;
};

#endif
