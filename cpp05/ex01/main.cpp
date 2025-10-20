#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat alice("Alice", 5);
    Bureaucrat bob("Bob", 100);

    Form taxForm("Tax Form", 10, 50);
    Form secretForm("Secret Form", 1, 1);

    std::cout << "Alice should succeed:" << std::endl;
    // Should succeed
    alice.signForm(taxForm);
    std::cout << "\n-----------------------------------------------\n" << std::endl;

    std::cout << "Bob should fail:" << std::endl;
    // Should fail (grade too low)
    bob.signForm(taxForm);
    std::cout << "\n-----------------------------------------------\n" << std::endl;

    std::cout << "Bob should fail:" << std::endl;
    // Should fail (grade too low)
    bob.signForm(secretForm);
    std::cout << "\n-----------------------------------------------\n" << std::endl;

    std::cout << "Alice should succeed:" << std::endl;
    // Should succeed
    alice.signForm(secretForm);
    std::cout << "\n-----------------------------------------------\n" << std::endl;

    // Test grade bounds
    std::cout << "Invalid Test Form:" << std::endl;
    try {
        Form badForm("Invalid", 0, 10); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    std::cout << "Invalid Test Form:" << std::endl;
    try {
        Form badForm2("Invalid", 10, 151); // Should throw
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    return 0;
}
