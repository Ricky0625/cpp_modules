/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:04:15 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 21:38:43 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->index = 0;
    this->total = 0;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "\nBye bye~ Thanks for using PhoneBook.\n";
}

int PhoneBook::get_index(void) {
    return this->index;
}

int PhoneBook::get_total(void) {
    return this->total;
}

void   PhoneBook::show_cmds(void) {
    std::cout << "\n\tHere are the list of commands (case-sensitive):\n";
    std::cout << left << setw(7) << "\tADD" << "| Add new contact.\n";
    std::cout << left << setw(7) << "\tSEARCH" << "| Look up a contact.\n";
    std::cout << left << setw(7) << "\tEXIT" << "| Exit PhoneBook.\n";
}

static std::string replace_tabs(std::string str, int spacesPerTab)
{
    std::string newStr;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == '\t') {
            for (int i = 0; i < spacesPerTab; i++)
                newStr += ' ';
        }
        else
            newStr += str[i];
    }
    return newStr;
}

std::string get_input(std::string prompt) {

    std::string input;

    while (1)
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\n[ERROR]: INTERRUPTED!\n";
            std::exit(EXIT_FAILURE);
        }
        else if (input.empty() == 1) {
            continue ;
        }
        else
            break ;
    }
    input = replace_tabs(input, 4);
    return input;
}

void    PhoneBook::add_contact() {

    int index = get_index();

    if (index == MAX_CONTACTS) {
        this->index = 0;
        index = 0;
    }
    contacts[index].set_firstname(get_input("First name"));
    contacts[index].set_lastname(get_input("Last name"));
    contacts[index].set_nickname(get_input("Nickname"));
    contacts[index].set_phone(get_input("Phone Number"));
    contacts[index].set_secret(get_input("Darkest secret"));
    this->index++;
    if (get_total() < 8)
        this->total++;
}

static void print_table_border(void)
{
    int i = -1;

    while (++i < 4)
        std::cout << "+----------";
    std::cout << "+\n";
}

static void    print_table_header(void)
{
    std::cout << "|";
    std::cout << setw(10) << "INDEX" << "|";
    std::cout << setw(10) << "F.NAME" << "|";
    std::cout << setw(10) << "L.NAME" << "|";
    std::cout << setw(10) << "N.NAME" << "|\n";
}

void    PhoneBook::list_contacts()
{
    int index = -1;
    int total = get_total();

    std::cout << "\nCONTACTS:\n";
    print_table_border();
    print_table_header();
    while (++index < total)
    {
        print_table_border();
        contacts[index].print_contact_as_table(index);
    }
    print_table_border();
    std::cout << setw(40) << "total: " << index << "/8\n";
}

void    PhoneBook::search_contact() {

    std::string index;

    if (contacts[0].is_empty() == 1) {
        std::cout << "The contact list is empty!\n";
        return ;
    }
    list_contacts();
    index = get_input("Entry's index");
    if (index.length() == 1 && isdigit(index[0]) && index[0] - '0' < MAX_CONTACTS)
        contacts[index[0] - '0'].print_contact();
    else
        std::cout << "[ERROR]: INVALID INDEX NUMBER\n";
}
