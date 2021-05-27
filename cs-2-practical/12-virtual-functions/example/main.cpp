#include <iostream>
#include<string>

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

// pure virtual functions
//interface- abstract class
class Printable {
public:
    virtual void print() = 0;
};

struct Point : public Printable {
    float x = 0;
    float y = 0;

    explicit Point(float x = 0, float y = 0) : x(x), y(y) {}

    void print() override {
        printf("(x,y)=(%f,%f)\n", x, y);
    }
};

struct Point3d : public Printable {
    float x;
    float y;
    float z;

    explicit Point3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void print() override {
        printf("(x,y,z)=(%f,%f,%f)\n", x, y, z);
    }
};

int main() {
    A a;
    B b;
    a.getName();
    b.getName();
    A *bPtr = new B();
    A *aPtr = new A();
    aPtr->getName();
    bPtr->getName();
    std::cout << '\n';
    //Printable p;
    Point p(2.2, 3.5);
    p.print();
    Printable *point = new Point(1, 1);
    point->print();
    std::cout << '\n';
    short choice;
    std::cin>>choice;
    Printable* printable;
    if(choice==0) {
        printable = new Point(2,5);
    } else {
        printable = new Point3d(2,3,4);
    }
    printable->print();
    Printable** arr = new Printable*[2];
    arr[0] = new Point[2];
    arr[1] = new Point3d[2];
    arr[0][0].print();
    arr[1][0].print();
    return 0;
}