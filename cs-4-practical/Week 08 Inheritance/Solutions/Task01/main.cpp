#include <iostream>
#include "shape.h"
#include "rectangular.h"
#include "colored_rectangular.h"
#include "square.h"
#include "triangle.h"

using std::cout;
using std::endl;

int main() {

    Shape shape;
    shape.print();
    cout << endl;

    Rectangular rect(2, 3);
    rect.print();
    cout << endl;

    ColoredRectangular coloredRect("red", 5, 6);
    coloredRect.print();
    cout << endl;

    Square square(4);
    square.print();
    cout << endl;

    Triangle triangle(3, 4, 5);
    triangle.print();

    return 0;
}