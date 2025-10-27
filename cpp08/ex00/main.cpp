#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    // Test mit std::vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(42);
    vec.push_back(5);

    std::cout << "=== Testing with std::vector ===" << std::endl;
    try {
        std::vector<int>::const_iterator it = easyfind(vec, 42);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 99);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test mit std::list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::cout << "\n=== Testing with std::list ===" << std::endl;
    try {
        std::list<int>::const_iterator it = easyfind(lst, 20);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(lst, 100);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test mit std::deque
    std::deque<int> deq;
    deq.push_back(7);
    deq.push_back(14);
    deq.push_back(21);

    std::cout << "\n=== Testing with std::deque ===" << std::endl;
    try {
        std::deque<int>::const_iterator it = easyfind(deq, 14);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
