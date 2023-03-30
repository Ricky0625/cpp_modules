/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:12:48 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:29 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public:
        Point( void );
        Point( const float x, const float y );
        Point( const Point& point );
        ~Point( void );

        Point   &operator=( const Point& point );
    
        float   getX( void ) const;
        float   getY( void ) const;
    private:
        const Fixed _x;
        const Fixed _y;
};

#endif
