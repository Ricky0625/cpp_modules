/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:17:01 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 15:24:25 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal {
    public:
        WrongCat( void );
        ~WrongCat( void );
        WrongCat( const WrongCat &other );
        WrongCat	&operator=( const WrongCat &other );
        void    makeSound( void ) const;
};

#endif

