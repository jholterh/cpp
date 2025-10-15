#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\nInformation: Lowest grade is 150, highest grade is 1" << std::endl;
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    try
    {
        std::cout << "Test: Bureaucrat grade 1000" << std::endl;
        Bureaucrat a("Alice", 1000);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    try
    {
        std::cout << "Test: Bureaucrat grade 0" << std::endl;
        Bureaucrat b("Peter", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    try
    {
        std::cout << "Test: Decrementing and Incramenting a valid grade" << std::endl;
        Bureaucrat c("Isa", 124);
        std::cout << "Before incrementing: " << c << std::endl;
        c.incrementGrade();
        std::cout << "After incrementing and before decrementing: " << c << std::endl;
        c.decrementGrade();
        std::cout << "After decrementing it back: " << c << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n-----------------------------------------------\n" << std::endl;
    try
    {
        std::cout << "Test: Incrementing to a non valid grade" << std::endl;
        Bureaucrat d("Milan", 1);
        std::cout << "Before incrementing: " << d << std::endl;
        d.incrementGrade();
        std::cout << "SHOULD NOT PRINT" << d << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}