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

        Fixed               &operator=( const Fixed& fixed ); // assignment operator

        bool                operator>( const Fixed& rightOperand ) const;  // greater than
        bool                operator<( const Fixed& rightOperand ) const;  // less than
        bool                operator>=( const Fixed& rightOperand ) const; // greater and equal
        bool                operator<=( const Fixed& rightOperand ) const; // less and equal
        bool                operator==( const Fixed& rightOperand ) const; // equal
        bool                operator!=( const Fixed& rightOperand ) const; // not equal

        Fixed               operator+( const Fixed& rightOperand ); // addition
        Fixed               operator-( const Fixed& rightOperand ); // substraction
        Fixed               operator*( const Fixed& rightOperand ); // multiplication
        Fixed               operator/( const Fixed& rightOperand ); // division

        Fixed               operator++( void ); // pre-increment
        const Fixed         operator++( int );  // post-increment
        Fixed               operator--( void ); // pre-decrement
        const Fixed         operator--( int );  // post-decrement

        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );
        float               toFloat( void ) const;
        int                 toInt( void ) const;
        
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