/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:01 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:05:47 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i){
		_materias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		delete _materias[i];
		_materias[i] = other._materias[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
	{
		delete _materias[i];
		_materias[i] = other._materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _materias[i];
		_materias[i] = nullptr;
	}
}

void MateriaSource::learnMateria(AMateria* m_name)
{
	for(int i=0; i<4; i++)
	{
		if (_materias[i] == nullptr)
		{
			_materias[i] = m_name;
			break;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i=0; i<4;i++)
	{
		if (_materias[i]->getType() == type)
		{
			return _materias[i]->clone();
		}
	}
	return nullptr;
}