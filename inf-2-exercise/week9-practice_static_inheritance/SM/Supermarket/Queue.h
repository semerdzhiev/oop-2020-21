#pragma once
#include <iostream>

class Queue {
    int* data;
    int size;
    int capacity;

    void clear();
    void copy(const int* data, int size, int capacity);
    void copy(const Queue& other);

public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    ~Queue();

    int getSize();
    void enqueue(int newItem);
    int dequeue();
    void print();
};

