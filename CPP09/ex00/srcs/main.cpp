/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/19 15:05:45 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Test.hpp"
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << BRED INVALID_USAGE RESET << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        BitcoinExchange::bitcoinExchange(av[1]);
    }
    catch (const std::exception &ex)
    {
        std::cout << BRED << ex.what() << RESET << std::endl;
    }
}
