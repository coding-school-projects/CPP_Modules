/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:22:49 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:09:02 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <fstream>
#include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define CYAN_B "\033[1;36m"
# define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		const std::string	_target;

	public:
		AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
		
		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat& bc);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, AForm& form);

#endif