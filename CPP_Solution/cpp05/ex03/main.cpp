/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:16:11 by pchennia          #+#    #+#             */
/*   Updated: 2024/11/28 00:43:32 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat manager("manager", 1);
	Bureaucrat junior("junior", 150);
	Intern intern;
	ShrubberyCreationForm form_s("home");
	RobotomyRequestForm form_r("cluster");
	PresidentialPardonForm form_p("42 school");
	
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
	junior.executeForm(form_s);
	junior.signForm(form_s);
	manager.signForm(form_s);
	junior.executeForm(form_s);
	manager.executeForm(form_s);

	std::cout<<std::endl;
	std::cout<<CYAN_B<<"Robotomy Sign and execute"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"*************************"<<RESET<<std::endl;
	junior.executeForm(form_r);
	junior.signForm(form_r);
	manager.signForm(form_r);
	junior.executeForm(form_r);
	manager.executeForm(form_r);

	std::cout<<std::endl;
	std::cout<<CYAN_B<<"Presidential Sign and execute"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"*****************************"<<RESET<<std::endl;
	junior.executeForm(form_p);
	junior.signForm(form_p);
	manager.signForm(form_p);
	junior.executeForm(form_p);
	manager.executeForm(form_p);
	
	std::cout<<std::endl;
	std::cout<<CYAN_B<<"Intern"<<RESET<<std::endl;
	std::cout<<CYAN_B<<"******"<<RESET<<std::endl;
	AForm* tmp = intern.makeForm("forrrrm", "tarrrrget");
	tmp = intern.makeForm("robotomy request", "Bender");
	std::cout << *tmp;
	delete tmp;
	tmp = nullptr;
	tmp = intern.makeForm("shrubbery creation", "home");
	std::cout << *tmp;
	delete tmp;
	tmp = nullptr;
	tmp = intern.makeForm("presidential pardon", "cat");
	std::cout << *tmp;
	junior.executeForm(*tmp);
	junior.signForm(*tmp);
	manager.signForm(*tmp);
	std::cout << *tmp;
	junior.executeForm(*tmp);
	manager.executeForm(*tmp);
	delete tmp;
	tmp = nullptr;
	
	std::cout << std::endl;

	return 0;
}