#ifndef BACKPACK
#define BACKPACK

#include "item.h"
#include "exceptions.h"

class Backpack {

private:
    const static int INITIAL_SIZE = 8;

    Item* items;
    int count;

    double volume;
    double maxWeight;

public:
    Backpack();
    Backpack(double volume, double maxWeight);

    void add(const Item &item);
    int size();
    double leftVolume();
    double leftWeight();

    Item &operator[](int const position);

    ~Backpack();
};

#endif