/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:32:58 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/28 16:32:55 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        // constructor and destructor
        Fixed( void );
        Fixed( const int );
        Fixed( const float );
        Fixed( const Fixed& fixed );
        ~Fixed( void );

        // copy assignment operator
        Fixed   &operator=( const Fixed& fixed ); // assignment operator

        // comparison operators
        bool    operator>( const Fixed& other ) const;  // greater than
        bool    operator<( const Fixed& other ) const;  // less than
        bool    operator>=( const Fixed& other ) const; // greater and equal
        bool    operator<=( const Fixed& other ) const; // less and equal
        bool    operator==( const Fixed& other ) const; // equal
        bool    operator!=( const Fixed& other ) const; // not equal

        // arithmetic operators
        Fixed   operator+( const Fixed& other ) const; // addition
        Fixed   operator-( const Fixed& other ) const; // substraction
        Fixed   operator*( const Fixed& other ) const; // multiplication
        Fixed   operator/( const Fixed& other ) const; // division

        // increment and decrement operators
        Fixed&  operator++( void ); // pre-increment
        Fixed   operator++( int );  // post-increment
        Fixed&  operator--( void ); // pre-decrement
        Fixed   operator--( int );  // post-decrement

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        
        static Fixed&       min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed&       max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

    private:
        int                 _fixed;
        static const int    _fractBits;
};

std::ostream   &operator<<(std::ostream& os, const Fixed& fixed);

#endif