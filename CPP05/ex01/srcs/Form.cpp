/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:24:51 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 16:26:53 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// default constructor
Form::Form() : _name("unnamed form"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
    checkFormGrade();
}

// Parameter constructor
Form::Form(const std::string &name, int toSign, int toExecute) : _name(name), _isSigned(false), _gradeToSign(toSign), _gradeToExecute(toExecute)
{
    checkFormGrade();
}

// copy constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    *this = other;
}

// assignment operator (overload)
Form    &Form::operator=(const Form &other)
{
    _isSigned = other._isSigned;
    return *this;
}

// destructor
Form::~Form() {}

// getter: get name
const std::string &Form::getName() const
{
    return _name;
}

// getter: get isSigned
bool    Form::getIsSigned() const
{
    return _isSigned;
}

// getter: get gradeToSign
int   Form::getGradeToSign() const
{
    return _gradeToSign;
}

// getter: getGradeToExecute
int   Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

// helper: check if the form's grade whether it's the execute grade or sign grade is within range
// will throw exception when it's not within range
void    Form::checkFormGrade() const
{
    if (_gradeToExecute < HIGHEST_GRADE || _gradeToSign < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (_gradeToSign > LOWEST_GRADE || _gradeToExecute > LOWEST_GRADE)
        throw GradeTooLowException();
}

/**
 * @brief Sign the form
 * A bureaucrat can only sign the form if his/her grade is higher or equal to the signGrade
 * Grade 1 is the highest. Grade 150 is the lowest.
*/
void    Form::beSigned(const Bureaucrat& src)
{
    _isSigned = (src.getGrade() <= _gradeToSign);
    // if the form cannot be signed, throw error
    if (_isSigned == false)
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return RED "[FORM EXCEPTION] GRADE TOO HIGH" RESET;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return RED "[FORM EXCEPTION] GRADE TOO LOW" RESET;
}

std::string Form::toString() const
{
    return  BGBLACK "\t" + getName() + RESET
            + "\n\tGrade to sign:    " + UGREEN + std::to_string(getGradeToSign()) + RESET
            + "\n\tGrade to execute: " + UGREEN + std::to_string(getGradeToExecute()) + RESET
            + "\n\tSigned?           " + (getIsSigned() ? BGREEN "TRUE" : BRED "FALSE") + RESET
            + "\n";
}

std::ostream    &operator<<(std::ostream &out, const Form& src)
{
    out << src.toString();
    return out;
}
