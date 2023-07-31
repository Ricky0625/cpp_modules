/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:30:45 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 17:24:31 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef enum e_form
{
    SHRUBBERY,
    ROBOTOMY,
    PRESIDENTIAL,
    UNKNOWN
}   t_form;

class Intern {
    public:
        Intern( void );
        ~Intern( void );
        Intern( const Intern &other );
        Intern	&operator=( const Intern &other );

        // member function
        Form    *makeForm(const std::string &formName, const std::string &target);
};

#endif
