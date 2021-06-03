#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class Furniture {
    static long CURR_ID;

protected:
    long id;
    long length;
    long width;
    long height;
    double price;
    int qty;
    Furniture(long length, long width, long height, double price, int qty);

public:
    Furniture();
    long getId() const;
    long getLength() const;
    long getWidth() const;
    long getHeight() const;
    double getPrice() const;
    int getQty() const;
    void addQty(int);
    void removeQty(int);

    virtual void print(ostream &out) const;
};