#include <iostream>
#include <fstream>

#include "Product.h"
#include "ProductCollection.h"

int main() {
    Product p1("cubrica", 0.45, 0.55);
    Product p2("kashkaval", 4.5, 4.5);

    ProductCollection pc;
    pc.add(p1);
    pc.add(p2);

    ProductCollection pc2(pc);
    Product p3("sirene", 3.5, 3.5);
    pc2.add(p3);

    pc += pc2;
    //pc.print();

    std::cout << pc<< std::endl;

    std::fstream f("output.txt", std::ios::out);
    f << pc;
    f.close();

    try {
        Product& pt = pc[12];
        std::cout<< pt;
    } catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << pc.getPrice()<< std::endl;

    return 0;
}