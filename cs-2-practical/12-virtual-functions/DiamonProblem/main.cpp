#include <iostream>

class A {
public:
    char a = 'a';
};

//    A
//   / \
//   B  C
//    \ /
//     D

//base class I
class B : virtual public A {
public:
    char b = 'b';
};

//base class II
class C : virtual public A {
public:
    char c = 'c';
};

//derived class
class D : public B, public C {
public:
    char d = 'd';
};

class E : public D{
public:
    char e = 'e';
};

int main() {
    D d; E e;
    std::cout << d.a <<'\n'<<e.a<< std::endl;
    return 0;
}
