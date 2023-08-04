/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:01:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/04 20:29:33 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>

# include "Color.hpp"

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} e_type;

typedef enum e_convert_type {
    E_IMPOSSIBLE,
    E_NANF,
    E_NAN,
    E_PINFF,
    E_PINF,
    E_NINFF,
    E_NINF,
    E_NON_DISPLAYABLE,
    E_CONVERTABLE
} e_convert_type;

class ScalarConverter {
    public:
        static void convert( const std::string &raw );

    private:
        // Private constructor and destructor to prevent instantiation
        ScalarConverter( void );
        ~ScalarConverter( void );
        ScalarConverter( const ScalarConverter &other );
        // Private assignment operator to prevent assignment
        ScalarConverter &operator=( const ScalarConverter &other );
        
};

#endif