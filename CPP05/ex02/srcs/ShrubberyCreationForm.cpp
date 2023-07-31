/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:50:07 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 17:11:42 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_FORMNAME = "Shruberry Creation Form";

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : Form(_FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target("unknown") {}

// parameter constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form(_FORMNAME, _SIGNGRADE, _EXECUTEGRADE), _target(target) {}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
}

// assignment operator (overload)
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    // all the member data are either const or static const so no point of copy
    (void)other;
    return *this;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

static bool createWriteFile(std::fstream &file, std::string &fileName)
{
    file.open(fileName.c_str(), std::ios::out);
    if (file.is_open() == false)
        return false;
    return true;
}

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const
{
    std::fstream shruberryFile;
    std::string fileName = _target + "_shrubbery";

    if (createWriteFile(shruberryFile, fileName) == false)
    {
        std::cout << "[" << executor.getName() << "]: Ermm. That's awkward. I can't create a file. Try again later maybe?" << std::endl;
        return;
    }

    // write the shruberry tree into the file
    for (int i = 0; i < SHRUBERRY_TREE_LINE; i++)
        shruberryFile << SHRUBBERY_TREE[i] << std::endl;

    std::cout << "[" << executor.getName() << "]: Here you go. Check out this file: " << BPURPLE << fileName << RESET << std::endl;

    shruberryFile.close();
}
