/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:45:50 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:05:23 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN_B "\033[1;36m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// Orthodox Canonical Form
		Form();
		Form(const Form &other);
		Form& operator=(const Form& other);
		~Form();

		// Custom Constructor
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		
		// Member function(s)
		const std::string	getName();
		bool				getIsSigned();
		int					getGradeToSign();
		int					getGradeToExecute();
		void				beSigned(Bureaucrat& bc);

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
std::ostream& operator<<(std::ostream& out, Form& form);

#endif
