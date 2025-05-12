/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:49:50 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:57:56 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice:public AMateria
{
	public:
		// Orthodox Canonical Form
		Ice();
		Ice(const Ice&);
		Ice& operator=(const Ice&);
		~Ice();

		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif