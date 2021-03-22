#include <iostream>
#include "Car.h"
#include "EngineDetails.h"
using std::cin;

class A {
    int a;
public:
    A(int _a=0);
};

A::A(int _a):a(_a) {
    std::cout<<a<<'\n';
}


int main()
{
    EngineDetails ed;
    ed.readFromConsole();
    ed.print();
    A a(4);

    return 0;
}
