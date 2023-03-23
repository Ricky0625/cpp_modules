/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:23 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/23 20:44:46 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

/**
 * str, stringPTR & stringREF all refer to the same string object, but they
 * have different types and different ways of accessing the object.
 * 
 * 1. str is a string object. It is defined and initialized to the given string
 *    using the string literal syntax. We can access the value of string directly
 *    using the variable name, str.
 * 2. stringPTR is a pointer to a string. It needs to be defined and initialized
 *    to the address of a string using the '&' operator. We can access the value
 *    of the string by dereferencing the pointer using the '*' operator.
 * 3. stringREF is a reference to a string. It is defined and initialized to refer
 *    to 'str'. We can access the value of the string using the reference, stringREF.
 *    Unlike pointers, we don't need to dereference the reference to access the
 *    value of the object it refers to.
 * 
 * A. str is a value, while stringPTR and stringREF are references. Meaning 'str'
 * has its own memory address and stores the value directly, while the other
 * two only refer to the memory address of a string object.
 * 
 * B. stringPTR is a pointer, while stringREF is a reference. We can change the
 * memory address that stringPTR points to, but we cannot change the memory
 * address that stringREF refers to. Once we initialize stringREF, it will always
 * refer to 'str' throughout its lifetime.
 * 
 * Difference between reference and a pointer:
 * - Pointer can be re-assigned to point to a different memory address
 * - Reference cannot be re-assigned to refer to a different variable, it will
 *   still refer to the same address.
*/

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // Print memory address
    std::cout << " ====== MEMORY ADDRESSES ======\n"
              << std::setw(15) << "str: " << &str << "\n"
              << std::setw(15) << "stringPTR: " << stringPTR << "\n"
              << std::setw(15) << "stringREF: " << &stringREF << "\n";
    // Print value
    std::cout << " =========== VALUES ===========\n"
              << std::setw(15) << "str: " << str << "\n"
              << std::setw(15) << "stringPTR: " << *stringPTR << "\n"
              << std::setw(15) << "stringREF: " << stringREF << "\n";
    
    std::string newStr = "HELLO FROM LIVER";
    stringPTR = &newStr;
    // use reference to re-assign the value of str
    stringREF = newStr;
    // Print memory address
    // Notice that the address of str and stringREF still the same but value different
    std::cout << " ====== MEMORY ADDRESSES ======\n"
              << std::setw(15) << "str: " << &str << "\n"
              << std::setw(15) << "newStr: " << &newStr << "\n"
              << std::setw(15) << "stringPTR: " << stringPTR << "\n"
              << std::setw(15) << "stringREF: " << &stringREF << "\n";
    // Print value
    std::cout << " =========== VALUES ===========\n"
              << std::setw(15) << "str: " << str << "\n"
              << std::setw(15) << "newStr: " << newStr << "\n"
              << std::setw(15) << "stringPTR: " << *stringPTR << "\n"
              << std::setw(15) << "stringREF: " << stringREF << "\n";

    return (0);
}
