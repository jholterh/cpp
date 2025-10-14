#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No Name"), _grade(150) {}

void Bureaucrat::checkGrade(const int grade)
{
        if (grade > 150)
            throw GradeTooHighException();
        if (grade < 1)
            throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
 
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
    _grade++;
    checkGrade(_grade);
}

void Bureaucrat::decrementGrade()
{
    _grade--;
    checkGrade(_grade);
}
