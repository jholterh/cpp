#pragma once
 
 #ifndef BUREAUCRAT.HPP
 #define BUREAUCRAT.HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    public:

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override
                {
                    return "Grade too high!";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override
                {
                    return "Grade too low!";
                }
        };

        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();  

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        
    private:
        const std::string   name;
        int                 grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

 #endif