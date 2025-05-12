/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:40 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:44:15 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string _type;
    
    public:
        // Orthodox Canonical Form
		Animal();                                
		Animal(const Animal& other);			  
		Animal& operator = (const Animal& src);   
		virtual ~Animal();								 
			
		// Member function(s)
        std::string getType() const;
        virtual void makeSound() const;
};

#endif