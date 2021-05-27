#include <iostream>
using namespace std;

class D {
public:
    int a;
    D() {cout<<"D()"<<endl;}
    D(int a) {cout<<"D(int)"<<endl;}
    ~D() {cout<<"~D()"<<endl;}
    static void print() {
        cout<<"D";
    }
};

class B: virtual public D {
public:
    B() {cout<<"B()"<<endl;}
    B(int a) {cout<<"B(int )"<<endl;}
    ~B() {cout<<"~B()"<<endl;}
};

class C: virtual public D {
public:

    C() {cout<<"C()"<<endl;}
    C(int a) {cout<<"C(int )"<<endl;}
    ~C() {cout<<"~C()"<<endl;}

};

class A: public C, public B {
public:
    A() {
        cout<<"A()"<<endl;
    }
    A(int a): C(a), B(a), D(a) {
        cout<<"A(int)"<<endl;
    }
    ~A() {cout<<"~A()"<<endl;}

//    void print() override {
//        cout<<'A';
//    }
};


int main() {
    A* a = new A;
    D* d = new A;
    d->print();
    delete d;
    delete a;

}
