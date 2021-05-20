#include <iostream>
#include "List.h"

template <typename T = int, typename T2 = int>
class Pair {
    T first;
    T2 second;

    T getFirst() const {
        return first;
    }
};

bool isEven(int n) {
    return n % 2 == 0;
}

int multiply(int x) {
    return x * 10;
}

double int2double(int x) {
    return x * 1.1;
}

int sum(int a, int b) {
    return a + b;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };

    List<int> list(arr, 5);
    list.print();

    list.filter(isEven).print();
    list.genFilter(isEven).print();

    list.map(multiply).print();

    std::cout << list.reduce(sum, 10) << std::endl;

    return 0;
}
