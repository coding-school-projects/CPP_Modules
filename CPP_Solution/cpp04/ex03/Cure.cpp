/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:41 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:09:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure():AMateria("cure") {}

Cure::Cure(const Cure& other):AMateria(other) {}

Cure& Cure::operator=(const Cure& other)
{
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {}

std::string const&	Cure::getType() const
{
	return this->_type;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "\t* heals " << target.getName() << "'s wounds *\n";
}