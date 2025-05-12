/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:39:18 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/31 12:44:51 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombies = zombieHorde(N, "HordeZombie");
    
    for (int i = 0; i < N; i++)
    {
		std::cout << "[" << i + 1 << "] ";
		zombies[i].announce();
	}
	delete[] zombies;
    return 0;
}