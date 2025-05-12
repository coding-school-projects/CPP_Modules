/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:03 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:50:00 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments\n";
        std::cerr << "Usage: " << argv[0] << " \"inverted Polish mathematical expression\"" << std::endl;
        std::cerr << "Example: " << argv[0] << " \"1 2 +\"" << std::endl;
		return 1;
	}
	
	try {
		double result = RPN::evaluate(argv[1]);
        std::cout << result << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
        return 1;
	}
	return 0;
}