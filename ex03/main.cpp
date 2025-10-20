#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>  // std::srand, std::rand
#include <ctime>    // std::time

int main() {
    std::srand(std::time(NULL));
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 150);

    std::cout << "This is what the Forms should do: " << std::endl;
    std::cout << "-----------------------------------------------\n" << std::endl;
    ShrubberyCreationForm shrubbyForm("Isa");
    alice.signForm(shrubbyForm);
    alice.executeForm(shrubbyForm);
    std::cout << "Check the newly created files" << std::endl;
    std::cout << "-----------------------------------------------\n" << std::endl;

    RobotomyRequestForm robForm("Rob");
    alice.signForm(robForm);
    alice.executeForm(robForm);
    alice.executeForm(robForm);
    alice.executeForm(robForm);
    alice.executeForm(robForm);
    alice.executeForm(robForm);
    std::cout << "-----------------------------------------------\n" << std::endl;

    PresidentialPardonForm presForm("Milan");
    alice.signForm(presForm);
    alice.executeForm(presForm);
    std::cout << "-----------------------------------------------\n" << std::endl;

    std::cout << "Test: Level is not high enough" << std::endl;
    bob.executeForm(shrubbyForm);
    bob.executeForm(robForm);
    bob.executeForm(presForm);
    std::cout << "-----------------------------------------------\n" << std::endl;

    std::cout << "Test: Form has not been signed yet" << std::endl;
    ShrubberyCreationForm A("A");
    RobotomyRequestForm B("B");
    PresidentialPardonForm C("C");
    alice.executeForm(A);
    alice.executeForm(B);
    alice.executeForm(C);
    std::cout << "-----------------------------------------------\n" << std::endl;

    return 0;
}
