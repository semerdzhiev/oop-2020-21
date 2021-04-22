#pragma once
#include "Queue.h"

class MultiQueue {
    Queue q[5];

public:
    void enqueue(int newElement);

    void print();
};

