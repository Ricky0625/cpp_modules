/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:36:06 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 14:59:20 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <Animal.hpp>
# include <Brain.hpp>

const std::string GARFIELD_QUOTES[MAX_IDEA] = {
    "Love me, feed me, never leave me.",
    "I eat, therefore I am.",
    "I hate Mondays.",
    "I'm not overweight, I'm undertall.",
    "Big fat hairy deal.",
    "Diet is 'die' with a 't'.",
    "I never met a lasagna I didn't like",
    "It's not that I dislike you, I just don't like you near me."
};

const std::string TOM_QUOTES[MAX_IDEA] = {
    "Oh, I'm such a bad, bad, little kitty!",
    "Heavenly days!",
    "Ouch! That smarts!",
    "I've got nine lives, but I don't want to use them all at once.",
    "Dreams can come true, just keep believing.",
};

class Cat : public Animal {
    public:
        Cat( void );
        ~Cat( void );
        Cat( const Cat &other );
        Cat	&operator=( const Cat &other );
        virtual void   makeSound( void ) const;
        void    setIdea( int index, const std::string& idea );
        std::string &getIdea(int index) const;
    
    private:
        Brain *brain;
};

#endif
