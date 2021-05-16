#include <iostream>

class A {
public:
    char a = 'a';
};

//base class I
class B :  public A {
public:
    char b = 'b';
};

//base class II
class C :  public A {
public:
    char c = 'c';
};

//derived class
class D : public B, public C {
public:
    char d = 'd';
};

int main() {
    D d;
    std::cout<<d.d<<std::endl;
    return 0;
}
