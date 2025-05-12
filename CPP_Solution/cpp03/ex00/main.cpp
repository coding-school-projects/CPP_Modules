/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:59:35 by pchennia          #+#    #+#             */
/*   Updated: 2024/09/21 10:58:36 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clap1("Daniel");
    ClapTrap clap2("Mike");
			
    clap1.attack("Mike");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    clap2.attack("Daniel");
    clap1.takeDamage(8);
    clap1.beRepaired(5);


    return 0;
}