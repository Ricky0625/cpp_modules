/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:34:24 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 17:45:59 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define MAX_IDEA 100

class Brain {
    public:
        Brain( void );
        ~Brain( void );
        Brain( const Brain &other );
        Brain	&operator=( const Brain &other );
        void    setIdea( int index, const std::string& idea );
        std::string &getIdea(int index) const;

    private:
        std::string *ideas;
};

#endif
