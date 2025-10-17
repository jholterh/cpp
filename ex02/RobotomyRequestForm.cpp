#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib> // std::srand, std::rand
#include <ctime>   // std::time

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
    std::cout << "LOUD DRILLING NOISE" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}