/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:01:42 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/12 16:34:01 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <string>
#include <iostream>
#include <exception>

#define MAX_VAL 5

template <typename T>
void printRawArray(T* arr, unsigned int length)
{
	if (length == 0)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	std::cout << "{ ";
		for (unsigned int i = 0; i < length; ++i)
			std::cout << arr[i] << " ";
	std::cout << "}" << std::endl;
}

template <typename T>
void printArray(const Array<T>& arr)
{
	if (arr.size() == 0)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	std::cout << "{ ";
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << " ";
	std::cout << "}" << std::endl;
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    std::cout<<"(Custom array) numbers: ";
    printArray(numbers);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout<<"(Regular dynamic array) mirror: ";
    printRawArray(mirror, MAX_VAL);
    std::cout<<std::endl;
    
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;  // Subscript operator for non-const
        mirror[i] = value;
    }

    std::cout<<"After random numbers generate: "<<std::endl;
    std::cout<<"numbers: ";
    printArray(numbers);
    std::cout<<"mirror: ";
    printRawArray(mirror, MAX_VAL);
    std::cout<<std::endl;

    std::cout<<"Copy construcor: "<<std::endl;
    Array<int> tmp = numbers;
    std::cout<<"tmp: ";
    printArray(tmp);
    std::cout<<std::endl;
        
    std::cout<<"Copy assign operator: "<<std::endl;
    std::cout<<"test: ";
    Array<int> test(tmp);
    printArray(test);
    std::cout<<std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
	try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
	try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout<<std::endl;
    std::cout<<"After changing an elements: "<<std::endl;
    std::cout<<"numbers: ";
    printArray(numbers);
    std::cout<<"tmp: ";
    printArray(tmp);
    std::cout<<"test: ";
    printArray(test);
    
    delete [] mirror;
    
    return 0;
}