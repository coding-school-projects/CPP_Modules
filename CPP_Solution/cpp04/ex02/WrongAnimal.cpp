/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:51 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:48:18 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default contructor is called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other): _type(other._type)
{
	std::cout << "WrongAnimal: Copy contructor is called\n";
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: Assignment operator is called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Default destructor is called\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound\n";
}