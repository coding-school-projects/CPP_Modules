/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:43 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:03:22 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# define RED "\033[0;31m"
# define CYAN_B "\033[1;36m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

#include <iostream>
#include <string>
#include <exception>

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