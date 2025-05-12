/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:23:37 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	
	public:
		
		Point();
		Point(float x, float y);
		Point(int x, int y);
		Point(float x, int y);
		Point(int x, float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();
	
		Point getPoint(void) const;
		Fixed getX(void) const;
		Fixed getY(void) const;
	
};
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif