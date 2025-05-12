/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:02:28 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:25:49 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _gradeToSign(150), 
			_gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const Form& other):_name(other._name), _isSigned(other._isSigned),
				_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):_name(name), 
	_isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
	std::cout << "Form Custom constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException(); 
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

const std::string Form::getName()
{
	return _name;
}

bool Form::getIsSigned()
{
	return _isSigned;
}

int Form::getGradeToSign()
{
	return _gradeToSign;
}

int Form::getGradeToExecute()
{
	return _gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	out << "Name of the form: " << form.getName() << std::endl
			<< "Is form signed:   " << form.getIsSigned() << std::endl
			<< "Grade to sign:    " << form.getGradeToSign() << std::endl
			<< "Grade to execute: " << form.getGradeToExecute();
	return out;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low.";
}

void Form::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}
