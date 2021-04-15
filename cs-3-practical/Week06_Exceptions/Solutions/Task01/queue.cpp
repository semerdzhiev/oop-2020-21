#include <iostream>
#include "queue.h"

Queue::Queue(int size){
    capacity = size;
    queue = new Ticket[capacity];
}

int Queue::getTicket(const char *name, const char *phone) {
    Ticket newTicket(name, phone);
    
    if (size == capacity) {
        throw std::overflow_error("There is no more space");
    }

    queue[size++] = newTicket;

    return newTicket.getId();
}

Ticket &Queue::operator[](int const position)
{
    if (position < 0 || position >= size) {
        throw std::invalid_argument("There is no element with this index");
    }

    return queue[position];
}

Ticket Queue::next() {
    Ticket returnTicket = queue[0];

    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--;

    return returnTicket;
}

bool Queue::empty() const {
    return size == 0;
}

int Queue::getSize() const {
    return size;
}

Queue::~Queue() {
    delete[] queue;
}