#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _database(copy._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    // Check if all chars except dashes are digits
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    
    // Extract year, month, day
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    // Validate ranges
    if (year < 2009 || year > 2026)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    // Days per month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}

ValueError BitcoinExchange::isValidValue(const std::string &value, double &result) const
{
    char *end;
    errno = 0;
    result = std::strtod(value.c_str(), &end);
    
    if (end == value.c_str() || *end != '\0')
        return VALUE_INVALID_FORMAT;
    
    // Check for overflow
    if (errno == ERANGE)
        return VALUE_INVALID_FORMAT;
    
    // Check if negative
    if (result < 0)
        return VALUE_NEGATIVE;
    
    // Check if too large
    if (result > 1000)
        return VALUE_TOO_LARGE;
    
    return VALUE_OK;
}



void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream DataBase(filename);
    if (!DataBase.is_open())
        throw std::runtime_error("Error: could not open database file.");
    
    std::string line;
    std::getline(DataBase, line); // Skip header
    
    while (std::getline(DataBase, line))
    {
        int length = line.length();
        _database.insert(std::make_pair(line.substr(0, 10), atof(line.substr(11, length - 11).c_str())));
    }
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _database.find(date);
    
    if (it != _database.end())
        return it->second;
    
    it = _database.upper_bound(date);
    if (it == _database.begin())
        throw std::runtime_error("Error: no earlier date available");
    
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream InputFile(filename);
    if (!InputFile.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::getline(InputFile, line); // Skip header

    while (std::getline(InputFile, line))
    {
        // Check line format
        if (line.length() < 14 || line.find(" | ") == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, 10);
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        double amount;
        std::string valueStr = line.substr(13, line.length() - 13);
        
        ValueError error = isValidValue(valueStr, amount);
        if (error != VALUE_OK)
        {
            if (error == VALUE_NEGATIVE)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (error == VALUE_TOO_LARGE)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        try {
            double rate = getExchangeRate(date);
            double result = amount * rate;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        }
        catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
