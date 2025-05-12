/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:46 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:24:19 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void display(const std::string& msg, const std::string& color)
{
	std::cout << std::endl << color << msg << RESET << std:: endl;
}

void testOrthodexCanonicalForm()
{
	display("Default constructor", YELLOW);
    Bureaucrat manager;
	std::cout << manager<<std::endl;
		
	display("Copy constructor", YELLOW);
    Bureaucrat hr(manager);
	std::cout << hr <<std::endl;
		
	display("Assignment Operator", YELLOW);
    Bureaucrat junior("junior", 25);
	std::cout << junior <<std::endl;
    junior = hr;
	std::cout << junior <<std::endl;
		
	display("Destructor", YELLOW);
}

void testExceptionInConstructor()
{
	std::cout<<std::endl;
	try
	{
		Bureaucrat manager1 = Bureaucrat("Manager1", 1);
		std::cout << manager1 <<std::endl;
		Bureaucrat manager2 = Bureaucrat("Manager2", 0); // grade too high
		std::cout << manager2 <<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}
	try
	{
		Bureaucrat junior1 = Bureaucrat("Junior1", 150);
		std::cout << junior1 <<std::endl;
		Bureaucrat junior2 = Bureaucrat("Junior2", 151); // grade too low
		std::cout << junior2 <<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}


void testIncrementDecrementGrade()
{
	std::cout<<std::endl;
	try
	{
		Bureaucrat junior = Bureaucrat("Junior", 43);
		std::cout << junior <<std::endl;
		junior.incrementGrade();
		std::cout << YELLOW<<"After Increment: " << RESET << std::endl;
		std::cout << junior << std::endl;

		Bureaucrat manager = Bureaucrat("Manager", 1);
		std::cout << manager <<std::endl;
		manager.incrementGrade();
		std::cout << YELLOW<<"After Increment: " << RESET << std::endl;
		std::cout << manager << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}

	try
	{
		Bureaucrat manager = Bureaucrat("Manager", 41);
		std::cout << manager <<std::endl;
		manager.decrementGrade();
		std::cout << YELLOW<<"After Decrement: " << RESET << std::endl;
		std::cout << manager << std::endl;

		Bureaucrat junior = Bureaucrat("Junior", 150);
		std::cout << junior <<std::endl;
		junior.decrementGrade();
		std::cout << YELLOW<<"After Decrement: " << RESET << std::endl;
		std::cout << junior << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
	}
}

int main()
{
	display("Bureaucrat Orthodox Canonical Form", CYAN_B);
	std::cout<<CYAN_B<<"**********************************"<<RESET<<std::endl;
	testOrthodexCanonicalForm();

	display("Exception in Constructor", CYAN_B);
	std::cout<<CYAN_B<<"************************"<<RESET<<std::endl;
	testExceptionInConstructor();

	display("Exception in Increment and Decrement Grades", CYAN_B);
	std::cout<<CYAN_B<<"*******************************************"<<RESET<<std::endl;
	testIncrementDecrementGrade();
	
	return 0;
}