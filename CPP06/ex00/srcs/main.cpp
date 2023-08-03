/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/02 20:24:37 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Test.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "[ERROR]: ./converter <arg>" << std::endl;
        exit(EXIT_FAILURE);
    }

    ScalarConverter::convert(av[ac - 1]);
}