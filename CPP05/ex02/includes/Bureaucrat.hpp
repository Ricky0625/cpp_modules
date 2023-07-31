/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:10:35 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 11:32:01 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Color.hpp"
# include "Test.hpp"
# include "AForm.hpp"

class Form;

class Bureaucrat {
    public:
        Bureaucrat( void );
        Bureaucrat( const std::string &name, int grade );
        ~Bureaucrat( void );
        Bureaucrat( const Bureaucrat &src );
        Bureaucrat	&operator=( const Bureaucrat &other );

        // getters
        const std::string	&getName( void ) const;
        int			getGrade( void ) const;

        // grade related functions
        void    incrementGrade( void );
        void    decrementGrade( void );
        void    checkGrade( int grade ) const;
        void    updateGrade( int grade );

        // form related functions
        void    signForm(Form &form);
        void    executeForm(const Form &form);

        // toString
        std::string toString( void ) const;

        // exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();    
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        static const int    HIGHEST_GRADE = 1;
        static const int    LOWEST_GRADE = 150;
        const std::string	_name;
        int					_grade;
};

// overload insertion operator
std::ostream	&operator<<( std::ostream &out, const Bureaucrat &src );

#endif
