/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:17:30 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/20 11:49:48 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook():_index(0), _numOfContact(0)
{
    std::cout << "\033[2J\033[H";
    std::cout << std::endl;
    std::cout << "\t\t********************\033[0m" << std::endl;
    std::cout << "\t\t\033[0;33mMY AWESOME PHONEBOOK\033[0m" << std::endl;
    std::cout << "\t\t********************\033[0m" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::_addColumn(std::string str, int i, int num)
{
    std::cout<<str;
    if (num == 1)
        std::cin>>_contacts[i].firstName;
    else if (num == 2)
        std::cin>> _contacts[i].lastName;
    else if (num == 3)
        std::cin>> _contacts[i].nickName;
    else if (num == 4)
         std::cin>> _contacts[i].phoneNumber;
    else if (num == 5)
        std::cin>> _contacts[i].darkestSecret;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return ;
}

void PhoneBook::addContact()
{
    if (_index == _capacity)
        _index = 0;   
    _addColumn("Firstname : ", _index, 1);
    _addColumn("Lastname : ", _index, 2);
    _addColumn("Nickname : ", _index, 3);
    _addColumn("Phone number : ", _index, 4);
    _addColumn("Darkest secret : ", _index, 5);
    if (_numOfContact < _capacity)
        _numOfContact += 1;
    _index += 1;
    std::cout << std::endl << "\033[0;32m" <<"Contact added at Index " 
                    << _index-1 << ".\033[0m" << std::endl;
    std::cout << "Total number of Contact(s): " << _numOfContact << std::endl<<std::endl;
    return ;
}

std::string PhoneBook::_displayColumn(std::string str)
{
    if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int PhoneBook::_displayContacts()
{
    if (_index == 0)
	{
		std::cout << "No Contacts Found!" << std::endl;
		return 1;
	}
    std::cout << std::endl << "\t\t\tCONTACT LIST" << std::endl;
    std::cout << "\t|" << std::setw(10) << std::right << "Index" << "|"
                << std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < _numOfContact; i++)
    {
        std::cout << "\t|" << std::setw(10) << std::right <<  i << "|"
                << std::setw(10) << _displayColumn(_contacts[i].firstName) << "|"
                << std::setw(10) << _displayColumn(_contacts[i].lastName) << "|"
                << std::setw(10) << _displayColumn(_contacts[i].nickName) << "|"
                << std::endl;
    }
    std::cout<< std::endl << "Total number of Contact(s): " << _index
                << std::endl<<std::endl;
    return 0;
}

void PhoneBook::searchContact()
{
    std::string input;
    int         num;
        
    if (_displayContacts() == 1)
        return ;
    while (true)
    {
        std::cout << "\033[0;36m" << "Enter a Index of the entry to display: " << "\033[0m";
        std::cin>> input;
        try
        {
            num = std::stoi(input);
        } 
        catch (const std::invalid_argument&)
        {
            std::cout << "Invalid input: Not an integer." << std::endl;
            continue ;
        } 
        if (num < 0 || num > _numOfContact)
        {
            std::cout << "Index out of range." << std::endl;
            continue ;
        }
        else
        {
            std::cout << std::left;
            std::cout << std::setw(15) << "First Name: " << _contacts[num].firstName << std::endl;
		    std::cout << std::setw(15) << "Last Name: " << _contacts[num].lastName << std::endl;
		    std::cout << std::setw(15) << "Nickname: " << _contacts[num].nickName << std::endl;
		    std::cout << std::setw(15) << "Phone Number: " << _contacts[num].phoneNumber << std::endl;
		    std::cout << std::setw(15) << "Darkest Secret: " << _contacts[num].darkestSecret << std::endl;
            return ;
        } 
    }
    return ;
 }    