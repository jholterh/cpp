#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
    int i = std::rand() % 3;

    switch (i)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "It's type A!" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "It's type B!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "It's type C!" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "It's type A!" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "It's type B!" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "It's type C!" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
        std::cout << "Mistakes happen" << std::endl;
    }        
}