#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy) : _numbers(copy._numbers) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
    }
    return *this;
}

RPN::~RPN() {}

TokenType findCase(const std::string &token)
{
    if (token.length() > 1)
        return TOKEN_ERROR;
    if (isdigit(token[0]))
        return TOKEN_DIGIT;
    if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        return TOKEN_OPERATOR;
    return TOKEN_ERROR;
}

void RPN::evaluate(const std::string &expression)
{
    std::stringstream ss(expression);
    std::string token;
    while (ss >> token)
    {
        TokenType type = findCase(token);
        if (type == TOKEN_DIGIT)
        {
            _numbers.push(atof(token.c_str()));
        }
        else if (type == TOKEN_OPERATOR)
        {
            if (_numbers.size() < 2)
                throw std::runtime_error("Error: operator called on one number in stack");
            double b = _numbers.top();
            _numbers.pop();
            double a = _numbers.top();
            _numbers.pop();

            if (token[0] == '+')
                _numbers.push(a + b);
            else if (token[0] == '-')
                _numbers.push(a - b);
            else if (token[0] == '*')
                _numbers.push(a * b);
            else  // division
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                _numbers.push(a / b);
            }
        }
        else
          throw std::runtime_error("Error: String provided is invalid");  
    }
    if (_numbers.size() != 1)
        throw std::runtime_error("Error: More than one element left");
}

double RPN::getResult() const
{
    if(_numbers.empty())
        throw std::runtime_error("Error: Invalid Result");
    return _numbers.top();
}