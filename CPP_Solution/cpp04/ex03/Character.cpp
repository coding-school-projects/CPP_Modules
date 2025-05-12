/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:36 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:55:06 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name):_name(name)
{
	for (int i=0; i<4; i++)
		_materias[i] = nullptr;
}

Character::Character(const Character& other):ICharacter(other)
{
	for (int i=0; i<4; i++)
	{
		if (other._materias[i] != nullptr)
		{
			_materias[i] = other._materias[i]->clone();
		}
		else
			_materias[i] = nullptr;
	}
	_name = other._name;
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return *this;
	ICharacter::operator=(other);
	for (int i=0; i<4; i++)
	{
		if (_materias[i] != nullptr)   // clean the local member
		{
			delete _materias[i];
			_materias[i] = nullptr;
		}
	}
	for (int i=0; i<4; i++)
	{
		if (other._materias[i] != nullptr)
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = nullptr;
	}
	_name = other._name;
	return *this;
}

Character::~Character()
{
	for (int i=0; i<4; i++)
		delete _materias[i];
}


std::string const& Character::getName() const
{
	return _name;
}
void Character::equip(AMateria* m)
{
	for (int i=0; i<4; i++)
	{
		if (_materias[i] == nullptr)
		{
			_materias[i] = m;
			break;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx >=0 && idx < 4)
		_materias[idx] == nullptr;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >=0 && idx < 4)
		_materias[idx]->use(target);
}
