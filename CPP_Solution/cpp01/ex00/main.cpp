/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:36:34 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/26 14:21:14 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{   
    if (argc != 2)
    {
        std::cout << "Usage: ./zombie <name>" <<std::endl;
        return 1;
    }
    /* allocate zombie on the heap*/
    Zombie *zombie = newZombie(argv[1]);
    zombie->announce();
    
     /* allocate zombie on the stack */
    randomChump(argv[1]);
    delete zombie;
    return 0;
}