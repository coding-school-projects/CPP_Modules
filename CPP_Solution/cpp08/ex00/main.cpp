/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:33 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:28:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

#define RESET   "\e[0m"
#define CYAN    "\e[0;36m"

template <typename T>
void fillContainer(T& container, int n)
{
    for (int i = 0; i < n; i++)
        container.push_back((i * 10) + i);
}

template <typename T>
void displayContainer(T& container, const std::string& containerName)
{
	std::cout << containerName << " Container contents: [ ";
    for (auto it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}

template <typename T>
void testContainer(T& container, int valueToFind)
{
    std::cout << CYAN << "easy find " << valueToFind << RESET << std::endl;
    try {
        typename T::iterator valueIterator = easyfind(container, valueToFind);
        std::cout << "Found: " << *valueIterator << " at index: "
                  << std::distance(container.begin(), valueIterator) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    int n = 5;

    std::vector<int> intVector;
    std::deque<int> intDeque;
    std::list<int> intList;

    // Fill each container dynamically
    fillContainer(intVector, n);
    fillContainer(intDeque, n);
    fillContainer(intList, n);

    std::cout << CYAN << "\n----- Vector Test -----\n" << RESET << std::endl;
	displayContainer(intVector, "Vector");
    testContainer(intVector, 11);
    testContainer(intVector, 100);

    std::cout << CYAN << "\n----- Deque Test -----\n" << RESET << std::endl;
	displayContainer(intDeque, "Deque");
    testContainer(intDeque, 44);
    testContainer(intDeque, 55);

    std::cout << CYAN << "\n----- List Test -----\n" << RESET << std::endl;
	displayContainer(intList, "List");
    testContainer(intList, 22);
    testContainer(intList, 78);

    return 0;
}
