/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:03:13 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/15 15:44:32 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <algorithm>

template <typename Container>
size_t easyfind(Container cont, const int& val)
{
    typename Container::iterator it = std::find(cont.begin(), cont.end(), val);
    if (it == cont.end())
        throw ElementNotFoundException();
    return std::distance(cont.begin(), it);
}

const char *ElementNotFoundException::what() const throw ()
{
    return "[EXCEPTION]: Element not found!";
}

// helper function
template <typename Container>
void    showElements(Container cont)
{
    typename Container::iterator ptr;

    for (ptr = cont.begin(); ptr != cont.end(); ptr++)
        std::cout << *ptr << " ";
    std::cout << std::endl;
}
