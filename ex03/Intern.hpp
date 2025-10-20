#pragma once

#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <string>
class AForm;

class Intern
{
    public:
        class FormNonExistentException : public std::exception {
            public:
                const char *what() const throw() {
                    return "Form does not exist!";
                }
        };
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &other);
        ~Intern();
        AForm *makeForm(const std::string &formName, const std::string &target);
};  


#endif