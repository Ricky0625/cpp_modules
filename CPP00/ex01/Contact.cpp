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

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::get_firstname() {
    return this->firstname;
}

std::string Contact::get_lastname() {
    return this->lastname;
}

std::string Contact::get_nickname() {
    return this->nickname;
}

std::string Contact::get_phone() {
    return this->phone;
}

std::string Contact::get_secret() {
    return this->secret;
}

void    Contact::set_firstname(std::string firstname) {
    this->firstname = firstname;
}

void    Contact::set_lastname(std::string lastname) {
    this->lastname = lastname;
}

void    Contact::set_nickname(std::string nickname) {
    this->nickname = nickname;
}

void    Contact::set_phone(std::string phone) {
    this->phone = phone;
}

void    Contact::set_secret(std::string secret) {
    this->secret = secret;
}

static std::string truncate_str(std::string str)
{
    if (str.length() < 10)
        return str;
    return str.substr(0, 10 - 1) += ".";
}

void    Contact::print_contact_as_table(int index)
{
    std::cout << "|";
    std::cout << setw(10) << index << "|";
    std::cout << setw(10) << truncate_str(this->firstname) << "|";
    std::cout << setw(10) << truncate_str(this->lastname) << "|";
    std::cout << setw(10) << truncate_str(this->nickname) << "|\n";
}

void    Contact::print_contact()
{
    std::cout << "\n";
    std::cout << setw(20) << "First name: " << this->firstname << "\n";
    std::cout << setw(20) << "Last name: " << this->lastname << "\n";
    std::cout << setw(20) << "Nickname: " << this->nickname << "\n";
    std::cout << setw(20) << "Phone number: " << this->phone << "\n";
    std::cout << setw(20) << "Darkest secret: " << this->secret << "\n\n";
}

/**
 * "A saved contact can't have empty fields."
 * Based on this, check if the firstname field is empty.
 * If it's empty, meaning the contact is completely empty.
*/
int Contact::is_empty() {
    return (this->firstname.empty());
}
