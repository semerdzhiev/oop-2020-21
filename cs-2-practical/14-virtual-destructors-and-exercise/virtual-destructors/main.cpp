#include <iostream>
#include <vector>

class Base
{
public:
    Base() { std::cout << "Base: Constructor\n"; }
    virtual ~Base() { std::cout << "Base: Destructor\n"; }
    virtual void test() { std::cout << "base\n"; }
};

class Derived : public Base
{
    int *arr;

public:
    Derived()
    {
        arr = new int[5];
        std::cout << "Derived: Constructor\n";
    }
    ~Derived()
    {
        delete[] arr;
        std::cout << "Derived: Destructor\n";
    }
    void test() { std::cout << "der\n"; }
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
    poly->test();
    delete poly;
    return 0;
}