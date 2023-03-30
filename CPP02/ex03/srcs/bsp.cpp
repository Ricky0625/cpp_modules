/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wricky-t <wricky-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:24:00 by wricky-t          #+#    #+#             */
/*   Updated: 2023/03/29 17:58:37 by wricky-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Check if the point is on one of the line (y = mx + c)
 * @details
 * Slope = (y2 - y1) / (x2 - x1)
 * y-intercept (c) = y - mx
*/
static bool    isOnLine(Point const a, Point const b, Point const point) {
    float   slope, y_intercept, res;

    slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
    y_intercept = a.getY() - (slope * a.getX());
    res = (slope * point.getX()) + y_intercept;
    return (point.getY() == res);
}

/**
 * @brief Calculate area of a triangle with three vertices
*/
static float   getArea(Point const a, Point const b, Point const c) {
    float   determinant;

    determinant = (a.getX() * (b.getY() - c.getY()))
                  + (b.getX() * (c.getY() - a.getY()))
                  + (c.getX() * (a.getY() - b.getY()));
    determinant = determinant / 2;
    return (determinant < 0) ? determinant * -1 : determinant;
}

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    float   abcArea, abpArea, acpArea, bcpArea, allRegionArea;

    abcArea = getArea(a, b, c);
    abpArea = getArea(a, b, point);
    acpArea = getArea(a, c, point);
    bcpArea = getArea(b, c, point);
    allRegionArea = abpArea + acpArea + bcpArea;
    if (allRegionArea != abcArea
        || (isOnLine(a, b, point) || isOnLine(a, c, point) || isOnLine(b, c, point)))
        return false;
    return true;
}
