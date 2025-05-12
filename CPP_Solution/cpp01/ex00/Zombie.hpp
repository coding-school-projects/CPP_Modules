/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:37:16 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/26 14:17:25 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    std::string _name;
    
    public:
            Zombie(std::string name);
            ~Zombie();
            void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif