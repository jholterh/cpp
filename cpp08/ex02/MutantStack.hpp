#pragma once

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator.begin();
        iterator.end();

        const_iterator.begin();
        const_iterator.end();
};

#include "MutantStack.tpp"

#endif