#include <iostream>
using namespace std;

class A {
public:
    virtual void print() {cout<<"class A"<<endl;}

};

class B : public A {
public:
    void print() override {cout<<"class B"<<endl;}
    // void print1() override {cout<<"error";} // error, print1 is not defined in class A
};

class D {
public:
    virtual void printable () = 0;
    void test() {cout<<"Test..."<<endl;}
};

class E : public D {
public:
    void printable() final { cout<<"print E"<<endl;}
    void printable1() {cout<<"Hello World..."<<endl;}
};

class F : public D {
public:
    void printable() override { cout<<"print F"<<endl;}
};

class G : public E {
public:
    // void printable() { cout<<"print F";} error because class E has final for printable
};

void print(D* d) {
    d->printable();
    d->test();
    cout<<endl;
}

/* - Error - static function could not be virtual
virtual int ten () {
    return 10;
}*/

int main() {

    A a;
    a.print();
    cout<<"---"<<endl;
    B b;
    b.print();
    cout<<"---"<<endl;
    A* c = &b;
    c->print();
    //D d;
    E e;
    D* d = &e;
    d->printable();
    print(d);
    F f;
    print(&f);

    return 0;
}
