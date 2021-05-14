#include <iostream>
using namespace std;

template<typename T>
class A {
    T val;

public:
    A(T val): val(val) {}
    T getVal() {
        return val;
    }
};

int main() {
    A<int> a1(5.6);
    cout<< a1.getVal()<< endl;

    A<double> a2(5.6);
    cout<< a2.getVal()<< endl;

    return 0;
}
