#pragma once
 
 #ifndef BUREAUCRAT.HPP
 #define BUREAUCRAT.HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    Bureaucrat();
    Bureaucrat(std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

};


 #endif