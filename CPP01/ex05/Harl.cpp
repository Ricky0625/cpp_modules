/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:46:01 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 14:30:02 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void    Harl::debug() {
    std::cout << PPL << std::setw(10) << "[DEBUG] " << DFL
              << "Debugging is like being a detective in a crime movie where you are also the murderer." << std::endl;
}

void    Harl::info() {
    std::cout << BLU << std::setw(10) << "[INFO] " << DFL
              << "Information is power, but too much of it is just overwhelming." << std::endl;
}

void    Harl::warning() {
    std::cout << YLW << std::setw(10) << "[WARNING] " << DFL
              << "I'm not afraid of warnings. I just treat them like suggestions and ignore them like my boss's emails." << std::endl;
}

void    Harl::error() {
    std::cout << RED << std::setw(10) << "[ERROR] " << DFL
              << "I don't always write code, but when I do, I make sure it crashes spectacularly." << std::endl;
}

static void unknown() {
    std::cout << GRN << std::setw(10) << "[Harl2.0] " << DFL
              << "You think I know everything is it? 🙄" << std::endl;
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

void    Harl::complain(std::string level) {

    void    (Harl::*complainFunc)(void) = NULL;
    e_level levelCode = setComplain(level);

    switch (levelCode)
    {
        case DEBUG:
            complainFunc = &Harl::debug;
            break;
        case INFO:
            complainFunc = &Harl::info;
            break ;
        case WARNING:
            complainFunc = &Harl::warning;
            break ;
        case ERROR:
            complainFunc = &Harl::error;
            break ;
        default:
            unknown();
            break;
    }
    if (complainFunc != NULL)
        (this->*complainFunc)();
}
