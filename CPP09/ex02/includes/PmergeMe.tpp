/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:54:37 by wricky-t          #+#    #+#             */
/*   Updated: 2023/09/07 13:45:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void showElements(Container cont)
{
    size_t size = cont.size();
    
    for (size_t i = 0; i < size; i++)
        std::cout << cont[i] << " ";
    std::cout << std::endl;
}
