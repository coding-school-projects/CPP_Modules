/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:49 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/07 12:14:14 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        // Orthodox Canonical Form
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound() const;
    
};

#endif