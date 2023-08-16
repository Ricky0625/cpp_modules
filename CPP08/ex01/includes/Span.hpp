/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:47:41 by wricky-t          #+#    #+#             */
/*   Updated: 2023/08/16 16:01:24 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include "Color.hpp"

typedef std::vector<int>::iterator IntIterator;

class Span {
    public:
        Span( void );
        Span( unsigned int N );
        ~Span( void );
        Span( const Span &other );
        Span	&operator=( const Span &other );

        // necessary member function
        void    addNumber( const int &val );
        void    addMultiple( IntIterator start, IntIterator end);
        long    shortestSpan( void ) const; // need to be aware of int MIN/MAX
        long    longestSpan( void ) const; // need to be aware of int MIN/MAX

        // helper function
        void    showElements( void ) const;

        // exceptions
        class SpanReachMaximumCapacityException : public std::exception {
            const char *what() const throw();
        };
        class SpanNotEnoughElementException : public std::exception {
            const char *what() const throw();
        };
        class NegativeDistanceBetweenIteratorsException : public std::exception {
            const char *what() const throw();
        };
        class SpanMayExceedMaximumCapacityException : public std::exception {
            const char *what() const throw();
        };

    private:
        std::vector<int>    _elements;
        unsigned int        _maxCapacity;
};

#endif
