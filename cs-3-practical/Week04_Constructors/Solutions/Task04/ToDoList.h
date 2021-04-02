#include "Task.h"

#ifndef TODOLIST_H
#define TODOLIST_H

class ToDoList {
    Task* tasks;
    int firstTaskIndex, numberOfTasks, capacity;

public:
    ToDoList();
    void reorderArray();
    void resizeArray();
    void pushTask(Task task);
    Task popTask();
    bool isEmpty();
    void printSize();
    ~ToDoList();
};

#endif // TODOLIST_H
