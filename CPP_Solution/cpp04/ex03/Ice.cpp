/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:47 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:09:37 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice():AMateria("ice") {}

Ice::Ice(const Ice& other):AMateria(other) {}

Ice& Ice::operator=(const Ice& other)
{
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {}

std::string const&	Ice::getType() const
{
	return this->_type;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "\t* shoots an ice bolt at " << target.getName() << " *\n";
}
