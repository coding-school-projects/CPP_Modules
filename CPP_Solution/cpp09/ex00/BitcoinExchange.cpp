/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:14:46 by pchennia          #+#    #+#             */
/*   Updated: 2025/04/09 12:43:28 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		this->_database.clear();
		this->_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &databaseFile)
{
	std::ifstream inFile(databaseFile.c_str());
	if (!inFile.is_open())
		throw std::runtime_error("could not open database file.");
	if (inFile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("data.csv is empty");

	std::string line;
	std::getline(inFile, line); // Skip header line
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("invalid data.csv => " + line);

	while (std::getline(inFile, line)) {
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = line.substr(0, comma);
		std::string valueStr = line.substr(comma + 1);

		float value;
		std::istringstream iss(valueStr);
		if (!(iss >> value))
			continue;

		_database[date] = value;
	}
}

void BitcoinExchange::run(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error(inputFile + " is empty");

	std::string line; // Skip header line
	std::getline(file, line);
	if (line.compare("date | value") != 0)  // validate the first line
		throw std::runtime_error(inputFile + " not valid => " + line);

	while (std::getline(file, line)) {
		try {
			size_t pipe = line.find('|');
			if (pipe == std::string::npos)
				throw std::runtime_error("Error: bad input => " + line);

			std::string date = line.substr(0, pipe);
			date.erase(date.find_last_not_of(" \t") + 1);
			date.erase(0, date.find_first_not_of(" \t"));

			std::string valueStr = line.substr(pipe + 1);
			valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \t"));

			if (!isValidDate(date)) {
				throw std::runtime_error("Error: bad input => " + date); }

			float value;
			if (!isValidValue(valueStr, value))
				continue;

			std::string closestDate = findClosestDate(date);
			float exchangeRate = _database.at(closestDate);
			float result = value * exchangeRate;

			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	iss >> year >> dash1 >> month >> dash2 >> day;

	if (dash1 != '-' || dash2 != '-' || iss.fail() || !iss.eof())
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2) {
		bool isLeap = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const
{
	char *end;
	value = std::strtof(valueStr.c_str(), &end);

	if (*end != '\0' || end == valueStr.c_str())
		throw std::runtime_error("Error: bad input => " + valueStr);

	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");

	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");

	return true;
}

std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
	if (_database.empty())
		throw std::runtime_error("Error: database is empty");

	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

	if (it == _database.begin() && it->first != date)
		throw std::runtime_error("Error: no data available before " + date);

	if (it == _database.end() || it->first != date)
		--it;

	return it->first;
}
