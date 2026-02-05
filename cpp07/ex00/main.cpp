#include "whatever.hpp"
#include <iostream>

int main(void)
{
    std::cout << "my tests:" << std::endl;
    std::cout << "\t\tx = 5, y = 2\n" << std::endl;

    int x = 5, y = 2;

    std::cout << "print the smaller one: " << min(x, y) << std::endl;

    std::cout << "print the larger one: " << max(x, y) << "\n" << std::endl;

    swap(x, y);

    std::cout << "after swaping:\tx = " << x << ", y = " << y << "\n" << std::endl;

    std::cout << "print the smaller one: " << min(x, y) << std::endl;

    std::cout << "print the larger one: " << max(x, y) << std::endl;


    std::cout << "\nboth the same number:" << std::endl;
    x = 5;

    std::cout << "\t\tx = 5, y = 5\n" << std::endl;

    std::cout << "print the smaller one: " << min(x, y) << std::endl;

    std::cout << "print the larger one: " << max(x, y) << "\n" << std::endl;

    swap(x, y);

    std::cout << "after swaping:\tx = " << x << ", y = " << y << "\n" << std::endl;

    std::cout << "print the smaller one: " << min(x, y) << std::endl;

    std::cout << "print the larger one: " << max(x, y) << std::endl;

    std::cout << "\n------------------------------------" << std::endl;
    std::cout << "official tests:" << std::endl;

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}