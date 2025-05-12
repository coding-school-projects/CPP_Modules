/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:42 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:24:46 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point () : _x(0), _y(0) {}

Point::~Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const int x, const int y) : _x(x), _y(y) {}

Point::Point(const float x, const int y) : _x(x), _y(y) {}

Point::Point(const int x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) 
{
	*this = other;
}

Point& Point::operator=(const Point& other) 
{
	if (this != &other)
	{
		//Fixed members are const, no modification
	}
	return *this;
}

Point Point::getPoint(void) const
{
	return *this;
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}