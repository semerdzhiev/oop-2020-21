#include <iostream>
#include "Complex.h"

int main() {
    Complex n ={2,3};
    Complex m ={3,3};
    Complex res1 = add(n,m);
    Complex res2 = multiply(n,m);
    print(res1);
    print(res2);
    print(Complex{-5,-2});
    return 0;
}
