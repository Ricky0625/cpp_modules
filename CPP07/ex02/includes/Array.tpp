/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:58:06 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/01 15:42:08 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/**
 * @brief Constructor - Create an empty array
 *
 * Ok. Why not just set arr to NULL? Isn't new T[0] and NULL the same thing?
 * Apparently, they are not. The first thing that you can notice is that the later
 * one is using `new` keywords which is to allocate memory. It's actually
 * allocating an array of integers with size zero. This array will not have any
 * elements, and has minimal memory footprint (usually just enough to hold the
 * bookkeeping information for the allocation). Hence, new T[0] actually will
 * cause memory leaks if you didn't delete[] it.
 *
 * For setting arr to NULL, it's different. It literally means that pointer
 * does not point to any valid memory location. It does not point to an array,
 * and you cannot access or modify any elements through this pointer.
 *
 * To summarize, new T[0] will allocate memory while setting it to NULL won't.
 * You are not suppose to access the element using both method. It's undefined
 * behavior.
 */
template <typename T>
Array<T>::Array() : _size(0), _arr(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size), _arr(new T[other._size])
{
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{   
    // delete the allocated memory first
    delete[] _arr;
    
    // setting member data
    _size = other._size;

    // allocate new memory
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) const
{
    if (idx < 0 || idx >= _size)
        throw IndexOutOfBoundException();
    return _arr[idx];
}

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
    return "[ARRAY]: Index out of bound!";
}

// destructor: delete all the allocated memory
template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
