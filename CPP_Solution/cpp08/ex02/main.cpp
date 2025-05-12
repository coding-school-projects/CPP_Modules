/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:50 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:23:06 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

#define RESET   "\e[0m"
#define CYAN    "\e[0;36m"

template <typename T>
void displayContainer(T& container, const std::string& containerName)
{
	std::cout << containerName << " contents: [ ";
	for (int val : container)
    	std::cout << val << " ";
	std::cout << "]" << std::endl;
}

void testStack(MutantStack<int>& mstack)
{
    std::cout << CYAN << "\n----- Stack Test -----\n" << RESET << std::endl; 

	displayContainer(mstack, "Stack");

    mstack.push(5); // Adds element to top of stack
    mstack.push(17);

	displayContainer(mstack, "Stack");

    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop(); // Removes the top element
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3); 
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

	displayContainer(mstack, "Stack");
    std::cout << "Iterating through stack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it; // Skip first element
    --it; // Reset to first element
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
void testList(std::list<int> list)
{
    std::cout << CYAN << "\n----- List Test -----\n" << RESET << std::endl;
	displayContainer(list, "List");
    list.push_back(5);
    list.push_back(17);
	
	displayContainer(list, "List");
    
    std::cout << "Back: " << list.back() << std::endl;
    
    list.pop_back();
    std::cout << "Size: " << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

	displayContainer(list, "List");
    std::cout << "Iterating through list:" << std::endl;
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{
    MutantStack<int> mstack;
    testStack(mstack);

    std::list<int> list;
    testList(list);
    
    return 0;
}