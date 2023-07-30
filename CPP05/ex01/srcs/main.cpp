/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:28:32 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/30 14:28:54 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::string name = "waduh";
    {
        TEST_TITLE("Test 0: Form up!");
        TEST_NL();

        try {
            Form flyingCarpet("Form 42-B: Authorization for Flying Carpet Usage", 42, 42);

            std::cout << flyingCarpet << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 1: Invalid form - Grade too low");
        TEST_NL();

        try {
            // gradeToSign too low
            Form potion("Form 777-Z: Potion Approval Request", 200, 50);
            std::cout << potion << std::endl;
        } catch (const Form::GradeTooLowException& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();

        try {
            // gradeToExecute too low
            Form timeTravel("Form X-13: Time travel License Application", 42, 500);
            std::cout << timeTravel << std::endl;
        } catch (const Form::GradeTooLowException& ex) {
            std::cout << ex.what() << std::endl;
        }

        TEST_NL();
    }
    {
        TEST_TITLE("Test 2: Invalid form - Grade too high");
        TEST_NL();

        try {
            // gradeToSign too high
            Form potion("Form 777-Z: Potion Approval Request", 0, 50);
            std::cout << potion << std::endl;
        } catch (const Form::GradeTooHighException& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();

        try {
            // gradeToExecute too high
            Form timeTravel("Form X-13: Time travel License Application", 42, 0);
            std::cout << timeTravel << std::endl;
        } catch (const Form::GradeTooHighException& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 3: Highest grade");
        TEST_NL();

        try {
            Form potion("Form 777-Z: Potion Approval Request", 1, 1);
            std::cout << potion << std::endl;
        } catch (const Form::GradeTooLowException& ex) {
            std::cout << ex.what() << std::endl;
        } catch (const Form::GradeTooHighException& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 4: Lowest grade");
        TEST_NL();

        try {
            Form potion("Form X-13: Time travel License Application", 150, 150);
            std::cout << potion << std::endl;
        } catch (const Form::GradeTooLowException& ex) {
            std::cout << ex.what() << std::endl;
        } catch (const Form::GradeTooHighException& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 5: Sign form - success");

        try {
            Bureaucrat waduh(name, 42);
            Form unicorn("Form Z-2022: Unicorm Adoption Form", 60, 40);

            std::cout << "Person In Charge:\n" << waduh << std::endl;

            TEST_NL();
            std::cout << "BEFORE:\n" << unicorn << std::endl; 

            waduh.signForm(unicorn);
            std::cout << "AFTER:\n" << unicorn << std::endl;
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 6: Sign form - Failed (Form has been signed before attempting to sign it)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 1);
            Bureaucrat jake("jake", 5);
            Form dragon("Form W-404: Dragon Fire Permit", 100, 100);

            std::cout << "Jake signed the form first" << std::endl;
            jake.signForm(dragon);
            std::cout << dragon << std::endl;

            TEST_NL();
            std::cout << "Waduh attempting to sign form" << std::endl;
            jake.signForm(dragon);
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
    {
        TEST_TITLE("Test 7: Sign form - Failed (Grade too low)");
        TEST_NL();

        try {
            Bureaucrat waduh(name, 150);
            Form enchanted("Form Y-2023: Enchanted Item Registration", 1, 5);
            
            std::cout << "Person in charge:\n" << waduh << std::endl;
            std::cout << "The Form:\n" << enchanted << std::endl;
            
            // attempting to sign the form
            waduh.signForm(enchanted);

            if (enchanted.getIsSigned())
                std::cout << "The updated form:\n" << enchanted << std::endl;
            else
                throw Form::GradeTooLowException();
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        
        TEST_NL();
    }
}