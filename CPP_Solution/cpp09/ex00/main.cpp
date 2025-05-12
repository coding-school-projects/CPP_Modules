/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:14:52 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:34:28 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"


int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: invalid number of arguments.\n";
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	
	try {
		BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");
        exchange.run(argv[1]);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	}
	return 0;
}