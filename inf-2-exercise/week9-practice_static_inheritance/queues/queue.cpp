#include <iostream>
using namespace std;

class Queue {
    int* data;
    int size;
    int capacity;

    void clear() {
        delete [] data;
        data = NULL;
        size = 0;
        capacity = 0;
    }

    void copy(const int* data, int size, int capacity) {
        int* tmp = new int[capacity];
        for(int i = 0; i< size; ++i) {
            tmp[i] = data[i];
        }

        clear();
        this->size = size;
        this->capacity = capacity;
        this->data = tmp;
    }

    void copy(const Queue& other) {
        copy(other.data, other.size, other.capacity);
    }

public:
    Queue(): size(0), capacity(5), data(new int[10]) {}
    Queue(const Queue& other): data(NULL) {
        copy(other);
    }
    Queue& operator=(const Queue& other) {
        if(this != &other) {
            copy(other);
        }

        return *this;
    }
    ~Queue() {
        clear();
    }

    int getSize() {
        return size;
    }

    void enqueue(int newItem) {
        if(size+1 == capacity) {
            copy(data, size, capacity*2);
        }

        for(int i = size; i>= 0; --i) {
            data[i+1] = data[i];
        }

        data[0] = newItem;
        ++size;
    }

    int dequeue() {
        return data[--size];
    }

    void print() {
        for(int i = 0; i< size; ++i) {
            cout<< data[i]<< " ";
        }
        cout<< endl;
    }
};

class MultiQueue {
    Queue q[5];

public:
    void enqueue(int newElement) {
        int minIndex = 0;
        for(int i=0; i< 5; ++i) {
            if(q[i].getSize() < q[minIndex].getSize()) {
                minIndex = i;
            }
        }

        q[minIndex].enqueue(newElement);
    }

    void print() {
        for(int i = 0; i< 5; ++i) {
            q[i].print();
            cout<< endl;
        }
        cout<< endl;
    }
};

int main() {

    MultiQueue mq;

    for(int i = 0; i< 20; ++i) {
        mq.enqueue(i);
    }

    mq.print();

    return 0;
}
