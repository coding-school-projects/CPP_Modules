/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:49 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:46:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *_brain;
    public:
        // Orthodox Canonical Form
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound() const;   
        Brain* getBrain() const; // Get the Dog's brain
};

#endif