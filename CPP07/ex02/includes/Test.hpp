/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:50:57 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/01 12:51:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <iostream>
#include <string>

// change this to your program name, if want to test leaks
# define PROGRAM_NAME "array"

// Output test title
# define TEST_TITLE(x) std::cout << BGREEN << x << RESET << std::endl;

// Output small test title
# define TEST_TITLE_S(x) std::cout << BWHITE << x << ":" << RESET << std::endl;

// Output test description
# define TEST_DESC(x) std::cout << BWHITE << "DESCRIPTION:\n" << WHITE << x << RESET << std::endl;

// Output test description continuation
# define TEST_DESC_CONT(x) std::cout << WHITE << x << RESET << std::endl;

// Test leaks
# define TEST_LEAKS(num) { \
    TEST_NL(); \
    std::cout << URED << "Leaks check for TEST "<< num << ":" << RESET << std::endl; \
    std::string command = std::string("leaks -q ") + std::string(PROGRAM_NAME); \
    system(command.c_str()); \
}

// Await user input to continue to next test
# define TEST_AWAIT() { \
    std::cout << BWHITE << "Press [ENTER] to continue..." << RESET << std::endl; \
    std::cin.get(); \
}

#define TEST_CONCLUDE(x) { \
    std::cout <<  UBLUE << "[CONCLUSION]\n" << RESET << BGBLUE << x << RESET << std::endl; \
}

#define TEST_CONCLUDE_CONT(x) { \
    std::cout << BGBLUE << x << RESET << std::endl; \
}

# define TEST_NL() std::cout << std::endl;

# define TEST_HR() std::cout << BWHITE << "\n==================================\n" << RESET << std::endl;

#endif