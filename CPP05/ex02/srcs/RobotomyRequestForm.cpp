/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:11:34 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 15:44:50 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::_FORMNAME = "Robotomy Request Form";

// default constructor
RobotomyRequestForm::RobotomyRequestForm() : Form(_FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target("unknown") {}

// parameter constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(_FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target(target) {}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
}

// assignment operator (overload)
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
    return *this;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// override
void    RobotomyRequestForm::executeAction(const Bureaucrat &executor) const
{
    // Seed the random number generator
    std::srand(std::time(0));
    int success = std::rand() % 2;
    // 0 means failed, 1 means successful
    std::cout << BPURPLE << " * Some drilling noises * " RESET << std::endl;
    std::cout << "[" << executor.getName() << "]: Task to robotomize " << _target << BWHITE " " << (success ? BGGREEN "IS A BIG SUCCESS!" : BGRED "IS A BIG FAILURE...") << RESET << std::endl;
}
