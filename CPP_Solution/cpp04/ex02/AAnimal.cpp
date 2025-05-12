/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:43 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:42:35 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal():_type("AAnimal")
{
	std::cout << "AAnimal: Default contructor is called\n";
}

AAnimal::AAnimal(AAnimal const &other):_type(other._type)
{
	std::cout << "AAnimal: Copy contructor is called\n";
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal: Assignment operator is called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Default destructor is called\n";
}

std::string AAnimal::getType() const
{
	return (_type);
}
