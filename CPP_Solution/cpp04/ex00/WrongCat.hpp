/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:08 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/07 12:14:54 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        // Orthodox Canonical Form
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& src);
        ~WrongCat();

        void	makeSound() const;
};

#endif