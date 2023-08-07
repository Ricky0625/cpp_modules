/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:28:11 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 21:42:31 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>
# include <iomanip>

# include "Color.hpp"
# include "data.h"

// "uintptr" stands for "unsigned integer type capable of holding a pointer"
// "_t" suffix is a common naming convention in C/C++
// This data type is guranteed to have the same size as a pointer on the system,
// allowing developer to convert between pointers and integers safely.

class Serializer {
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

    private:
        Serializer( void );
        ~Serializer( void );
        Serializer( const Serializer &other );
        Serializer	&operator=( const Serializer &other );
};

#endif
