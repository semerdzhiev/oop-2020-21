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

//interface
class Printable {
public:
    virtual void print()=0;
};

struct Point : public Printable {
    float x=0;
    float y=0;
    explicit Point(float x=0,float y=0) : x(x), y(y) {}

    void print() override {
        printf("(x,y)=(%f,%f)\n",x,y);
    }
};

int main() {
    A a;
    B b;
    a.getName();b.getName();
    A* bPtr = new B();
    bPtr->getName();
    //Printable p;
    Point p(2.2,3.5);
    p.print();
    return 0;
}
