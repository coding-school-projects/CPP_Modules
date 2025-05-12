/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:38:59 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	std::cout << "Dog: Default contructor is called\n";
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const &other): Animal(other)
{
	std::cout << "Dog: Copy contructor is called\n";
	_type = "Dog";
	_brain = new Brain(*other._brain);
}

Dog & Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Assignment operator is called\n";
	if (this != &other)
	{
		Animal::operator=(other);	// Assign base class members
		delete _brain;
		this->_type = other._type;
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: Default destructor is called\n";
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof! " << std::endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}