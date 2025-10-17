#pragma once
 
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    public:
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade too high!";
                }
            };

            class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade too low!";
                }
            };

        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();  

        const std::string   getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();
        void                checkGrade(const int grade);
        void                signForm(AForm &f);
        void                executeForm(const AForm &form);

    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

 #endif