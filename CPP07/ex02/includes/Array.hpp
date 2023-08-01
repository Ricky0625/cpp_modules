/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:35:07 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/01 15:30:20 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
    Array(void);                           // creates an empty array
    Array(unsigned int n);                 // creates an array of n elements
    ~Array(void);                          // free allocated memory
    Array(const Array &other);             // creates a copy of another array
    Array &operator=(const Array &other);  // assign value of another array to current array
    T &operator[](unsigned int idx) const; // return a reference to T type

    unsigned int size(void) const; // get the size of the array

    // exception
    class IndexOutOfBoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    unsigned int _size;
    T *_arr;
};

#include "Array.tpp"

#endif
