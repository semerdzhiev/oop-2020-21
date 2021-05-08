#include <iostream>

class A {
protected:
    char c;
public:
    A(char _c = 'a') : c(_c) {}

    virtual void getName() {
        std::cout << "My name is A and I've got " << c << " in my char variable!\n";
    }
};

class B : public A {
public:
    B(char _c = 'b') : A(_c) {}

    void getName() override {
        std::cout << "My name is B and I've got " << c << " in my char variable!\n";
    }

};

int main() {
    A a;
    B b;
    a.getName();b.getName();
    A* bPtr = new B();
    bPtr->getName();
    return 0;
}
