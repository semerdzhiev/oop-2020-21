#include <iostream>
#include "backpack.h"

Backpack::Backpack() {
    count = 0;
    items = new (std::nothrow) Item[count];
    volume = 0;
    maxWeight = 0;
}

Backpack::Backpack(double volume, double maxWeight) {
    count = 0;
    items = new (std::nothrow) Item[count];
    this->volume = volume;
    this->maxWeight = maxWeight;
}

void Backpack::add(const Item &item)
{
    if (this->leftVolume() < item.getVolume()) {
        throw VolumeOverflow();
    }

    if (this->leftWeight() < item.getWeight()) {
        throw WeightOverflow();
    }

    Item* newItems = new (std::nothrow) Item[++count];

    for (int i = 0; i < count - 1; i++) {
        newItems[i] = items[i];
    }

    newItems[count - 1] = item;

    delete[] items;

    items = newItems;
}

Item &Backpack::operator[](int const position) {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Incorrect index!");
    }

    return items[position];
}

int Backpack::size() {
    return count;
}

double Backpack::leftVolume() {
    double sum = 0;

    for (int i = 0; i < count; i++) {
        sum += items[i].getVolume();
    }

    return volume - sum;
}

double Backpack::leftWeight() {
    double sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += items[i].getWeight();
    }

    return maxWeight - sum;
}

Backpack::~Backpack() {
    delete[] items;
}