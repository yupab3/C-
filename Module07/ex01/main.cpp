#include <iostream>
#include <typeinfo>
#include "iter.hpp"

class A
{
public:
    static void funcA(const double a);
};

void A::funcA(const double a)
{
    std::cout << "static member func, " << a;
    const std::type_info& type = typeid(a);
    std::cout << ", type = " << type.name() << '\n';
}

static void    funcStatic(int a)
{
    std::cout << "static overload func, " << a;
    const std::type_info& type = typeid(a);
    std::cout << ", type = " << type.name() << '\n';
}

int main()
{
    const double a[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    iter(a, 6, funcStatic);
    iter(a, 6, funcTemplate<double>);
    iter(a, 6, A::funcA);
    return 0;
}
