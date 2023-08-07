/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:38:18 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/07 20:47:33 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/************************************************************
 * The member below has no meaning, will not be using these *
 *      Static class should not be able to instantiate      *
 ************************************************************/

// default constructor
Serializer::Serializer() {}

// copy constructor
Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

// assignment operator (overload)
Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

// destructor
Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data    *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
