/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:19:58 by pchennia          #+#    #+#             */
/*   Updated: 2024/12/17 09:43:34 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const& obj)
{
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs)
{
    (void)rhs;
    
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input) 
{
	std::string specialTypes[6] = 
	{
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) 
	{
		toChar = input[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}

	toInt = std::atoi(input.c_str());

	if (input[input.length() - 1] == 'f') 
	{
		toFloat = std::atof(input.c_str());
		toDouble = static_cast<double>(toFloat);
	} else 
	{
		toDouble = std::atof(input.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) 
	{
		if (input == specialTypes[i]) 
		{
			toChar = "imposible"; break;
		}
	}
	if (toChar == "" && (toInt >= 32 && toInt <= 126)) 
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} 
	else if (toChar == "") 
	{
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	if (toChar == "imposible") 
	{
		std::cout << "int: imposible" << std::endl;
	} 
	else 
	{
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "imposible" && toFloat == 0) 
	{
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	} 
	else 
	{
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0) 
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}