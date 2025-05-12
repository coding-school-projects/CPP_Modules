/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:44 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:23:01 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout<< std::endl << "--- Test: Basic --- "<<std::endl<<std::endl;
	// Calling the default constructor using new
    Animal* animal1 = new Animal();  // This calls Animal::Animal()

    // Calling the copy constructor using new
    Animal* animal2 = new Animal(*animal1);  // This calls Animal::Animal(const Animal& other)

    // Calling the assignment operator using new
    Animal* animal3 = new Animal();  // Default constructor
    *animal3 = *animal1;  // This calls Animal::operator=(const Animal& other)

    // Clean up dynamically allocated memory
    delete animal1;
    delete animal2;
    delete animal3;

	std::cout<< std::endl <<"--- Test: Correct Animals ---"<<std::endl<<std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // Cat's sound!
	j->makeSound(); // Dog's sound
	meta->makeSound(); // Animal's sound
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl <<" --- Test: Wrong Animals --- "<< std::endl<< std::endl;
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	std::cout << w_i->getType() << " " << std::endl;
	w_i->makeSound(); // WrongAnimal's sound(non-virtual)
	w_meta->makeSound(); // WrongAnimal's sound
	delete w_i;
	delete w_meta;

	return 0;
}