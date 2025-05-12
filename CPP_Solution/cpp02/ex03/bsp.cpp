/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:31 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:40:56 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed areaOfTriangle(const Fixed &x1, const Fixed &y1, const Fixed &x2, const Fixed &y2, const Fixed &x3, const Fixed &y3)
{
	Fixed result=(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)).abs() / 2;
	return result;
}



bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	
	Fixed triangleArea = areaOfTriangle(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());

	Fixed pointTriangleA = areaOfTriangle(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY()).abs();
	Fixed pointTriangleB = areaOfTriangle(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY()).abs();
	Fixed pointTriangleC = areaOfTriangle(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY()).abs();

	return (triangleArea == pointTriangleA + pointTriangleB + pointTriangleC);
}
