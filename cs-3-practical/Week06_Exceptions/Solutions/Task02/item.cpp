#include <iostream>
#include <cstring>
#include "item.h"

Item::Item()
{
    name = nullptr;
    weight = 0;
    volume = 0;
}

Item::Item(const char *name, double weight, double volume) {
    int n = strlen(name);
    this->name = new (std::nothrow) char[n+1];
    
    if (this->name) {
        strcpy(this->name, name);
    }

    this->weight = weight;
    this->volume = volume;
}

const char* Item::getName() const {
    return name;
}

double Item::getVolume() const {
    return volume;
}

double Item::getWeight() const {
    return weight;
}

Item &Item::operator=(const Item &item){
    if (this != &item)
    {
        if (item.name != nullptr) {
            this->name = new (std::nothrow) char[strlen(item.name) + 1];
            strcpy(this->name, item.name);
        }

        this->weight = item.weight;
        this->volume = item.volume;       
    }
 
    return *this;
}

bool Item::operator==(const Item &item)
{
    return strcmp(name, item.name) == 0 && weight == item.weight && volume == item.volume;
}

bool Item::operator>(const Item &item) {
    return strcmp(name, item.name) < 0 && weight > item.weight && volume > item.volume;
}

Item::~Item() {
    delete[] name;
}
