#include "MultiQueue.h"

inline void MultiQueue::enqueue(int newElement) {
    int minIndex = 0;
    for (int i = 0; i < 5; ++i) {
        if (q[i].getSize() < q[minIndex].getSize()) {
            minIndex = i;
        }
    }

    q[minIndex].enqueue(newElement);
}

inline void MultiQueue::print() {
    for (int i = 0; i < 5; ++i) {
        q[i].print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
