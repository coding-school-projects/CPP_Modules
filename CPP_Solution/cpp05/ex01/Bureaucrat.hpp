/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:07:57 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:05:05 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Custom Constructor
		Bureaucrat(const std::string name, int grade);
		
		// Member function(s)
		const std::string	getName();
		int					getGrade();
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form);

		// Exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
};

// Overloaded << operator
std::ostream& operator<<(std::ostream& out, Bureaucrat& bc);

#endif