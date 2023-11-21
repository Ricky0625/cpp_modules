/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:50:59 by wricky-t          #+#    #+#             */
/*   Updated: 2023/11/21 15:34:49 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// default constructor
Bureaucrat::Bureaucrat(void) : _name("unnamed"), _grade(LOWEST_GRADE) {}

// parameter constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    // check if the grade is out of range
    checkGrade(_grade);
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
    *this = src;
}

// assignment operator
Bureaucrat    &Bureaucrat::operator=(const Bureaucrat &other)
{
    _grade = other._grade;
    return *this;
}

// destructor
Bureaucrat::~Bureaucrat(void) {}

// get name
const std::string &Bureaucrat::getName() const
{
    return _name;
}

// get grade
int Bureaucrat::getGrade() const
{
    return _grade;
}

// user-defined exception: GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return RED "[BUREAUCRAT EXCEPTION] GRADE TOO HIGH!" RESET;
}

// user-defined exception: GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return RED "[BUREAUCRAT EXCEPTION] GRADE TOO LOW!" RESET;
}

// check grade
void    Bureaucrat::checkGrade(int grade) const
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
}

// update the grade, will perform a check before assign the new grade
void    Bureaucrat::updateGrade(int grade)
{
    // will throw an exception if it's too high or too low
    checkGrade(grade);
    // if no exception was thrown, execute the below
    _grade = grade;
}

// increment grade. since the highest is 1, meaning to increment grade, you need to decrement the grade
void    Bureaucrat::incrementGrade()
{
    int newGrade = _grade - 1;
    updateGrade(newGrade);
}

// decrement grade. since the lowest is 150, meaning to decrement grade, you need to increment the grade
void    Bureaucrat::decrementGrade()
{
    int newGrade = _grade + 1;
    updateGrade(newGrade);
}

// Seperate I/O from logic
std::string Bureaucrat::toString() const
{
    return getName() + ", bureaucrat grade " + std::to_string(getGrade());
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
    out << src.toString();
    return out;
}