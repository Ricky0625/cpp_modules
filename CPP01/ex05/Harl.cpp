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

// constructor
Harl::Harl(void) {}

// destructor
Harl::~Harl(void) {}

// DEBUG
void    Harl::debug() {
    std::cout << PPL << std::setw(10) << "[DEBUG] " << DFL
              << "Debugging is like being a detective in a crime movie where you are also the murderer." << std::endl;
}

// INFO
void    Harl::info() {
    std::cout << BLU << std::setw(10) << "[INFO] " << DFL
              << "Information is power, but too much of it is just overwhelming." << std::endl;
}

// WARNING
void    Harl::warning() {
    std::cout << YLW << std::setw(10) << "[WARNING] " << DFL
              << "I'm not afraid of warnings. I just treat them like suggestions and ignore them like my boss's emails." << std::endl;
}

// ERROR
void    Harl::error() {
    std::cout << RED << std::setw(10) << "[ERROR] " << DFL
              << "I don't always write code, but when I do, I make sure it crashes spectacularly." << std::endl;
}

// UNKWOWN
static void unknown() {
    std::cout << GRN << std::setw(10) << "[Harl2.0] " << DFL
              << "You think I know everything is it? 🙄" << std::endl;
}

// Set the level based on the given string
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
 * This function will call the appropriate function based on the given level.
 * The function to called is determined by the levelCode. The function will be
 * called using a pointer to member function.
*/
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
