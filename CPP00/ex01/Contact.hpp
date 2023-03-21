/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:31:26 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 18:57:26 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

using std::left; // left align output
using std::setw; // set padding for output

class Contact {
    public:
        Contact();
        ~Contact();
        std::string get_firstname(void);
        std::string get_lastname(void);
        std::string get_nickname(void);
        std::string get_phone(void);
        std::string get_secret(void);
        void        set_firstname(std::string firstname);
        void        set_lastname(std::string lastname);
        void        set_nickname(std::string nickname);
        void        set_phone(std::string phone);
        void        set_secret(std::string secret);
        void        print_contact_as_table(int index);
        void        print_contact();
        int         is_empty(void);
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone;
        std::string secret;
};

#endif
