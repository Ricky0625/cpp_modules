/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:04:29 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/30 14:28:39 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <exception>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form( void );
        Form ( const std::string &name, int toSign, int toExecute );
        ~Form( void );
        Form( const Form &other );
        Form	&operator=( const Form &other );

        // toString
        std::string toString( void ) const;

        // getters
        const std::string&  getName( void ) const;
        bool getIsSigned( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExecute( void ) const;

        // grade related member function
        void    checkFormGrade( void ) const;

        // member functions
        void    beSigned( const Bureaucrat& src );

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        static const int    HIGHEST_GRADE = 1;
        static const int    LOWEST_GRADE = 150;
        const std::string	_name;
        bool				_isSigned;
        const int			_gradeToSign;
        const int			_gradeToExecute;
        
};

std::ostream	&operator<<( std::ostream &out, const Form &src );

#endif
