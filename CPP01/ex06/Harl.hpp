/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:37:26 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 14:30:34 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <iomanip>

enum e_level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define BLU "\033[1;36m"
# define PPL "\033[1;35m"
# define DFL "\033[0m"

class Harl
{
    public:
        Harl( void );
        ~Harl( void );
        void    complain( std::string level );
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
};

#endif