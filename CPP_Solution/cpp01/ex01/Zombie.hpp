/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:40:45 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/28 09:55:50 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    std::string _name;;

    public:
            Zombie();
            ~Zombie();
            void announce();
            void setName(std::string name);           
};

Zombie* zombieHorde(int N, std::string name);

#endif 