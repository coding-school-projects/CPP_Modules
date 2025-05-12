/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:39 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/09 11:35:54 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ( void ) 
{
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(1, 1) ) == true ) 
	{
		std::cout << "Triangle A(0, 0), B(10, 30), C(20, 0)" << std::endl;
		std::cout << "Point P(1, 1)" << std::endl;
		std::cout << "P is in the triangle of ABC" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "Triangle A(0, 0), B(10, 30), C(20, 0)" << std::endl;
		std::cout << "Point P(1, 1)" << std::endl;
		std::cout << "P is not in the triangle of ABC" << std::endl << std::endl;
	}

	if ( bsp( Point(0, 0), Point(10.0f, 30), Point(20, 0), Point(-0.1f, 0) ) == true ) 
	{
		std::cout << "Triangle A(0, 0), B(10.0f, 30), C(20, 0)" << std::endl;
		std::cout << "Point P(-0.1f, 0)" << std::endl;
		std::cout << "P is in the triangle of ABC" << std::endl << std::endl;
	} 
	else
	{
		std::cout << "Triangle A(0, 0), B(10.0f, 30), C(20, 0)" << std::endl;
		std::cout << "Point P(-0.1f, 0)" << std::endl;
		std::cout << "P is not in the triangle of ABC" << std::endl;
	}
	return 0;
}