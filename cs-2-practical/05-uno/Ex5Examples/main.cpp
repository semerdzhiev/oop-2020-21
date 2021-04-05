#include <iostream>

class A {
public:
    A() {
        std::cout << "Constructor of A invoked!\n";
    }

    A(const char *str) {
        std::cout << "Constructor of A invoked:" << str << '\n';
    }
};


class B {
    A a;
    int n; // 0 < n < 10
    mutable int k;
public:
    B(int _n) : a("duma"), n(_n),k(0) {
        if (n <= 0 || n >= 10) {
            n = -1;
        }
    }

    int getN() const {
        k++;
        return n;
    }
};

void f(const B &b) {
    int n = b.getN();
}

int main() {
    B b(5);
    std::cout << b.getN()<<'\n';

    B* pointer;
    {
        B *n= new B(9);
        pointer=n;
    }
    std::cout<<pointer->getN()<<'\n';
    delete pointer;
    return 0;
}
