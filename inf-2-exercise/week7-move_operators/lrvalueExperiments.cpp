#include <iostream>
using namespace std;

int getVar(int& x) {
    return x;
}

int main() {
    // lvalue
    int a = 5;
    getVar(a) = a+7;

    return 0;
}
