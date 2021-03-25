#include <iostream>
#include "triangle.h"

using std::cout;
using std::endl;

int main() {
    Triangle myTriangle;

    myTriangle.read();
    cout << "Perimeter: " << myTriangle.perimeter() << endl;
    cout << "Area: " << myTriangle.area() << endl;

    return 0;
}