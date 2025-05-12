/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:15:14 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 13:44:29 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided." << std::endl;
		std::cerr << "Usage: " << argv[0] << " \"[positive integer sequence]\"" << std::endl;
        std::cerr << "Example: " << argv[0] << " \"3 5 9 7 4\"" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    std::vector<int> input;
    std::set<int> uniqueValues;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        std::istringstream iss(arg);
        int num;
        
        if (!(iss >> num) || num <= 0 || iss.peek() != EOF) {
            std::cerr << "Error: Invalid input '" << arg << "'" << std::endl;
            return 1;
        }
        if (uniqueValues.find(num) != uniqueValues.end()) {
            std::cerr << "Error: Invalid input, duplicate value " << num << std::endl;
            return 1;
        }
        uniqueValues.insert(num);
        input.push_back(num);
    }

    sorter.sortAndDisplay(input);
    return 0;
}