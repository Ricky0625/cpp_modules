/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:46:17 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/26 15:23:35 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// default constructor
Brain::Brain()
{
    ideas = new std::string[MAX_IDEA];
    std::cout << "🧠 Brain created" << std::endl;
}

// copy constructor
Brain::Brain(const Brain &other) : ideas(NULL)
{
    *this = other;
    std::cout << "🧠 Brain copied" << std::endl;
}

// assignment operator (overload)
Brain &Brain::operator=(const Brain &other)
{
    // check for self-assignment
    if (this == &other)
        return *this;

    // free the existing resource (dynamic memory)
    delete[] ideas;

    // perform deep copy
    if (other.ideas != NULL)
    {
        ideas = new std::string[MAX_IDEA];
        for (int i = 0; i < MAX_IDEA; i++)
            ideas[i] = other.ideas[i];
    }
    else
        ideas = NULL;
    std::cout << "🧠 Brain's assignment operator called" << std::endl;
    return *this;
}

// destructor
Brain::~Brain()
{
    // deallocate the dynamic memory
    delete[] ideas;
    std::cout << "🧠 Brain destroyed" << std::endl;
}

// set idea
void    Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < MAX_IDEA)
        ideas[index] = idea;
}

// get idea
std::string &Brain::getIdea(int index) const
{
    if (index >= 0 && index < MAX_IDEA)
        return ideas[index];
    return ideas[0];
}
