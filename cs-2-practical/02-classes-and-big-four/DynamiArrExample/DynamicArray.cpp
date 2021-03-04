#include "DynamicArray.h"

DynamicArray::DynamicArray(size_t capacity) {
    this->capacity = capacity;
    size = 0;
    numbers = new int[capacity];
}

void DynamicArray::add(int number) {
    if (size >= capacity) {
        if(!increaseCapacity()) {
            std::cerr << "Not enough memory!" << std::endl;
            return;
        }
    }
    numbers[size] = number;
    size++;
}

bool DynamicArray::contains(int number) const {
    for (size_t i = 0; i < size; i++) {
        if (numbers[i] == number) return true;
    }
    return false;
}

void DynamicArray::print() const {
    for (size_t i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

DynamicArray::~DynamicArray() {
    delete[]  numbers;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    capacity = other.capacity;
    size = other.size;
    numbers = new (std::nothrow) int[other.capacity];
    copyArray(numbers,other.numbers,other.size);
    cout<<"Copy constructor invoked!"<<endl;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        int *newArr = new(std::nothrow) int[other.capacity];
        if (newArr) {
            delete[] numbers;
            DynamicArray::copyArray(newArr, other.numbers, other.size);
            numbers = newArr;
            size = other.size;
            capacity = other.capacity;
        }
        cout << "Operator= invoked" << endl;
    }
    return *this;
}

bool DynamicArray::increaseCapacity() {
    capacity *= 2;
    int* numbersCopy = new (std::nothrow) int[capacity];
    if (numbersCopy) {
        copyArray(numbersCopy, numbers, size);
        delete[] numbers;
        numbers = numbersCopy;
        return true;
    } else {
        capacity /= 2;
        return false;
    }
}

void DynamicArray::copyArray(int* destination, const int* source, const size_t& sourceSize) {
    for (size_t i = 0; i < sourceSize; i++) {
        destination[i] = source[i];
    }
}
