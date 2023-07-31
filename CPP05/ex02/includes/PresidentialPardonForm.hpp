/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:36:08 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 13:01:31 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define FORMNAME "Presidential Pardon Form"

class PresidentialPardonForm : public Form {
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string &target );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm( const PresidentialPardonForm &other );
        PresidentialPardonForm &operator=( const PresidentialPardonForm &other );

        // override
        void    executeAction(const Bureaucrat &executor) const;

    private:
        static const std::string _FORMNAME;
        static const int _SIGNGRADE = 25;
        static const int _EXECUTEGRADE = 5;
        const std::string _target;
};

#endif
