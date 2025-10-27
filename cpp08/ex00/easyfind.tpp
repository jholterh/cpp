#pragma once
#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(const T &container, int num)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}   