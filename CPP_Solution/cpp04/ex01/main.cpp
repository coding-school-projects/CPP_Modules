/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:44 by pchennia          #+#    #+#             */
/*   Updated: 2024/10/21 10:37:27 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

	std::cout<< std::endl << "--- Test: Individual objects --- "<<std::endl<<std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    dog->makeSound();  // Dog sound
    cat->makeSound();  // Cat sound
    delete dog;
    delete cat;

	std::cout<< std::endl << "--- Test: Deep copy functionality --- "<<std::endl<<std::endl;

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Play Football");
    Dog copyDog = originalDog;  // Deep copy
    std::cout << "Original Dog Brain Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
    originalDog.getBrain()->setIdea(0, "Play Basketball");
    std::cout << "Modified Original Dog Brain Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea after modification: " << copyDog.getBrain()->getIdea(0) << std::endl;

	std::cout<< std::endl << "--- Test: Array of Animal objects --- "<<std::endl<<std::endl;

    const int numAnimals = 4;
    Animal* animals[numAnimals];
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
