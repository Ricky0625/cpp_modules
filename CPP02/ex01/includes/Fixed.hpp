/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:32:58 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/27 18:28:46 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    public:
        Fixed( void );
        Fixed( const int );
        Fixed( const float );
        Fixed( const Fixed& other );
        ~Fixed( void );

        Fixed &operator=(const Fixed& other);

        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );
        float               toFloat( void ) const;
        int                 toInt( void ) const;
    private:
        int                 _fixed;
        static const int    _fractBits;
};

std::ostream   &operator<<(std::ostream& os, const Fixed& fixed);

#endif
