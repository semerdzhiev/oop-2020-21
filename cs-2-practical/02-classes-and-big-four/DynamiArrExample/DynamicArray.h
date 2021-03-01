#pragma once

#include <iostream>

using std::cout;
using std::endl;

class DynamicArray {
private:
    size_t capacity;
    size_t size;
    int* numbers;

    static void copyArray(int* destination, const int* source, const size_t& sourceSize);
    bool increaseCapacity();
public:
    DynamicArray(size_t capacity=16);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    void add(int number);
    bool contains(int number) const;
    void print() const;
};
