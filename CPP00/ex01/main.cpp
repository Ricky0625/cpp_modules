/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:22:25 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 18:12:53 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief PhoneBook
 * 
 * @details
 * 1. Get user input, expect one of the following commands:
 *  - ADD: Add new contact.
 *  - SEARCH: Look up a contact.
 *  - EXIT: Exit PhoneBook.
 * 2. If the command is ADD, call addContact() method.
 * 3. If the command is SEARCH, call searchContact() method.
 * 4. If the command is EXIT, destructor will be called and exit the program.
 * 5. If the command is invalid, show error message and showCmds().
*/
int main(void)
{
    PhoneBook   phonebook;
    std::string prompt;

    while (1)
    {
        std::cout << BCYAN << "PhoneBook > " << DEF;
        std::getline(std::cin, prompt);
        if (prompt == "ADD")
            phonebook.addContact();
        else if (prompt == "SEARCH")
            phonebook.searchContact();
        else if (prompt == "EXIT" || std::cin.eof())
            break ;
        else {
            std::cout << "\t" << (prompt.empty() ? "EMPTY COMMAND!" : "INVALID COMMAND!");
            phonebook.showCmds();
        }
    }
    return 0;
}
