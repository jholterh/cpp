#include "ScalarConverter.hpp"
#include <string>

int main()
{
    std::string input = "";
    ScalarConverter::convert(input);
    input = "b";
    ScalarConverter::convert(input);
    input = "'b'";
    ScalarConverter::convert(input);
    input = "bs";
    ScalarConverter::convert(input);
    input = "1234567";
    ScalarConverter::convert(input);
    input = "+1234567";
    ScalarConverter::convert(input);
    input = "-1234567";
    ScalarConverter::convert(input);
    input = "+";
    ScalarConverter::convert(input);
    input = "++";
    ScalarConverter::convert(input);
    input = "++1234567";
    ScalarConverter::convert(input);
    input = " +1234567";
    ScalarConverter::convert(input);
    input = "+1234567 ";
    ScalarConverter::convert(input);
    input = "+1234 567";
    ScalarConverter::convert(input);
    input = "+1234s567";
    ScalarConverter::convert(input);
    input = "-12345678910";
    ScalarConverter::convert(input);
    input = "3.14";
    ScalarConverter::convert(input);
    input = "-3.14";
    ScalarConverter::convert(input);
    input = " 3.14";
    ScalarConverter::convert(input);
    input = "3.14 ";
    ScalarConverter::convert(input);
    input = "2.7182818284590452353602874713527";
    ScalarConverter::convert(input);
    input = "2.718f";
    ScalarConverter::convert(input);
    input = "2.718fs";
    ScalarConverter::convert(input);
    input = " 2.718f";
    ScalarConverter::convert(input);
    input = "2718f";
    ScalarConverter::convert(input);
    return 0;
}