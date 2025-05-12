/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:59:40 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 11:46:09 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
    protected:
        std::string _type;
    
    public:
        // Orthodox Canonical Form
		AAnimal();                                
		AAnimal(const AAnimal& other);			 
		AAnimal& operator = (const AAnimal& src);   
		virtual ~AAnimal();								  
			
		// Member function(s)
        std::string getType() const;
        virtual void makeSound() const = 0; //pure virtual function
};

#endif