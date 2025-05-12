/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:17:23 by pchennia          #+#    #+#             */
/*   Updated: 2024/08/20 11:12:40 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook {
    private:
        static const int _capacity = 8;
        Contact _contacts[_capacity];
        int _index;
        int _numOfContact;
        void _addColumn(std::string, int i, int num);
        int _displayContacts();
        std::string _displayColumn(std::string str);
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};