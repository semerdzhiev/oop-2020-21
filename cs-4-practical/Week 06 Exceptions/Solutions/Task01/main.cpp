#include <iostream>
#include "queue.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    const int QUEUE_SIZE = 3;

    Queue ourQueue(QUEUE_SIZE);
    Ticket tmp;

    for (int i = 0; i < QUEUE_SIZE + 1; i++) 
    {
        cin >> tmp;
        try {
            ourQueue.getTicket(tmp.getName(), tmp.getPhone());
        } catch (std::overflow_error &e) {
            cout << e.what() << endl;
            cout << "Following element is not added to queue: \n";
            cout << tmp;
        }
    }

    cout << (ourQueue.empty() ? "Queue is empty" : "Queue is not empty") << endl;

    int size = ourQueue.getSize();
    for (int i = 0; i < size; i++) {
        cout << ourQueue.next();
    }

    cout << (ourQueue.empty() ? "Queue is empty" : "Queue is not empty");
    
    return 0;
}