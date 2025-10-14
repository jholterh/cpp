#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1000);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("Peter", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat c("Isa", 124);
        c.decrementGrade();
        c.incrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}