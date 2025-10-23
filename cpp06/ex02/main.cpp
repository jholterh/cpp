#include "Base.hpp"
#include "A.hpp"

int main(void)
{
    std::srand(std::time(NULL));

    Base *random =  generate();
    identify(random);
    identify(*random);
}