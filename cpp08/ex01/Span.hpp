#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef>
#include <iostream>
class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);
        const int *begin()const;
        const int *end() const;
        int *begin();
        int *end();
        int shortestSpan() const;
        int longestSpan() const;
        void printSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);
        
    private:
        int *_array;
        int _max;
        int _currentSize;

};

#include "Span.tpp"


#endif