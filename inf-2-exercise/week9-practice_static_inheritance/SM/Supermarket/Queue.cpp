#include "Queue.h"

inline void Queue::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

inline void Queue::copy(const int* data, int size, int capacity) {
    int* tmp = new int[capacity];
    for (int i = 0; i < size; ++i) {
        tmp[i] = data[i];
    }

    clear();
    this->size = size;
    this->capacity = capacity;
    this->data = tmp;
}

inline void Queue::copy(const Queue& other) {
    copy(other.data, other.size, other.capacity);
}

inline Queue::Queue() : size(0), capacity(5), data(new int[10]) {}

inline Queue::Queue(const Queue& other) : data(nullptr) {
    copy(other);
}

Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        copy(other);
    }

    return *this;
}

inline Queue::~Queue() {
    clear();
}

inline int Queue::getSize() {
    return size;
}

inline void Queue::enqueue(int newItem) {
    if (size + 1 == capacity) {
        copy(data, size, capacity * 2);
    }

    for (int i = size; i >= 0; --i) {
        data[i + 1] = data[i];
    }

    data[0] = newItem;
    ++size;
}

inline int Queue::dequeue() {
    return data[--size];
}

inline void Queue::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
