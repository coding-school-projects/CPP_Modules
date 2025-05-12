/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:14:49 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:11:34 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;	// Stores date -> exchange rate

		bool isValidDate(const std::string &date) const;
    	bool isValidValue(const std::string &valueStr, float &value) const;
    	std::string findClosestDate(const std::string &date) const;
	
	public:
		// Orthodox Canonical Form
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

		// Member function(s)
		void loadDatabase(const std::string &databaseFile);
		void run(const std::string &inputFile) const;	
};

#endif