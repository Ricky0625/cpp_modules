/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:00:24 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/16 16:19:04 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor
Span::Span() : _maxCapacity(0) {}

// parameter constructor
Span::Span(unsigned int N) : _maxCapacity(N) {}

// copy constructor
Span::Span(const Span &other) : _elements(other._elements), _maxCapacity(other._maxCapacity) {}

// assignment operator (overload)
Span    &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _elements = other._elements;
        _maxCapacity = other._maxCapacity;
    }
    return *this;
}

// destructor
Span::~Span() {}

const char *Span::SpanReachMaximumCapacityException::what() const throw() {
    return BRED "[EXCEPTION]: Span already reaches its maximum capacity!" RESET;
}

const char *Span::SpanNotEnoughElementException::what() const throw() {
    return BRED "[EXCEPTION]: Span doesn't have enough elements!" RESET;
}

const char *Span::NegativeDistanceBetweenIteratorsException::what() const throw() {
    return BRED "[EXCEPTION]: The distance between the given iterators is negative!" RESET;
}

const char *Span::SpanMayExceedMaximumCapacityException::what() const throw() {
    return BRED "[EXCEPTION]: Span will exceed maximum capacity during the process!" RESET;
}

/**
 * Add number into the vector
*/
void    Span::addNumber(const int& val)
{
    if (_elements.size() == _maxCapacity)
        throw Span::SpanReachMaximumCapacityException();
    _elements.push_back(val);
}

/**
 * Check if the distance between the given iterators is a positive value and greater than 0.
 * If it's negative, throw exception
 * If it's 0, return and do nothing
 * Also check if after insert this range of value, will it exceed the maximum capacity. In
 * that case, throw exception as well.
 * 
 * If every test above can pass, meaning it's ok to insert.
*/
void    Span::addMultiple(IntIterator start, IntIterator end)
{
    int distance = std::distance(start, end);

    if (distance < 0)
        throw Span::NegativeDistanceBetweenIteratorsException();
    else if (distance == 0) // nothing to do, just return
        return;
    else if ((_elements.size() + distance) > _maxCapacity)
        throw Span::SpanMayExceedMaximumCapacityException();
    
    // insert elements from a range of iterators into a vector
    _elements.insert(_elements.end(), start, end);
}


/**
 * Find the shortestSpan BETWEEN all the number stored.
 * Meaning that if I have (A, B, C, D, E), it would be calculated
 * as follows:
 * - between A and B
 * - between B and C
 * - between C and D
 * - between D and E
 * 
 * The operation to find the distance between them is minus.
 * So the idea is, create a copy of vector and sort it.
 * Sort it to ensures that adjacent elements in sorted sequence will
 * have the smallest differences.
 * Then calculate the distance between adjacent values.
 * These value need to be stored somewhere so that we can just
 * get min value using a builtin function.
 * 
 * A B C D E
 *   A B C D (minus) (this part is basically done by transform)
 *   X X X X (values)
 * 
 * min(values) -> shortest span
 * 
 * NOTES: copy a new vector so that sort won't modify the original vector
*/
long    Span::shortestSpan() const
{
    if (_elements.size() < 2)
        throw Span::SpanNotEnoughElementException();
    
    std::vector<long> copy(_elements.size());
    std::copy(_elements.begin(), _elements.end(), copy.begin());
    std::sort(copy.begin(), copy.end());

    std::vector<long> dist(_elements.size() - 1);
    std::transform(copy.begin() + 1, copy.end(), copy.begin(), dist.begin(), std::minus<long>());

    return *std::min_element(dist.begin(), dist.end());
}

/**
 * Finding longest span is relatively easier than finding shortest span.
 * Just get the max element - min element.
 * Keep in mind that the variable min and max need to be in long
*/
long    Span::longestSpan() const
{
    if (_elements.size() < 2)
        throw Span::SpanNotEnoughElementException();

    long min = *std::min_element(_elements.begin(), _elements.end());
    long max = *std::max_element(_elements.begin(), _elements.end());
    return (max - min);
}

/**
 * Helper function to show elements
*/
void    Span::showElements() const
{
    std::vector<int>::const_iterator it;

    std::cout << "[ELEMENT]: ";
    for (it = _elements.cbegin(); it != _elements.cend(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
