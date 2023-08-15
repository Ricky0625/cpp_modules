/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:34:55 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/15 15:43:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>

/**
 * In the context of `typename Container::iterator`, `Container` is a template
 * parameter, and `iterator` is a dependent type name (a type that depends on
 * a template parameter). However, the compiler doesn't know in advance that
 * `Container::iterator` is a type; it could also be a static member of something
 * else.
 * 
 * The `typename` keyword is used to tell the compiler that `Container::iterator`
 * is indeed a type. It helps the compiler to differentiate between types and non-
 * types in the context of dependent type names.
 * 
 * So, when you write `typename Container::iterator`, you're explicitly telling
 * the compiler that `Container::iterator` refers to a type, and it should treat
 * it as such.
*/

template <typename Container, typename T>
size_t easyfind(Container cont, const T& val);

class ElementNotFoundException : public std::exception {
    const char *what() const throw();
};

// helper function
template <typename Container>
void    showElements(Container cont);

#include "easyfind.tpp"

#endif
