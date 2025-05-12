/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:08:01 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:36:12 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void display(const std::string& msg, const std::string& color)
{
	std::cout << std::endl << color << msg << RESET << std:: endl;
}

void testOrthodexCanonicalForm()
{
	display("Default constructor", YELLOW);
    Form defaultForm;
	std::cout << defaultForm<<std::endl;
		
	display("Copy constructor", YELLOW);
    Form copyForm(defaultForm);
	std::cout << copyForm <<std::endl;
		
	display("Assignment Operator", YELLOW);
    Form assignedForm("AssignedForm", 42, 42);
	std::cout << assignedForm <<std::endl;
	Bureaucrat assignedBureaucrat("AssignedBureaucrat", 42);
	assignedBureaucrat.signForm(assignedForm);
	std::cout << assignedForm <<std::endl;
    assignedForm = copyForm;
	std::cout << assignedForm <<std::endl;
		
	display("Destructor", YELLOW);
}

int main()
{
	display("Form Orthodox Canonical Form", CYAN_B);
	std::cout<<CYAN_B<<"****************************"<<RESET<<std::endl;
	testOrthodexCanonicalForm();
	
	display("Exception in Custom constructor", CYAN_B);
	std::cout<<CYAN_B<<"*******************************"<<RESET<<std::endl;
	{
		try
		{
			Form offerForm = Form("OfferForm", 150, 1);
			std::cout << offerForm <<std::endl;
			Form saleForm = Form("SaleForm", 0, 1); // grade too high
			std::cout << saleForm <<std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() << RESET << std:: endl;
		}
	}

	display("Bureaucrat::signForm(), Form::beSigned()", CYAN_B);
	std::cout<<CYAN_B<<"****************************************"<<RESET<<std::endl;
	{
		Bureaucrat junior = Bureaucrat("Junior", 43);
		std::cout << junior <<std::endl;
		Bureaucrat manager = Bureaucrat("Manager", 41);
		std::cout << manager <<std::endl;
		Form entryForm = Form("EntryForm", 42, 42);
		std::cout << entryForm <<std::endl;
		junior.signForm(entryForm);
		manager.signForm(entryForm);
	}
}