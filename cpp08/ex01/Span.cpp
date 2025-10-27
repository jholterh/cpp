#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : _max(0), _array(0), _currentSize(0) {}

Span::Span(unsigned int n) : _max(n), _currentSize(0)
{
    _array = new int[n];
}

Span::Span(const Span &copy) : _max(copy._max), _currentSize(copy._currentSize)
{
    _array = new int[_max];
    std::copy(copy.begin(), copy.end(), _array);
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max = other._max;
        _currentSize = other._currentSize;
        delete[] _array;
        _array = new int[_max];
        std::copy(other.begin(), other.end(), _array);
    }
    return *this;
}

Span::~Span()
{
    delete[] _array;
}

const int *Span::begin() const
{
    return _array;
}

const int *Span::end() const
{
    return _array + _currentSize;
}

int *Span::begin()
{
    return _array;
}

int *Span::end()
{
    return _array + _currentSize;
}

void Span::addNumber(int num)
{
    if (_currentSize + 1 > _max)
        throw std::out_of_range("Span is full");
    _array[_currentSize] = num;
    _currentSize++;
}

int Span::shortestSpan() const
{
    if (_currentSize < 2)
        throw std::logic_error("Not enough values to find the shortest span");
    int *tmp = new int[_currentSize];
    std::copy(begin(), end(), tmp);
    std::sort(tmp, tmp + _currentSize);
    int shortest = tmp[1] - tmp[0];
    for (int i = 2; i < _currentSize; i++)
    {
        if (shortest > tmp[i] - tmp[i - 1])
            shortest = tmp[i] - tmp[i - 1];
    }
    delete[] tmp;
    return shortest;
}