/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:16:48 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 16:46:40 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& point) : _x(point._x), _y(point._y) {}

Point::~Point(void) {}

Point   &Point::operator=(const Point& point) {
    if (this != &point)
        *this = point;
    return *this;
}

float   Point::getX(void) const{
    return (this->_x).toFloat();
}

float   Point::getY(void) const{
    return (this->_y).toFloat();
}
