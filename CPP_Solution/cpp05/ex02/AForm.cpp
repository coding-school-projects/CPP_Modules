/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:22:55 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:27:30 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _gradeToSign(42), 
			_gradeToExecute(42), _target("unknown")
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), 
	_target(other._target)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), 
		_gradeToExecute(gradeToExecute), _target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm custom constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, AForm& form)
{
	out << YELLOW
			<< "Name of form:     " << form.getName() << std::endl
			<< "Is form signed:   " << form.getIsSigned() << std::endl
			<< "Grade to sign:    " << form.getGradeToSign() << std::endl
			<< "Grade to execute: " << form.getGradeToExecute() << std::endl
			<< "Target of form:   " << form.getTarget()
			<< RESET << std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low.";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed.";
}

const std::string& AForm::getName() const
{
	return _name;
}

const std::string& AForm::getTarget() const
{
	return _target;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bc)
{
	if (bc.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}