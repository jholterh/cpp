#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
    const std::string fileName = _target + "_shrubbery";
    std::ofstream ofs(fileName.c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not open file '" << fileName << "' for writing" << std::endl;
        return ;  
    }
    ofs <<
        "       _-_        \n"
        "    /~~   ~~\\    \n"
        " /~~         ~~\\ \n"
        "{               }\n"
        " \\  _-     -_  / \n"
        "   ~  \\\\ //  ~   \n"
        "_- -   | | _- _   \n"
        "  _ -  | |   -_   \n"
        "      // \\\\       \n";
    ofs.close();
}