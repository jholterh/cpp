#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

enum TokenType {
    TOKEN_DIGIT = 0,
    TOKEN_OPERATOR = 1,
    TOKEN_ERROR = 2
};

class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &other);
        ~RPN();

        void    evaluate(const std::string &expression);
        double  getResult() const;


    private:
        std::stack<double> _numbers;
};