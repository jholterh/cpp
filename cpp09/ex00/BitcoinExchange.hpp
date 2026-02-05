#pragma once
#include <map>
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

enum ValueError {
    VALUE_OK = 0,
    VALUE_INVALID_FORMAT = 1,
    VALUE_NEGATIVE = 2,
    VALUE_TOO_LARGE = 3
};

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    loadDatabase(const std::string &filename);
        double  getExchangeRate(const std::string &date) const;
        void    processInputFile(const std::string &filename);

    private:
        std::map<std::string, double> _database;
        
        bool        isValidDate(const std::string &date) const;
        ValueError  isValidValue(const std::string &value, double &result) const;
};
