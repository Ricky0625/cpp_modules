/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:38:16 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/28 20:53:11 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"

// Constructor
template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(Iterator base, size_t size) : _base(base), _size(size) {}

template <typename Iterator>
GroupIterator<Iterator>::GroupIterator(GroupIterator start, size_t size) : _size(size)
{
    _base = start._base;
}

// Assignation
template <typename Iterator>
GroupIterator<Iterator> &GroupIterator<Iterator>::operator=(const GroupIterator &src)
{
    if (this == &src)
        return *this;
    _base = src._base;
    _size = src._size;
    return *this;
}

// Pre-increment
template <typename Iterator>
GroupIterator<Iterator> &GroupIterator<Iterator>::operator++()
{
    _base += _size;
    return *this;
}

// Pre-decrement
template <typename Iterator>
GroupIterator<Iterator> &GroupIterator<Iterator>::operator--()
{
    _base -= _size;
    return *this;
}

// Comparision (not equal)
template <typename Iterator>
bool GroupIterator<Iterator>::operator!=(const GroupIterator &other) const
{
    return _base != other._base;
}

// Derefence group iterator, get the last element of the group
template <typename Iterator>
typename Iterator::value_type GroupIterator<Iterator>::operator*() const
{
    return _base[_size - 1];
}

template <typename Iterator>
GroupIterator<Iterator> GroupIterator<Iterator>::operator+(size_t n) const
{
    return GroupIterator<Iterator>(_base + (_size * n), _size);
}

template <typename Iterator>
GroupIterator<Iterator> GroupIterator<Iterator>::operator-(size_t n) const
{
    return GroupIterator<Iterator>(_base - (_size * n), _size);
}

template <typename Iterator>
GroupIterator<Iterator> &GroupIterator<Iterator>::operator+=(size_t n)
{
    std::advance(_base, n * _size);
    return *this;
}

template <typename Iterator>
GroupIterator<Iterator> &GroupIterator<Iterator>::operator-=(size_t n)
{
    std::advance(_base, -n * _size);
    return *this;
}


template <typename Iterator>
Iterator GroupIterator<Iterator>::base() const
{
    return _base;
}

template <typename Iterator>
size_t GroupIterator<Iterator>::size() const
{
    return _size;
}

template <typename Iterator>
size_t GroupIterator<Iterator>::distance(GroupIterator &dest)
{
    if (dest._base < this->_base)
        return 0;
    return (dest._base - this->_base) / _size;
}

template <typename Iterator>
void swapRange(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs)
{
    std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}
