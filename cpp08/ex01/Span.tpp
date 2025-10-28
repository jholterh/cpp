#pragma once
#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    int count = std::distance(begin, end);
    if (_currentSize + count > _max)
        throw std::out_of_range("Numbers don't fit into Span");
    for (Iterator it = begin; it != end; it++)
        _array[_currentSize++] = *it;
}