#pragma once

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &other);
        ~Array();

        T &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;

        unsigned int size() const;

    private:
        T *_data;
        unsigned int _len;
};

#include "Array.tpp"

#endif