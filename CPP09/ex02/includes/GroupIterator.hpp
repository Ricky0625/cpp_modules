/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:39:04 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/28 20:52:14 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPITERATOR_HPP
#define GROUPITERATOR_HPP

#include <iostream>
#include <iterator>

template <typename Iterator>
class GroupIterator
{
public:
    GroupIterator(void);
    GroupIterator(Iterator base, size_t size);
    GroupIterator(GroupIterator base, size_t size);

    // operator overload
    GroupIterator &operator=(const GroupIterator &src); // assignation
    GroupIterator &operator++(void);                    // pre-increment, move forward to next group
    GroupIterator &operator--(void);                    // pre-decrement, move backward to previous group
    bool operator!=(const GroupIterator &it) const;     // comparison, not equal
    typename Iterator::value_type operator*() const;    // dereference
    GroupIterator operator+(size_t n) const;            // addition
    GroupIterator operator-(size_t n) const;            // substration
    GroupIterator &operator+=(size_t n);
    GroupIterator &operator-=(size_t n);

    // member access
    Iterator base(void) const;
    size_t size(void) const;

    // helpers
    size_t distance(GroupIterator &dest);

private:
    Iterator _base;
    size_t _size;
};

template <typename Iterator>
void swapRange(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs);

#include "GroupIterator.tpp"

#endif
