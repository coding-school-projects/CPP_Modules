/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:06:28 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:26:28 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// Constructor with name parameter
ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created with " << _hitPoints << " hitPoints, " << _energyPoints << " energyPoints, and " << _attackDamage << " attackDamage." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src)
	{
        ClapTrap::operator=(src);
    }
    std::cout << "ScavTrap " << _name << " assigned." << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " <<_name << " is destroyed." <<std::endl;
}

// Attack function
void ScavTrap::attack(const std::string &target)
{
    
    if (_hitPoints > 0 && _energyPoints > 0)
	{
        std::cout << "ScavTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } 
	else if (_hitPoints <= 0)
	{
        std::cout << "ScavTrap " << _name << " is out of hitPoints and can't attack." << std::endl;
    } 
	else if (_energyPoints <= 0)
	{
        std::cout << "ScavTrap " << _name << " has no energy left to attack." << std::endl;
    }
}

// Guard gate function
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

