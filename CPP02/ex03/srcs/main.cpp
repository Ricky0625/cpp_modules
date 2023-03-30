/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:07:03 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 18:02:52 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

std::string evaluate(bool res) {
    return (res == true) ? "TRUE" : "FALSE";
}

int main(void) {
    
    {
        // Point inside triangle
        Point   a( 1, 1 );
        Point   b( 4, 2 );
        Point   c( 2, 7 );
        Point   point( 2, 3 );
        std::cout << evaluate(bsp(a, b, c, point)) << std::endl;
    }

    {
        // Point outside of triangle
        Point   a( 15, 20 );
        Point   b( 6, 4 );
        Point   c( 10, -10 );
        Point   point( 16, 10 );
        std::cout << evaluate(bsp(a, b, c, point)) << std::endl;
    }

    {
        // The given coordinates cannot form a triangle
        Point   a( 4, 16 );
        Point   b( 11, 23 );
        Point   c( 7, 19 );
        Point   point( 5, 18 );
        std::cout << evaluate(bsp(a, b, c, point)) << std::endl;
    }

    {
        // Another test case
        Point   a( -3, 4 );
        Point   b( 1, -2 );
        Point   c( 5, 5 );
        Point   point( 3, 3 );
        std::cout << evaluate(bsp(a, b, c, point)) << std::endl;
    }

    {
        // Point is on one of the line
        Point   a( 12, 17 );
        Point   b( 11, 23 );
        Point   c( 7, 19 );
        Point   point( 9.5, 18 );
        std::cout << evaluate(bsp(a, b, c, point)) << std::endl;
    }
}
