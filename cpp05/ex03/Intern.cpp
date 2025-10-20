#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
    (void)copy;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string availableForms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = -1;
    while (++i < 3 && formName != availableForms[i]) {}
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(target));
        default:
            throw FormNonExistentException();
    }
}