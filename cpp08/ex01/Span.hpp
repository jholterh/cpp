#pragma once

#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstddef> 

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
        
    private:
        int *_array;
        int _max;
        int _currentSize;

};

#endif