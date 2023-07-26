/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:09:10 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 18:31:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <Animal.hpp>
# include <Brain.hpp>

const std::string SNOOPY_QUOTES[MAX_IDEA] = {
    "Never forget to smile.",
    "Keep looking up... that's the secret of life.",
    "Everyone understand kindness.",
    "The best way to cheer yourself up is to try to cheer somebody else up.",
    "The less you want, the more you love.",
    "Each of us has his own calling.",
    "I think I'm allergic to morning.",
    "I can't... I'm thinking about pizza.",
};

const std::string SCOOBY_QUOTES[MAX_IDEA] = {
    "Scooby Doobie Doooo!",
    "Yeah, yeah, yeah, yeah!",
    "rought ra rindow.",
    "Over here!",
    "Ruh-roh-RAGGY!!!",
    "Rizza Rie!",
};

class Dog : public Animal {
    public:
        Dog( void );
        ~Dog( void );
        Dog( const Dog &other );
        Dog	&operator=( const Dog &other );
        virtual void   makeSound( void ) const;
        void    setIdea( int index, const std::string& idea );
        std::string &getIdea(int index) const;

    private:
        Brain *brain;
};

#endif
