/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:39 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:46:09 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): AAnimal()
{
	std::cout << "Cat: Default contructor is called\n";
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &other): AAnimal(other)
{
	std::cout << "Cat: Copy contructor is called\n";
	_type = "Cat";
	_brain = new Brain(*other._brain);
}

Cat & Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Assignment operator is called\n";
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain); // Deep copy te Brain
		this->_type = other._type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor is called\n";
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow! Meow! "<< std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}