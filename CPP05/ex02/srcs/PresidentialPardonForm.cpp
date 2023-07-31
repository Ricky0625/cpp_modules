/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:53:27 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 15:29:50 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::_FORMNAME = "Presidential Pardon Form";

// default constructor
PresidentialPardonForm::PresidentialPardonForm() : Form(FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target(target) {}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
}

// assignment operator (overload)
PresidentialPardonForm    &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
    return *this;
}

// destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::executeAction(const Bureaucrat &executor) const
{
    std::cout << "[" << executor.getName() << "]: ";
    std::cout << BPURPLE << _target << " has been pardoned by Zaphod Beeblebrox." RESET << std::endl;
}
