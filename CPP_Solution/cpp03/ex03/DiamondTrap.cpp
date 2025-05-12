/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:02:51 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:27:56 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Constructor with name parameter
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " created with " 
            << this->_hitPoints << " hitPoints, " 
            << this->_energyPoints << " energyPoints, and " 
            << this->_attackDamage << " attackDamage." << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other),ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    if (this != &src)
	{
        ClapTrap::operator=(src);
        ScavTrap::operator=(src);
        FragTrap::operator=(src);
        _name = src._name;
    }
    std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " <<_name << " is destroyed." <<std::endl;
}

// Attack function
void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

// Who am I function
void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " 
              << ClapTrap::_name << "." << std::endl;
}