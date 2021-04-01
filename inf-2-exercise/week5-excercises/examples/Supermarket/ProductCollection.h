#pragma once

#include "Product.h"

class ProductCollection {
    Product products[30];
    int size;

public:
    ProductCollection() : size(0) {}

    Product& getAt(int index);

    void add(const Product& newProduct);
    Product& cheapest();
    ProductCollection withDiscount();
    Product& cheapestWithDiscount();
};

