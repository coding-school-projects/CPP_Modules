/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:44 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:57:24 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        // Orthodox Canonical Form
		Cure();                                
		Cure(const Cure&);    		  
		Cure& operator = (const Cure&);  
		~Cure();

		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif