/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/12/18 14:08:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    {
        TEST_TITLE("Test 0: Subject test - robotomy request");

        Intern someRandomIntern;
        Form *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 1: Shrubbery Creation Form");

        Intern someRandomIntern;
        Form *scf;

        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *scf << std::endl;
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 2: Presidential Pardon Form");

        Intern someRandomIntern;
        Form *ppf;

        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *ppf << std::endl;
        TEST_NL();
    }
    {
        TEST_AWAIT();
        TEST_TITLE("Test 3: WHAT FORM ARE YOU LOOKING FOR? IDK!");

        Intern someRandomIntern;
        Form *what;

        what = someRandomIntern.makeForm("Form XA-87: Unicorn Adoption", "Bender");
        std::cout << *what << std::endl;
        TEST_NL();
    }
}