/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:29:42 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:44:59 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_brain;
    public:
        // Orthodox Canonical Form
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& src);
        ~Cat();
        
        void makeSound() const;  
        Brain* getBrain() const; // Get cat's brain
};

#endif