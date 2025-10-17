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
    Bureaucrat bob("Bob", 100);

    ShrubberyCreationForm shrubbyForm("Isa");
    alice.signForm(shrubbyForm);
    bob.executeForm(shrubbyForm);

    RobotomyRequestForm robForm("Rob");
    bob.signForm(robForm);
    alice.signForm(robForm);
    alice.executeForm(robForm);

    PresidentialPardonForm presForm("Milan");
    alice.signForm(presForm);
    alice.executeForm(presForm);

    return 0;
}
