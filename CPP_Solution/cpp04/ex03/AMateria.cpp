/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:28 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:53:24 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type): _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " uses AMateria " << _type << std::endl;
}