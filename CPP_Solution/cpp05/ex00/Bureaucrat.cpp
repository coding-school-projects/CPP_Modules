/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:37 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:03:33 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(42)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	std::cout << "Bureaucrat Assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	std::cout << "Bureaucrat Custom constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException(); 
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

const std::string Bureaucrat::getName()
{
	return _name;
}

int Bureaucrat::getGrade()
{
	return _grade;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& bc)
{
	out <<"Name: " << bc.getName() << ", Bureaucrat grade: " << bc.getGrade();
	return out;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low.";
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}
