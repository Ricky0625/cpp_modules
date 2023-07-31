/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:38:23 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 17:36:41 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// default constructor
Intern::Intern() {}

// copy constructor
Intern::Intern(const Intern &other)
{
    (void)other;
}

// assignment operator (overload)
Intern    &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

// destructor
Intern::~Intern() {}

static t_form getFormType(const std::string &formName)
{
    if (formName == "shrubbery creation")
        return SHRUBBERY;
    
    if (formName == "robotomy request")
        return ROBOTOMY;
    
    if (formName == "presidential pardon")
        return PRESIDENTIAL;
    
    return UNKNOWN;
}

Form    *Intern::makeForm(const std::string &formName, const std::string &target)
{
    t_form  formType = getFormType(formName);
    Form    *newForm = NULL;

    switch (formType)
    {
    case SHRUBBERY:
        newForm = new ShrubberyCreationForm(target);
        break;
    case ROBOTOMY:
        newForm = new RobotomyRequestForm(target);
        break;
    case PRESIDENTIAL:
        newForm = new PresidentialPardonForm(target);
        break;
    case UNKNOWN:
        newForm = NULL;
        break;
    }
    if (newForm != NULL)
        std::cout << "Intern creates " << newForm->getName() << std::endl;
    else
    {
        std::cout << "[INTERN]: Dear boss. I can't find the form you requested. :) So here's a unnamed form." << std::endl;
        newForm = new Form();
    }
    return newForm;
}
