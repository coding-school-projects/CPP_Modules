/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:25:39 by pchennia          #+#    #+#             */
/*   Updated: 2025/03/20 11:21:38 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define RESET   "\e[0m"
#define CYAN    "\e[0;36m"

void Span::printNumbers() const {
    std::cout << "Container contents: [ ";
    for (int num : _intVector) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    try
    {
        Span sp(5);
		
		std::cout << CYAN << "\n----- Test-1 -----\n" << RESET << std::endl;
        sp.addNumber(10);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printNumbers();
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		std::cout << CYAN << "\n----- Test-2 -----\n" << RESET << std::endl;
        Span bigSpan(10000);
        for (int i = 0; i < 10000; i++)
            bigSpan.addNumber(i * 2); // Even numbers

		bigSpan.printNumbers();
        std::cout << "BigSpan Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "BigSpan Longest: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	try {
        // Adding more numbers in one call using a range
        std::cout << CYAN << "\n----- Test-3 -----\n" << RESET << std::endl;
        std::vector<int> numbers = {20, 30, 40, 50};
        Span sp(10);
        sp.addMultipleNumbers(numbers.begin(), numbers.end()); 

		std::cout << "After adding multiple numbers " << std::endl;
        sp.printNumbers();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

