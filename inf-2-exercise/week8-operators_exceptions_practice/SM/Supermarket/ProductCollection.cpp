#include "ProductCollection.h"

ProductCollection::ProductCollection(int capacity) : size(0), capacity(capacity) {
    products = new Product[capacity];
}

ProductCollection::ProductCollection(const ProductCollection& other) {
    copy(other, false);
}

ProductCollection::~ProductCollection() {
    clean();
}

ProductCollection& ProductCollection::operator=(const ProductCollection& other) {
    if (&other != this) {
        copy(other);
    }

    return *this;
}

ProductCollection ProductCollection::operator+(const ProductCollection& other) {
    ProductCollection pc(*this);

    for (int i = 0; i < other.size; ++i) {
        pc.add(other.products[i]);
    }

    return pc;
}

ProductCollection& ProductCollection::operator+=(const ProductCollection& other) {
    return (*this = (*this + other));
}

Product& ProductCollection::operator[](int index) {
    return getAt(index);
}

Product& ProductCollection::getAt(int index) {
    if (index > size - 1) {
        throw std::exception("out of bounds");
    }

    return products[index];
}

int ProductCollection::getSize() const {
    return size;
}

void ProductCollection::remove(std::string name) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (products[i].getName() == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        products[i] = products[i + 1];
    }
    --size;
}

void ProductCollection::add(const Product& newProduct) {
    if (size + 1 > capacity || capacity == 0) {
        capacity = (capacity == 0) ? 8 : capacity *= 2;
        Product* newData = new Product[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = products[i];
        }
        delete[] products;
        products = newData;
    }
    products[size++] = newProduct;
}

void ProductCollection::clean() {
    delete[] products;
    products = nullptr;
    size = 0;
    capacity = 0;
}

void ProductCollection::copy(const ProductCollection& other, bool doClean) {
    if (doClean) {
        clean();
    }

    size = other.size;
    capacity = other.capacity;
    products = new Product[capacity];

    for (int i = 0; i < size; ++i) {
        products[i] = other.products[i];
    }
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

double ProductCollection::getPrice() const {
    double sum = 0;
    
    for (int i = 0; i < size; ++i) {
        sum += products[i].getCurrPrice();
    }

    return sum;
}

void ProductCollection::print(std::ostream& out) const {
    for (int i = 0; i < size; ++i) {
        products[i].print(out);
    }
}

std::ostream& operator<<(std::ostream& out, const ProductCollection& pc) {
    pc.print(out);
    return out;
}
