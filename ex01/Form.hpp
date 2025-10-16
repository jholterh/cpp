#pragma once

#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>

class Bureaucrat; // Forward Declaration so the compiler knows it exists

class Form
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

        Form();
        Form(const std::string &name, const int signGrade, const int executeGrade);
        Form(const Form &copy);
        Form &operator=(const Form &other);
        ~Form();

        const std::string   getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        void                checkGrade(const int grade);
        void                beSigned(const Bureaucrat &b);
    
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif