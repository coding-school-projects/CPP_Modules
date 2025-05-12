/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:31:48 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:50:08 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain: default constractor is called\n";
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = "";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: Copy contructor is called\n";
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain: Assignemnt operator is called\n";
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: destructor is called\n";
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
	{
        _ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
	{
        return _ideas[index];
    }
    return "";
}