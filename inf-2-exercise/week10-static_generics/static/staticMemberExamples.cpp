#include <iostream>
using namespace std;

class A {
    static int val;

public:
    A() {
        ++val;
    }

    int getVal() {
        return val;
    }
};

// we need to initialize our static variables
int A::val = 5;

int main() {
    A a1;
    cout<< a1.getVal()<< endl;

    A a2;
    cout<< a1.getVal()<< endl;
    cout<< a1.getVal()<< endl;

    return 0;
}

