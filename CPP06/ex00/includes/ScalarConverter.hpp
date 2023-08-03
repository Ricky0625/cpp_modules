/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:01:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/03 15:18:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>

# include "Color.hpp"

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} e_type;

typedef enum e_error {
    E_IMPOSSIBLE,
    E_NAN,
    E_INFP,
    E_INFN,
    E_NON_DISPLAYABLE
} e_error;

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
