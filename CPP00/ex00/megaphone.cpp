/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:19:58 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/21 11:19:59 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void megaphone(char *str)
{
    int i = -1;

    while (str[++i] != '\0')
        std::cout << (char)toupper(str[i]);
}

/**
 * @note
 * In C++, using "\n" instead of "endl" can be more efficient in
 * terms of performance because "endl" does more than just insert
 * a newline character. It actually inserts a newline and flushes
 * the output buffer, which can be an expensive operation.
 * 
 * (The difference will be obvious when outputting large amount
 * of characters.)
 * 
 * When using "\n", the newline character is simply inserted into
 * the output stream, and the output buffer is not immediately
 * flushed but is flushed at a later time, such as when the buffer
 * becomes full or when the stream is closed.
*/

int main(int ac, char **av) {

    int i = 0;

    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    else {
        while (++i < ac)
            megaphone(av[i]);
        std::cout << "\n";
    }
}
