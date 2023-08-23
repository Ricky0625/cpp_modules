/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/23 16:07:09 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Test.hpp"
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << BRED INVALID_USAGE RESET << std::endl;
        return (EXIT_FAILURE);
    }
    
    // skip the program name
    ++av;
    --ac;

    // create a vector of string based on the given args
    // template <class InputIterator> vector (InputIterator first, InputIterator last);
    std::vector<std::string> elements(av, av + ac);

    try 
    {
        PmergeMe::mergeMe(elements);
    }
    catch (const std::exception &ex)
    {
        std::cout << BRED << ex.what() << RESET << std::endl;
    }
}
