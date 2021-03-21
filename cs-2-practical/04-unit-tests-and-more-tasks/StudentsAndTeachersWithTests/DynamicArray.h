#pragma once

#include <iostream>


using std::cout;
using std::endl;

template<class T>
class DynamicArray {
private:
    size_t capacity;
    size_t size;
    T* arr;

    static void copyArray(T* destination, const T* source, const size_t& sourceSize);
    bool increaseCapacity();
    int findIndex(const T& elem) const;
    void swapElements(size_t i, size_t j);
public:
    DynamicArray(size_t capacity=16);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    T& operator[](size_t i) const;
    void add(const T& elem);
    bool contains(const T& elem) const;
    T& getFirst() const;
    T& getLast() const;
    void print() const;
    bool remove(const T& elem);
    size_t getSize() const;

public:
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& _course);
};