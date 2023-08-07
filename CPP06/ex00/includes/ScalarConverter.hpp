/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:01:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 20:29:10 by wricky-t         ###   ########.fr       */
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
};

#endif
