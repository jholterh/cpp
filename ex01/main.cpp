#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 100);

    Form taxForm("Tax Form", 10, 50);
    Form secretForm("Secret Form", 1, 1);

    // Should succeed
    alice.signForm(taxForm);

    // Should fail (grade too low)
    bob.signForm(taxForm);

    // Should fail (grade too low)
    bob.signForm(secretForm);

    // Should succeed
    alice.signForm(secretForm);

    // Test grade bounds
    try {
        Form badForm("Invalid", 0, 10); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form badForm2("Invalid", 10, 151); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
