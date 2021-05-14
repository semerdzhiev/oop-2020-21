#include <iostream>
using namespace std;

class Calculator {
    Calculator() {}
public:
    static Calculator& getSharedInstance() {
        // because it's static, it's only created once
        static Calculator calc;
        return calc;
    }

    int add(int a, int b) {
        return a+b;
    }
};

int main() {
    cout<< Calculator::getSharedInstance().add(1,2)<< endl;

    return 0;
}
