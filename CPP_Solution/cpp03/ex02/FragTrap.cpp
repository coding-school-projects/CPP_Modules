/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:01:47 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:25:21 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

// Constructor with name parameter
FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created with " << _hitPoints << " hitPoints, " << _energyPoints << " energyPoints, and " << _attackDamage << " attackDamage." << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " copied." << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& src)
{
    if (this != &src)
	{
        ClapTrap::operator=(src);
    }
    std::cout << "FragTrap " << _name << " assigned." << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " <<_name << " is destroyed." <<std::endl;
}

// High fives guys function
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " requests high fives from everyone!" << std::endl;
}
