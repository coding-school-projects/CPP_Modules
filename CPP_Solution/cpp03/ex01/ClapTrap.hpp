/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:01:05 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:22:53 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	protected:
			std::string _name;
			int _hitPoints;
			int _energyPoints;
			int _attackDamage;
	public:
			// Orthodox Canonical Form
			ClapTrap(const std::string& name);          // Constructor
			ClapTrap(const ClapTrap& other);			// Copy constructor
			ClapTrap& operator = (const ClapTrap& src); // Copy assign operator
			~ClapTrap();								// Destructor
			
			// Member function(s)
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
};

#endif