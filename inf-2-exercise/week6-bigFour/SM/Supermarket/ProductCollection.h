#pragma once

#include "Product.h"

class ProductCollection {
    Product* products;
    int size;
    int capacity;

public:
    ProductCollection(int capacity = 10);
    ProductCollection(const ProductCollection& other);
    ~ProductCollection();
    ProductCollection& operator=(const ProductCollection& other);

    Product& getAt(int index);

    void add(const Product& newProduct);
    void clean();
    void copy(const ProductCollection& other);

    Product& cheapest();
    ProductCollection withDiscount();
    Product& cheapestWithDiscount();

    void print();
};

