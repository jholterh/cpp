#include "iter.hpp"
#include <string>

void print_int_plus1(int number)
{
    number++;
    std::cout << number << std::endl;
}

int main()
{
    int nothing[] = {};
    int array[] = {1, 3, 6};
    const float floats[] = {2.0, 3.5, 6.2};
    std::string words[] = {"hey", "hello"};

    iter(array, 3, print_int_plus1);
    // iter(words, 2, print_int); should not work
    std::cout << std::endl;

    iter(array, 3, print_all<int>);

    std::cout << std::endl;

    iter(words, 2, print_all<std::string>);

    std::cout << std::endl;

    iter(floats, 3, print_all<float>);

    std::cout << std::endl;

    iter(nothing, 0, print_all<int>);
}