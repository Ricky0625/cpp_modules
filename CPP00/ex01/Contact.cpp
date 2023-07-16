/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:18:09 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 19:01:28 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact() {}

// Destructor
Contact::~Contact() {}

// Getter: Get first name
std::string Contact::getFirstname() const {
    return _firstname;
}

// Getter: Get last name
std::string Contact::getLastname() const {
    return _lastname;
}

// Getter: Get nickname
std::string Contact::getNickname() const {
    return _nickname;
}

// Getter: Get phone number
std::string Contact::getPhone() const {
    return _phone;
}

// Getter: Get darkest secret
std::string Contact::getSecret() const {
    return _secret;
}

// Setter: Set first name
void    Contact::setFirstname(const std::string firstname) {
    _firstname = firstname;
}

// Setter: Set last name
void    Contact::setLastname(const std::string lastname) {
    _lastname = lastname;
}

// Setter: Set nickname
void    Contact::setNickname(const std::string nickname) {
    _nickname = nickname;
}

// Setter: Set phone number
void    Contact::setPhone(const std::string phone) {
    _phone = phone;
}

// Setter: Set darkest secret
void    Contact::setSecret(const std::string secret) {
    _secret = secret;
}

// Helper: Truncate string to 10 characters.
// If the string is longer than 10 characters, replace the last character with a dot.
static std::string truncate_str(std::string str)
{
    if (str.length() < 10)
        return str;
    return str.substr(0, 10 - 1) += ".";
}

// Helper: Print contact object as a table
void    Contact::printContactAsTable(int index)
{
    std::cout << "|";
    std::cout << setw(10) << index << "|";
    std::cout << setw(10) << truncate_str(_firstname) << "|";
    std::cout << setw(10) << truncate_str(_lastname) << "|";
    std::cout << setw(10) << truncate_str(_nickname) << "|\n";
}

// Helper: Print contact object as a list
void    Contact::printContact()
{
    std::cout << "\n";
    std::cout << setw(20) << "First name: " << _firstname << "\n";
    std::cout << setw(20) << "Last name: " << _lastname << "\n";
    std::cout << setw(20) << "Nickname: " << _nickname << "\n";
    std::cout << setw(20) << "Phone number: " << _phone << "\n";
    std::cout << setw(20) << "Darkest secret: " << _secret << "\n\n";
}

/**
 * "A saved contact can't have empty fields."
 * Based on this, check if the firstname field is empty.
 * If it's empty, meaning the contact is completely empty.
*/
int Contact::isEmpty() {
    return (_firstname.empty());
}
