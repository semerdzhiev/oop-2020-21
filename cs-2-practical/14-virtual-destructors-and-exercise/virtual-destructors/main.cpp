#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base: Constructor\n"; }
    virtual ~Base() { std::cout << "Base: Destructor\n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived: Constructor\n"; }
    ~Derived() { std::cout << "Derived: Destructor\n"; }
};

int main()
{
    Base *base = new Base();
    delete base;
    std::cout << "---------------------\n";
    Derived *derived = new Derived();
    delete derived;
    std::cout << "---------------------\n";
    Base *poly = new Derived();
    delete poly;
    return 0;
}