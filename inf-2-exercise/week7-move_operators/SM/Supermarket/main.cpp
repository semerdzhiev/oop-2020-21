#include <iostream>

#include "Product.h"
#include "ProductCollection.h"

int main() {
    Product p1("cubrica", 0.45, 0.55);
    Product p2("kashkaval", 4.5, 4.5);

    std::cout<< "p1 and p2 are"<< ((p1 == p2) ? "" : " not")<< " eqal" << std::endl;

    ProductCollection pc;
    pc.add(p1);
    pc.add(p2);

    ProductCollection pc2(pc);

    //pc.clean();

    ProductCollection sum = pc + pc2;
    sum.print();

    //pc += pc2;
    //pc.print();

    return 0;
}