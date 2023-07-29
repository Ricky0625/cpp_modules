/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 22:01:12 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::string name = "waduh";
    {
        TEST_TITLE("Test 0: Hello Bureaucrat!");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 42);
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 1: Grade too low!");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 160);
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 2: Grade too high!");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 0);
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 3: Highest grade");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 1);
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 4: Lowest grade");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 150);
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 5: Increment grade (normal)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 150);
            waduh.incrementGrade();
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 6: Decrement grade (normal)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 1);
            waduh.decrementGrade();
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 7: Increment grade (exceed)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 1);
            waduh.incrementGrade();
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
     {
        TEST_TITLE("Test 8: Decrement grade (exceed)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 150);
            waduh.decrementGrade();
            std::cout << waduh << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
}