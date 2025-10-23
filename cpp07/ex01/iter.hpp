#pragma once
#include <iostream>

template <typename T, typename  F>
void iter(T *array, const int length, F function)
{
    for (int i = 0; i < length; i++)
    {
        function(array[i]);
    }
}

template <typename T>
void print_all(const T &input)
{
    std::cout << input << std::endl;
}

