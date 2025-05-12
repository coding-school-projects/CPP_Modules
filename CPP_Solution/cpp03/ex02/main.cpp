/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:50:43 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:13:21 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap ft("Jake");
	ft.attack("Robot");
	ft.takeDamage(42);
	ft.beRepaired(10);
	ft.highFivesGuys();
	
	return (0);
}