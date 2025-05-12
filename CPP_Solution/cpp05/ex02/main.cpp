/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:45:50 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/29 10:09:25 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat collector("collector", 1);
	Bureaucrat staff("staff", 150);
	ShrubberyCreationForm form_s("home");
	RobotomyRequestForm form_r("office");
	PresidentialPardonForm form_p("public place");
    
	std::cout<<std::endl;
    std::cout<<CYAN_B<<"Orthodox Canonical Form"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"***********************"<<RESET<<std::endl;
	std::cout << form_s << std::endl;
	ShrubberyCreationForm ff(form_s);
	ShrubberyCreationForm cc;
	cc = ff;
	std::cout << "signed=" << cc.getIsSigned() << "\n";
    
	std::cout<<std::endl;
    std::cout<<CYAN_B<<"Shrubbery Sign and execute"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"**************************"<<RESET<<std::endl;
	staff.executeForm(form_s);
	staff.signForm(form_s);
	collector.signForm(form_s);
	staff.executeForm(form_s);
	collector.executeForm(form_s);
    
	std::cout<<std::endl;
    std::cout<<CYAN_B<<"Robotomy Sign and execute"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"*************************"<<RESET<<std::endl;
    staff.executeForm(form_r);
	staff.signForm(form_r);
	collector.signForm(form_r);
	staff.executeForm(form_r);
	collector.executeForm(form_r);

	std::cout<<std::endl;
    std::cout<<CYAN_B<<"Presidential Sign and execute"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"*****************************"<<RESET<<std::endl;
    staff.executeForm(form_p);
	staff.signForm(form_p);
	collector.signForm(form_p);
	staff.executeForm(form_p);
	collector.executeForm(form_p);
    
    std::cout<<std::endl;
	
    return 0;
}
