/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:11:55 by wricky-t          #+#    #+#             */
/*   Updated: 2023/07/31 21:26:17 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>
# include "Color.hpp"

template <typename T, typename Func>
void    iter(T &arr, std::size_t len, const Func &callback)
{
    for (std::size_t i = 0; i < len; i++)
        callback(arr[i]);
}

template <typename T>
void    print(const T &element)
{
    std::cout << element << std::endl;
}

void    oddOrEven(int element)
{
    std::cout << element << " is " << (element % 2 == 0 ? "even." : "odd.") << std::endl;
}

void    meowSay(std::string &str)
{
    str += " ~ MEOW ~ ";    
}

void    tripleElement(int &element)
{
    element *= 3;
}

void    squareElement(int &element)
{
    element *= element;
}

template <typename T>
void colorize(const T &element)
{
    if (std::is_same<T, int>::value)
        std::cout << BGREEN << element << RESET << std::endl;
    else if (std::is_same<T, std::string>::value)
        std::cout << BYELLOW << element << RESET << std::endl;
    else if (std::is_same<T, double>::value)
        std::cout << BPURPLE << element << RESET << std::endl;
    else if (std::is_same<T, float>::value)
        std::cout << BRED << element << RESET << std::endl;
    else if (std::is_same<T, bool>::value)
        std::cout << BCYAN << element << RESET << std::endl;
    else
        std::cout << BGBLACK << element << RESET << std::endl;
}

#endif