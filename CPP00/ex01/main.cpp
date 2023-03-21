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
 * 1. Need an infinite loop that ask for user's prompt.
 * 2. The prompt should be all UPPERCASE only.
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
            phonebook.add_contact();
        else if (prompt == "SEARCH")
            phonebook.search_contact();
        else if (prompt == "EXIT" || std::cin.eof())
            break ;
        else {
            std::cout << "\t" << (prompt.empty() ? "EMPTY COMMAND!" : "INVALID COMMAND!");
            phonebook.show_cmds();
        }
    }
    return 0;
}
