/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:06 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:25:36 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat: Default contructor is called\n";
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal(other)
{
	std::cout << "WrongCat: Copy contructor is called\n";
	_type = "WrongCat";
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat: Operator = is called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Default destructor is called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Sound! " << std::endl;
}