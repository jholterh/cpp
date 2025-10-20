#include "Form.hpp"
#include "Bureaucrat.hpp"

void Form::checkGrade(const int grade)
{
        if (grade > 150)
            throw GradeTooLowException();
        if (grade < 1)
            throw GradeTooHighException();
}

Form::Form() : _name("Standard Form"), _isSigned(false), _signGrade(1), _executeGrade(1) {}

Form::Form(const std::string &name, const int signGrade, const int executeGrade) :
    _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    checkGrade(signGrade);
    checkGrade(executeGrade);
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned),
    _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName() << ", signed: " << std::boolalpha << f.getIsSigned()
       << ", sign grade: " << f.getSignGrade()
       << ", execute grade: " << f.getExecuteGrade();
    return os;
}


const std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecuteGrade() const
{
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (_isSigned == true)
        throw AlreadySignedException();
    else if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}
