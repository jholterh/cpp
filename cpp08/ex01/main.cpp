#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Test 1: add more numbers than max" << std::endl;
    Span twoNum(1);
    twoNum.addNumber(1);
    try
    {
        twoNum.addNumber(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 2: Span with just one number (shortestSpan)" << std::endl;
    try
    {
        twoNum.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "Test 3: Span with just one number (longestSpan)" << std::endl;
    try
    {
        twoNum.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    twoNum.printSpan();
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 4: three numbers success" << std::endl;
    Span threeNum(3);
    threeNum.addNumber(-100);
    threeNum.addNumber(-1);
    threeNum.addNumber(10);
    threeNum.printSpan();
    std::cout << "Shortest Span: " << threeNum.shortestSpan() << ", Longest Span: " << threeNum.longestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 5: subject tests" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 6: Duplicate numbers (shortest span = 0)" << std::endl;
    Span duplicates(5);
    duplicates.addNumber(5);
    duplicates.addNumber(5);
    duplicates.addNumber(10);
    std::cout << "Shortest Span: " << duplicates.shortestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 7: Add numbers with range (vector)" << std::endl;
    Span large(1005);
    large.addNumbers(sp.begin(), sp.end());
    large.printSpan();
    std::vector<int> numbers;
    for (int i = 0; i < 1000; i++)
        numbers.push_back(i);
    large.addNumbers(numbers.begin(), numbers.end());
    std::cout << "Shortest Span: " << large.shortestSpan() << ", Longest Span: " << large.longestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 8: Add numbers with range (array)" << std::endl;
    Span fromArray(10);
    int arr[] = {100, 200, 300, 400, 500};
    fromArray.addNumbers(arr, arr + 5);
    fromArray.printSpan();
    std::cout << "Shortest Span: " << fromArray.shortestSpan() << ", Longest Span: " << fromArray.longestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 9: Add numbers with range overflow" << std::endl;
    Span smallSpan(5);
    std::vector<int> tooMany;
    for (int i = 0; i < 10; i++)
        tooMany.push_back(i);
    try
    {
        smallSpan.addNumbers(tooMany.begin(), tooMany.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 10: 10,000+ numbers" << std::endl;
    Span huge(10000);
    std::vector<int> manyNumbers;
    for (int i = 0; i < 10000; i++)
        manyNumbers.push_back(i * 3);  // 0, 3, 6, 9, ...
    huge.addNumbers(manyNumbers.begin(), manyNumbers.end());
    std::cout << "Added 10,000 numbers successfully" << std::endl;
    std::cout << "Shortest Span: " << huge.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << huge.longestSpan() << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    
    std::cout << "Test 11: 15,000 numbers" << std::endl;
    Span massive(15000);
    std::vector<int> evenMore;
    for (int i = 0; i < 15000; i++)
        evenMore.push_back(i);
    massive.addNumbers(evenMore.begin(), evenMore.end());
    std::cout << "Added 15,000 numbers successfully" << std::endl;
    std::cout << "Shortest Span: " << massive.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << massive.longestSpan() << std::endl;
    
    return 0;
}
