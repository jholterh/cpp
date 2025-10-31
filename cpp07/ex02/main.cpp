#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> numbers(5);
    for (int i = 0; i < 5; i++)
        numbers[i] = i * 3;
    
    std::cout << "numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    Array<std::string> words(2);
    words[0] = "Milan";
    words[1] = "Gabriel";

    std::cout << "words: ";
    for (unsigned int i = 0; i < words.size(); i++)
        std::cout << words[i] << " ";
    std::cout << std::endl;

    Array<int> copy_numbers(numbers);
    copy_numbers[1] = 69;

    std::cout << "copied numbers: ";
    for (unsigned int i = 0; i < copy_numbers.size(); i++)
        std::cout << copy_numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "old numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    try
    {
        std::cout << numbers[6] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception called: " << e.what() << '\n';
    }

    const Array<std::string> constWords(words);
    std::cout << "constWords[1]: " << constWords[1] << std::endl;
    return 0;
}
