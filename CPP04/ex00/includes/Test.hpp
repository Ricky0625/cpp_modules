/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/25 14:19:59 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <iostream>
#include <string>

// change this to your program name, if want to test leaks
# define PROGRAM_NAME "polymorphism"

// Output test title
# define TEST_TITLE(x) std::cout << BGREEN << x << RESET << std::endl;

// Output test description
# define TEST_DESC(x) std::cout << BWHITE << "DESCRIPTION:\n" << WHITE << x << RESET << std::endl;

// Output test description continuation
# define TEST_DESC_CONT(x) std::cout << WHITE << x << RESET << std::endl;

// Test leaks
# define TEST_LEAKS(num) { \
    std::cout << URED << "Leaks check for TEST "<< num << ":" << RESET << std::endl; \
    std::string command = std::string("leaks -q ") + std::string(PROGRAM_NAME); \
    system(command.c_str()); \
}

// Await user input to continue to next test
# define TEST_AWAIT() { \
    std::cout << BWHITE << "Press any key to continue..." << RESET << std::endl; \
    std::cin.get(); \
}

#endif