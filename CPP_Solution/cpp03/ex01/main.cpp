/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:59:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:06:41 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ScavTrap st("Robot");
	st.attack("a door");
	st.takeDamage(42);
	st.beRepaired(10);
	st.guardGate();
	
	return (0);
}