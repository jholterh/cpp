#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>  // std::srand, std::rand
#include <ctime>    // std::time

int main() {
    std::srand(std::time(NULL));

    std::cout << "Test: Normal execution part 1\n" << std::endl;
    try
    {
        Intern Isa;
        AForm *shrub = Isa.makeForm("ShrubberyCreationForm", "kitchen");
        Bureaucrat john("John", 4);
        john.signForm(*shrub);
        john.executeForm(*shrub);
        delete (shrub);
    }
    catch (const std::exception &e)
    {
        std::cout << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------\n" << std::endl;
    std::cout << "Test: Normal execution part 2\n" << std::endl;
    try
    {
        Intern Isa;
        AForm *robo = Isa.makeForm("RobotomyRequestForm", "kitchen");
        Bureaucrat john("John", 4);
        john.signForm(*robo);
        john.executeForm(*robo);
        delete (robo);
    }
    catch (const std::exception &e)
    {
        std::cout << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------\n" << std::endl;
    std::cout << "Test: Normal execution part 3\n" << std::endl;
    try
    {
        Intern Isa;
        AForm *pres = Isa.makeForm("PresidentialPardonForm", "kitchen");
        Bureaucrat john("John", 4);
        john.signForm(*pres);
        john.executeForm(*pres);
        delete (pres);
    }
    catch (const std::exception &e)
    {
        std::cout << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------\n" << std::endl;
    std::cout << "Test: Form that does not exist\n" << std::endl;
    try
    {
        Intern Isa;
        AForm *non = Isa.makeForm("42Form", "kitchen");
        Bureaucrat john("John", 4);
        john.signForm(*non);
        john.executeForm(*non);
        delete (non);
    }
    catch (const std::exception &e)
    {
        std::cout << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------------\n" << std::endl;
    std::cout << "Test: constructors...\n" << std::endl;
    try
    {
        Intern Isa;
        Intern Ben(Isa);
        AForm *pres = Ben.makeForm("PresidentialPardonForm", "kitchen");
        Bureaucrat john("John", 4);
        john.decrementGrade();
        john.signForm(*pres);
        john.executeForm(*pres);
        delete (pres);
    }
    catch (const std::exception &e)
    {
        std::cout << "Intern couldn't create the form because " << e.what() << std::endl;
    }
    return 0;
}
