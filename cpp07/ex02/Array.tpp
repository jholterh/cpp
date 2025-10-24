#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(0), _len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _len(n) {}

template <typename T>
Array<T>::Array(const Array &copy) : _data(new T[copy._len]), _len(copy._len)
{
    for (unsigned int i = 0; i < _len; i++)
        _data[i] = copy._data[i];
    
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _data;
        _len = other._len;
        _data = new T[_len];
        for (unsigned int i = 0; i < _len; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _len)
        throw std::out_of_range("Index out of bounds");
    return _data[i];
}
template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= _len)
        throw std::out_of_range("Index out of bounds");
    return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _len;
}