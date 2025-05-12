/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:10:57 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 11:14:39 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap diamond("Diamondy");
    diamond.attack("enemy");
    diamond.takeDamage(50);
    diamond.beRepaired(30);
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

	return (0);
}