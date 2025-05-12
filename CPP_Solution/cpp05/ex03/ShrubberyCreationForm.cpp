/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:40 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 11:12:44 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137, "unknown target")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm custom constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = getTarget() + "_shrubbery";

	std::ofstream outfile(filename);
	if (!outfile)
		throw std::runtime_error("Error in ShrubberyCreationForm::execute(): could not open file for writing");
	
	outfile << "\n        *             *\n"
       		<< "       /.\\           /.\\\n"
       		<< "      /0..\\         /0..\\\n"
			<< "      /..0\\         /..0\\\n"
			<< "     /.0..0\\       /.0..0\\\n"
			<< "     /...0.\\       /...0.\\\n"
			<< "    /..0....\\     /..0....\\\n"
			<< "    ^^^[_]^^^     ^^^[_]^^^\n\n";
    outfile.close();
}