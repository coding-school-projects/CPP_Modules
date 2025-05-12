/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:44 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:47:45 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout<< std::endl << "--- Test: Individual objects --- "<<std::endl<<std::endl;

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();
    dog->makeSound();  // Dog sound
    cat->makeSound();  // Cat sound
    delete dog;
    delete cat;

	std::cout<< std::endl << "--- Test: Array of Animal objects --- "<<std::endl<<std::endl;

    const int numAnimals = 4;
    AAnimal* animals[numAnimals];
    for (int i = 0; i < numAnimals / 2; i++)
	{
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; i++)
	{
        animals[i] = new Cat();
    }

    for (int i = 0; i < numAnimals; i++)
	{
        animals[i]->makeSound();
    }

    for (int i = 0; i < numAnimals; i++)
	{
        delete animals[i];  // destructor call
    }

	return 0;
}
