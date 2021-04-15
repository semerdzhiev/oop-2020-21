#include <iostream>
#include "../Headers/TodoList.h"

TodoList::TodoList() {
    capacity = 2;
    size = 0;
    tasks = new Task*[capacity];
}

TodoList::~TodoList() {
    for (int i = 0; i < size; i++) {
        delete tasks[i];
    }
    delete [] tasks;
}

void TodoList::addTask(const char *title, const char *description) {
    try {
        if (size == capacity) {
            resize();
        }

        tasks[size] = new Task(title, description);
        size++;
    } catch (const std::bad_alloc& e) {
        std::cerr << "TodoList::addTask - Error while adding task:" << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "TodoList::addTask - " << e.what() << std::endl;
    }
}

void TodoList::removeTask(unsigned  id) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (id == tasks[i]->getId()) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Task *temp = tasks[index];

        for (int i = index; i < size - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }

        delete temp;
        size -= 1;
    }
}

void TodoList::print() const {
    for (int i = 0; i < size; ++i) {
        tasks[i]->print();
    }
}

void TodoList::reversePrint() const {
    for (int i = size - 1; i >= 0; --i) {
        tasks[i]->print();
    }
}

void TodoList::resize() {
    capacity *= 2;
    Task **temp;

    try {
        temp = new Task*[capacity];
    } catch (std::bad_alloc& e) {
        std::cerr << "TodoList::resize - " << e.what() << std::endl;
        throw;
    }

    for (int i = 0; i < size; ++i) {
        temp[i] = tasks[i];
    }

    delete [] tasks;
    tasks = temp;
}
