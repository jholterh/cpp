#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>   // strtol
#include <cerrno>    // errno, ERANGE
#include <climits>   // INT_MIN, INT_MAX
#include <cfloat>    // FLT_MAX
#include <cctype> 

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string &s, char &out)
{
    if (s.size() != 3 || s[0] != '\'' || s[2] != '\'' || !std::isprint(s[1])) return false;
    out = s[1];
    return true;
}

bool isInt(const std::string &s, int &out)
{
    if (s.empty()) return false;
    if (std::isspace((unsigned char)s[0])) return false;
    errno = 0;
    char *endptr = 0;
    const char *begin = s.c_str();
    long value = std::strtol(begin, &endptr, 10);
    if (errno == ERANGE) return false;
    if (endptr != begin + s.size()) return false;
    if (value < INT_MIN || value > INT_MAX) return false;
    out = static_cast<int>(value);
    return true;
}

bool isDouble(const std::string &s, double &out)
{
    if (s.find('.') == std::string::npos) return false;
    if (std::isspace((unsigned char)s[0])) return false;
    errno = 0;
    char *endptr = 0;
    const char *begin = s.c_str();
    double value = std::strtod(begin, &endptr);
    if (errno == ERANGE) return false;
    if (endptr != begin + s.size()) return false;
    out = value;
    return true;
}

bool isFloat(const std::string &s, float &out)
{
    if (s.find('f') == std::string::npos) return false;
    if (std::isspace((unsigned char)s[0])) return false;
    errno = 0;
    char *endptr = 0;
    const char *begin = s.c_str();
    float value = std::strtof(begin, &endptr);
    if (errno == ERANGE) return false;
    if (*endptr != 'f' || *(endptr + 1) != '\0') return false;
    out = value;
    return true;
}


void print_int_char(const std::string &s)
{
    int impos = 0;
    errno = 0;
    char *endptr = 0;
    const char *begin = s.c_str();
    long value = std::strtol(begin, &endptr, 10);
    if (errno == ERANGE) impos = 1;
    if (endptr != begin + s.size()) impos = 1;
    if (value < INT_MIN || value > INT_MAX) impos = 1;
    if (impos)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int value = static_cast<int>(value);
        if (std::isprint(value))
            std::cout << "char: " << static_cast<char>(value) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << value << std::endl;
    }
}

void float_to_all(const std::string &s, float &out)
{
    print_int_char(s);
    std::cout << "float: " << out << std::endl;
    
}

void ScalarConverter::convert(std::string &input)
{
    char    out1;
    int     out2;
    double  out3;
    float   out4;

    if (isChar(input, out1))
        std::cout << input << " is this char: " << out1 << std::endl;
    else if (isInt(input, out2))
        std::cout << input << " is this integer: " << out2 << std::endl;
    else if (isDouble(input, out3))
        std::cout << input << " is this double: " << out3 << std::endl;
    else if (isFloat(input, out4))
        std::cout << input << " is this double: " << out4 << std::endl;
    else
        std::cout << input << " is neither a char, an int, a float nor a double" << std::endl;
}