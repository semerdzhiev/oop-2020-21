#include "ProductCollection.h"

Product& ProductCollection::getAt(int index) {
    return products[index];
}

void ProductCollection::add(const Product& newProduct) {
    products[size++] = newProduct;
}

Product& ProductCollection::cheapest() {
    int minIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (products[i].cheaper(products[minIndex])) {
            minIndex = i;
        }
    }

    return products[minIndex];
}

ProductCollection ProductCollection::withDiscount() {
    ProductCollection pcd;
    for (int i = 0; i < size; ++i) {
        if (products->withDiscount()) {
            pcd.add(products[i]);
        }
    }

    return pcd;
}

Product& ProductCollection::cheapestWithDiscount() {
    return withDiscount().cheapest();
}
