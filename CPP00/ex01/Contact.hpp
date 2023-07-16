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
# include <cstdlib>

using std::left; // left align output
using std::setw; // set padding for output

class Contact {
    public:
        Contact();
        ~Contact();
        // getters
        std::string getFirstname() const;
        std::string getLastname() const;
        std::string getNickname() const;
        std::string getPhone() const;
        std::string getSecret() const;
        // setters
        void        setFirstname(const std::string firstname);
        void        setLastname(const std::string lastname);
        void        setNickname(const std::string nickname);
        void        setPhone(const std::string phone);
        void        setSecret(const std::string secret);
        // helpers
        void        printContactAsTable(int index);
        void        printContact();
        int         isEmpty();
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};

#endif
