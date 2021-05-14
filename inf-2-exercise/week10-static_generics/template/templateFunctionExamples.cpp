#include <iostream>

/*int max(int a, int b) {
    return (a < b) ? b : a;
}

double max(double a, double b) {
    return (a < b) ? b : a;
} */

template<typename T>
T max(T a, T b) {
    return (a < b) ? b : a;
}

int main() {
    int i1 = 5, i2 = 6;
    std::cout<< max(i1, i2)<< std::endl;

    double d1 = 4.5, d2 = 6.75;
    std::cout<< max(d1, d2)<< std::endl;

    return 0;
}
