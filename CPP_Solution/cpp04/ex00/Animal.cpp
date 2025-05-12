/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:43 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:27:11 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal: Default contructor is called\n";
}

Animal::Animal(Animal const &other): _type(other._type)
{
	std::cout << "Animal: Copy contructor is called\n";
}

Animal & Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Assignment operator called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Default destructor is called\n";
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound\n";
}