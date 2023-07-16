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

// PhoneBook constructor. Initializes attributes using initializer list.
PhoneBook::PhoneBook() : _index(0), _total(0) {}

// PhoneBook destructor.
PhoneBook::~PhoneBook() {
    std::cout << "\nBye bye~ Thanks for using PhoneBook.\n";
}

// Getters: Get index number
int PhoneBook::getIndex() const {
    return _index;
}

// Getters: Get total number of contacts
int PhoneBook::getTotal() const {
    return _total;
}

// Helper: Show all the available commands for PhoneBook
void   PhoneBook::showCmds() {
    std::cout << "\n\tHere are the list of commands (case-sensitive):\n";
    std::cout << left << setw(7) << "\tADD" << "| Add new contact.\n";
    std::cout << left << setw(7) << "\tSEARCH" << "| Look up a contact.\n";
    std::cout << left << setw(7) << "\tEXIT" << "| Exit PhoneBook.\n";
}

// Helper: Replace tabs to spaces
static std::string replaceTabs(const std::string str, int spacesPerTab)
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

/**
 * @brief Get user input
 * 
 * @details
 * 1. Get user input using std::getline().
 * 2. If the input is empty, continue to get user input.
 * 3. If the input is not empty, replace tabs to spaces and return the input.
 * 
 * @attention
 * If the tabs are not replaced, the table will be broken.
*/
std::string getInput(std::string prompt) {

    std::string input;

    while (true)
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "\n[ERROR]: INTERRUPTED!\n";
            std::exit(EXIT_FAILURE);
        }
        else if (input.empty() == true) {
            continue ;
        }
        else
            break ;
    }
    input = replaceTabs(input, 4);
    return input;
}

/**
 * @brief Add contact
 * 
 * @details
 * 1. Since the _index will be incremented after adding a contact, check if the
 *    _index is equal to MAX_CONTACTS. If it is, reset the _index to 0. This will
 *    overwrite the oldest contact.
 * 2. Get user input for each attribute of the contact.
 * 3. Only when the contact list is not full, increment the _total.
*/
void    PhoneBook::addContact() {

    int currentIndex = getIndex();

    if (currentIndex == MAX_CONTACTS) {
        _index = 0;
        currentIndex = 0;
    }
    contacts[currentIndex].setFirstname(getInput("First name"));
    contacts[currentIndex].setLastname(getInput("Last name"));
    contacts[currentIndex].setNickname(getInput("Nickname"));
    contacts[currentIndex].setPhone(getInput("Phone Number"));
    contacts[currentIndex].setSecret(getInput("Darkest secret"));
    _index++;
    if (getTotal() < 8)
        _total++;
}

// Helper: Print table border
static void printTableBorder(void)
{
    int i = -1;

    while (++i < 4)
        std::cout << "+----------";
    std::cout << "+\n";
}

// Helper: Print table header
static void    printTableHeader(void)
{
    std::cout << "|";
    std::cout << setw(10) << "INDEX" << "|";
    std::cout << setw(10) << "F.NAME" << "|";
    std::cout << setw(10) << "L.NAME" << "|";
    std::cout << setw(10) << "N.NAME" << "|\n";
}

// List the contacts in a table
void    PhoneBook::listContacts()
{
    int index = -1;
    int total = getTotal();

    std::cout << "\nCONTACTS:\n";
    printTableBorder();
    printTableHeader();
    while (++index < total)
    {
        printTableBorder();
        contacts[index].printContactAsTable(index);
    }
    printTableBorder();
    std::cout << setw(40) << "total: " << index << "/8\n";
}

/**
 * @brief Search contact
 * 
 * @details
 * 1. If the contact list is empty, show error message and return.
 * 2. Show all the contacts in a table if the contact list is not empty.
 * 3. Get user input, expect a valid index number.
 *    If it's valid, print the contact. Else, show error message.
*/
void    PhoneBook::searchContact() {

    std::string index;

    if (contacts[0].isEmpty() == 1) {
        std::cout << "The contact list is empty!\n";
        return ;
    }
    listContacts();
    index = getInput("Entry's index");
    if (index.length() == 1 && isdigit(index[0]) && index[0] - '0' < getTotal())
        contacts[index[0] - '0'].printContact();
    else
        std::cout << "[ERROR]: INVALID INDEX NUMBER\n";
}
