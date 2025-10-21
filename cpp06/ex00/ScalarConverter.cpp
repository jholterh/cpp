#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>   // strtol
#include <cerrno>    // errno, ERANGE
#include <climits> 
#include <limits>   // INT_MIN, INT_MAX
#include <cfloat>    // FLT_MAX
#include <cctype>
#include <cmath>


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

void convert_from_char(char c)
{
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    std::cout << "char: ";
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    std::cout << "float: " << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d - static_cast<int>(d) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void convert_from_int(int i)
{
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(i)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    float f = static_cast<float>(i);
    std::cout << "float: " << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;

    double d = static_cast<double>(i);
    std::cout << "double: " << d;
    if (d - static_cast<int>(d) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void convert_from_float(float f)
{
    // CHAR
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) || f < static_cast<float>(std::numeric_limits<int>::min()) || f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    // FLOAT
    std::cout << "float: ";
    if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << (f < 0 ? "-inff" : "+inff") << std::endl;
    else {
        std::cout << f;
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // DOUBLE
    double d = static_cast<double>(f);
    std::cout << "double: ";
    if (std::isnan(f))
        std::cout << "nan" << std::endl;
    else if (std::isinf(f))
        std::cout << (f < 0 ? "-inf" : "+inf") << std::endl;
    else {
        std::cout << d;
        if (d - static_cast<int>(d) == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void convert_from_double(double d)
{
    // CHAR
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // FLOAT
    std::cout << "float: ";
    float f = static_cast<float>(d);
    if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
    else {
        std::cout << f;
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // DOUBLE
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
    else {
        std::cout << d;
        if (d - static_cast<int>(d) == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}


void ScalarConverter::convert(const std::string &input)
{
    char    out1;
    int     out2;
    double  out3;
    float   out4;

    if (isChar(input, out1))
    {
        convert_from_char(out1);
    }
        
    else if (isInt(input, out2))
    {
        convert_from_int(out2);
    }
        
    else if (isDouble(input, out3))
    {
        convert_from_double(out3);
    }
        
    else if (isFloat(input, out4))
    {
        convert_from_float(out4);
    }
        
    else
        std::cout << input << " is neither a char, an int, a float nor a double" << std::endl;
    std::cout << "\n" << std::endl;
}