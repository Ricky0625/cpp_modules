/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 17:02:44 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat john("john", 150);
    Bureaucrat mark("mark", 1);
    Bureaucrat yasir("yasir", 5);
    Bureaucrat casey("casey", 70);
    Bureaucrat raymark("raymark", 20);
    // {
    //     // comment out this test case block to run tests
    //     TEST_TITLE("Test 0: AForm is not instantiatable anymore because it's an abstract class");
    //     Form nope;
    //     Form *nnope = new AForm();
    // }
    {
        TEST_TITLE("Test 1: Shrubbery Creation Form");
        TEST_NL();
        Form *scf = new ShrubberyCreationForm("mama");
        std::cout << *scf << std::endl;

        TEST_DESC_CONT("Casey signed the form");
        casey.signForm(*scf);
        std::cout << "\n"
                  << *scf << std::endl;

        TEST_DESC_CONT("John try to execute the form.");
        raymark.executeForm(*scf);
        TEST_NL();

        delete scf;
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: Robotomy Request Form");
        TEST_NL();
        Form *rrf = new RobotomyRequestForm("mama");
        std::cout << *rrf << std::endl;

        TEST_DESC_CONT("Casey signed the form");
        casey.signForm(*rrf);
        std::cout << "\n"
                  << *rrf << std::endl;

        TEST_DESC_CONT("John try to execute the form.");
        john.executeForm(*rrf);
        TEST_NL();

        TEST_DESC_CONT("Yasir try to execute the form.");
        yasir.executeForm(*rrf);
        TEST_NL();

        delete rrf;
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: Presidential Pardon Form");
        TEST_NL();

        Form *ppf = new PresidentialPardonForm("mama");
        std::cout << *ppf << std::endl;

        TEST_DESC_CONT("Mark signed the form.");
        mark.signForm(*ppf);
        std::cout << "\n"
                  << *ppf << std::endl;

        TEST_DESC_CONT("John try to execute the form.");
        john.executeForm(*ppf); // grade too low
        TEST_NL();

        TEST_DESC_CONT("Raymark try to execute the form.");
        raymark.executeForm(*ppf); // grade too low
        TEST_NL();

        TEST_DESC_CONT("Mark try to execute the form.");
        mark.executeForm(*ppf);
        TEST_NL();

        TEST_DESC_CONT("Yasir try to execute the form.");
        yasir.executeForm(*ppf);
        TEST_NL();

        delete ppf;
        TEST_NL();
    }
}