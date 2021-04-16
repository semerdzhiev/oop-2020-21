#ifndef QUEUE
#define QUEUE

#include "ticket.h"

class Queue
{
private:
    Ticket* queue;
    int capacity = 0;
    int size = 0;

public:
    Queue(int size);

    int getTicket(const char* name, const char* phone);
    Ticket& operator[](int const position);
    Ticket next();
    bool empty() const;
    int getSize() const;

    ~Queue();
};

#endif