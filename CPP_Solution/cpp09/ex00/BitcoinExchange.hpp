#pragma once

#include <map> // std::map
#include <string> // std::string

class BitcoinExchange {
private:
    std::map<std::string, double> exchangeRates;

public:
    BitcoinExchange();
    explicit BitcoinExchange(const std::map<std::string, double>& rates);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    double getExchangeRate(const std::string& date) const;
};
