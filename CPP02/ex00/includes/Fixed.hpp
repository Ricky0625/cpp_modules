/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:32:58 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/25 21:08:32 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed( void );
        Fixed( int a, int b );
        Fixed( const Fixed& fixed );
        Fixed &operator=(const Fixed& fixed);
        ~Fixed( void );
        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );
    private:
        int                 _fixed;
        static const int    _fractBits;
};

#endif