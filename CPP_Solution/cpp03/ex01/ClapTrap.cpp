/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:00:55 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:04:37 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// Constructor with name parameter
ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created with " << _hitPoints << " hitPoints, " << _energyPoints << " energyPoints, and " << _attackDamage << " attackDamage." << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    if (this != &src)
	{
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " assigned." << std::endl;
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

// Attack function
void ClapTrap::attack(const std::string &target)
{
	 if (_hitPoints > 0 && _energyPoints > 0)
	{
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } 
	else if (_hitPoints <= 0)
	{
        std::cout << "ClapTrap " << _name << " is out of hitPoints and can't attack." << std::endl;
    } 
	else if (_energyPoints <= 0)
	{
        std::cout << "ClapTrap " << _name << " has no energy left to attack." << std::endl;
    }
}

// Take damage function
void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    if (_hitPoints < 0)
		_hitPoints = 0; // Hit points can't be negative
	std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! " << "Hit points left: " << _hitPoints << std::endl;
}

// Be repaired function
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
	{
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hitPoints. " << "Hit points now: " << _hitPoints << std::endl;
        _energyPoints--;
    }
	else if (_hitPoints <= 0)
	{
        std::cout << "ClapTrap " << _name << " is out of hitPoints and can't be repaired." << std::endl;
    }
	else if (_energyPoints <= 0)
	{
        std::cout << "ClapTrap " << _name << " has no energy left to repair itself." << std::endl;
    }
}