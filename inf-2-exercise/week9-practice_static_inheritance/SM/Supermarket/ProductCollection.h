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

    ProductCollection operator+(const ProductCollection& other);
    ProductCollection& operator+=(const ProductCollection& other);

    const Product& operator[](int index) const;
    Product& operator[](int index);

    const Product& getAt(int index) const;
    Product& getAt(int index);

    int getSize() const;
    void remove(std::string name);

    void add(const Product& newProduct);
    void clean();
    void copy(const ProductCollection& other, bool doClean = true);

    Product& cheapest();
    ProductCollection withDiscount();
    Product& cheapestWithDiscount();

    double getPrice() const;

    void print(std::ostream& out) const;
};

std::ostream& operator<<(std::ostream& out, const ProductCollection& pc);
