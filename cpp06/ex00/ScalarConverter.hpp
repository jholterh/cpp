#pragma once

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(std::string &input);
        
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
};

#endif