/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:01:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 15:28:22 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstdlib>
# include <limits>
# include <iomanip>

# include "Color.hpp"
# include "helper.h"

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

        // min/max value of each data type
        static const unsigned char SC_CHAR_MIN;
        static const unsigned char SC_CHAR_MAX;
        static const int SC_INT_MIN;
        static const int SC_INT_MAX;
        static const float SC_FLOAT_MIN;
        static const float SC_FLOAT_MAX;
        static const double SC_DOUBLE_MIN;
        static const double SC_DOUBLE_MAX;
};

#endif
