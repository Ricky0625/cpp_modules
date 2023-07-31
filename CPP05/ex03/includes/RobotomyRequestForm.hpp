/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:11:43 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 16:00:42 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

# include <ctime>

class RobotomyRequestForm : public Form {
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string &target);
        ~RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm &other );
        RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );

        // override
        void    executeAction(const Bureaucrat &executor) const;

    private:
        static const std::string _FORMNAME;
        static const int _SIGNGRADE = 72;
        static const int _EXECUTEGRADE = 45;
        const std::string _target;
};

#endif
