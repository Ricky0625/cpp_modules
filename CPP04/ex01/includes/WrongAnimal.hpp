/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:14:34 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 14:16:15 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal {
    public:
        WrongAnimal( void );
        // NOTE: not setting virtual destructor purposefully to see the difference
        ~WrongAnimal( void );
        WrongAnimal( const WrongAnimal &other );
        WrongAnimal	&operator=( const WrongAnimal &other );

        // Not letting this function to be overridden purposefully to see the difference
        void    makeSound( void ) const;

        std::string    getType( void ) const;

    protected:
        std::string type;
};

#endif
