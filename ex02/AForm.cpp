#include "AForm.hpp"
#include "Bureaucrat.hpp"

void AForm::checkGrade(const int grade) const
{
        if (grade > 150)
            throw GradeTooLowException();
        if (grade < 1)
            throw GradeTooHighException();
}

AForm::AForm() : _name("Standard AForm"), _isSigned(false), _signGrade(1), _executeGrade(1) {}

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade) :
    _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    checkGrade(signGrade);
    checkGrade(executeGrade);
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned),
    _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", signed: " << std::boolalpha << f.getIsSigned()
       << ", sign grade: " << f.getSignGrade()
       << ", execute grade: " << f.getExecuteGrade();
    return os;
}


const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecuteGrade() const
{
    return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (_isSigned)
        throw AlreadySignedException();
    else if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    else if (_executeGrade < executor.getGrade())
        throw GradeTooLowException();
    action();
}