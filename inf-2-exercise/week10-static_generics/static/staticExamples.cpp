#include <iostream>
using namespace std;

int f1() {
    int val = 5;
    val++;

    return val;
}

int f2() {
    static int val = 5;
    val++;

    return val;
}

int main() {
    cout<< "non-static local variable example"<< endl;
    cout<< f1()<< " "<< f1()<< endl;

    cout<< "static local variable example"<< endl;
    cout<< f2()<< " "<< f2()<< endl;

    return 0;
}
