#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 100);

    ShrubberyCreationForm shrubbyForm1("Isa");
    ShrubberyCreationForm shrubbyForm2("Milan");
    alice.signForm(shrubbyForm1);
    bob.executeForm(shrubbyForm1);
    alice.signForm(shrubbyForm2);
    bob.executeForm(shrubbyForm2);
    return 0;
}
