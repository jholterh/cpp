#pragma once

#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
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
        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Already been signed!";
                }
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw(){
                    return "Form has not been signed!";
                }
        };

        AForm();
        AForm(const std::string &name, const int signGrade, const int executeGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        void                checkGrade(const int grade) const;

        void                beSigned(const Bureaucrat &b);
        void                execute(const Bureaucrat &executor) const;
    
    protected:
        virtual void        action() const = 0;

    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif