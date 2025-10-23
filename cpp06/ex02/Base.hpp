#pragma once

#ifndef BASE
#define BASE

#include <cstdlib> // std::srand, std::rand
#include <ctime>   // std::time
#include <iostream>

class Base
{
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif