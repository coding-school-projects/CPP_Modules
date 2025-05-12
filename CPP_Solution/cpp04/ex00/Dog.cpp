/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:21:56 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default contructor is called\n";
	_type = "Dog";
}

Dog::Dog(Dog const &other): Animal(other)
{
	std::cout << "Dog: Copy contructor is called\n";
	_type = "Dog";
}

Dog & Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Assignment operator called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor is called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof\n";
}