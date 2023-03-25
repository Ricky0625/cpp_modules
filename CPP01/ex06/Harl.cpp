/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:46:01 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 15:40:06 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void    Harl::debug() {
    std::cout << PPL << "[ DEBUG ] " << DFL << std::endl
              << "Debugging is like being a detective in a crime movie where you are also the murderer.\n" << std::endl;
}

void    Harl::info() {
    std::cout << BLU << "[ INFO ] " << DFL << std::endl
              << "Information is power, but too much of it is just overwhelming.\n" << std::endl;
}

void    Harl::warning() {
    std::cout << YLW << "[ WARNING ]" << DFL << std::endl
              << "I'm not afraid of warnings. I just treat them like suggestions and ignore them like my boss's emails.\n" << std::endl;
}

void    Harl::error() {
    std::cout << RED << "[ ERROR ]" << DFL << std::endl
              << "I don't always write code, but when I do, I make sure it crashes spectacularly.\n" << std::endl;
}

static void unknown() {
    std::cout << "You think I know everything is it? 🙄" << std::endl;
}

static e_level  setComplain(std::string level)
{
    if (level == "DEBUG")
        return DEBUG;
    else if (level == "INFO")
        return INFO;
    else if (level == "WARNING")
        return WARNING;
    else if (level == "ERROR")
        return ERROR;
    return UNKNOWN;
}

/**
 * Without break statement, execution will continue to the next
 * case statement regardless of whether the current case statement
 * matches the value of levelCode. This is known as fall-through.
*/
void    Harl::complain(std::string level) {

    e_level levelCode = setComplain(level);

    switch (levelCode)
    {
        case DEBUG:
            Harl::debug();
        case INFO:
            Harl::info();
        case WARNING:
            Harl::warning();
        case ERROR:
            Harl::error();
            break ;
        default:
            unknown();
            break;
    }
}
