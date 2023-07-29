/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:10:35 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/29 21:54:03 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>
# include <cstdlib>
# include "Color.hpp"
# include "Test.hpp"

# define EXCEPTION_TAG BPURPLE "[ Exception ]: " RESET

class Bureaucrat {
    public:
        Bureaucrat( void );
        Bureaucrat( std::string &name, int grade );
        ~Bureaucrat( void );
        Bureaucrat( const Bureaucrat &src );
        Bureaucrat	&operator=( const Bureaucrat &other );

        // getters
        const std::string	&getName( void ) const;
        int			getGrade( void ) const;

        // grade related functions
        void    incrementGrade( void );
        void    decrementGrade( void );
        void    checkGrade( int grade );

        // exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char	*what() const throw();    
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
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
