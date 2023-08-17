/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/17 17:10:32 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Test.hpp"
#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << BRED INVALID_USAGE "\n" BWHITE RULES RESET << std::endl;
        return EXIT_FAILURE;
    }

    std::string str = av[1];

    if (str.empty())
    {
        std::cout << BRED EMPTY_STRING RESET << std::endl;
        return EXIT_FAILURE;
    }

    // RPN
    try
    {
        std::cout << RPN(str) << std::endl;
    }
    catch (const RPNSyntaxError &ex)
    {
        std::cout << BRED << ex.what() << "\n" BWHITE RULES RESET << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cout << BRED << ex.what() << RESET << std::endl;
    }
    return 0;
}
