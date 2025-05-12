/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:39 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:20:59 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	std::cout << "Cat: Default contructor is called\n";
	_type = "Cat";
}

Cat::Cat(Cat const &other): Animal(other)
{
	std::cout << "Cat: Copy contructor is called\n";
	_type = "Cat";
}

Cat & Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Assignment operator called\n";
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor is called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow! "<< std::endl;
}