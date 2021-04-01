#include "Product.h"
#include "ProductCollection.h"

int main() {
    Product p1("cubrica", 0.45, 0.55);
    Product p2("kashkaval", 4.5, 4.5);

    ProductCollection pc;
    pc.add(p1);
    pc.add(p2);

    ProductCollection pc2(pc);

    pc.clean();

    pc2.print();

    return 0;
}