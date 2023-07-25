/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:36:06 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 11:16:17 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <Animal.hpp>

class Cat : public Animal {
    public:
        Cat( void );
        ~Cat( void );
        Cat( const Cat &other );
        Cat	&operator=( const Cat &other );
        virtual void   makeSound( void ) const;
};

#endif
