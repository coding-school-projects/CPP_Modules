/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:43:56 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/28 10:41:48 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    std::string	name;
    Weapon *weapon;
	
    public:
		HumanB(const std::string &name);
        void setWeapon(Weapon &weapon);
		void attack();
};

#endif