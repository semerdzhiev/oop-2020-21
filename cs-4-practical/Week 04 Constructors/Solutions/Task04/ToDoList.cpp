#include <iostream>
#include "ToDoList.h"

#define INITIAL_SIZE 8
#define INCREASE_STEP 2

using std::cout;
using std::endl;

ToDoList::ToDoList() {
    firstTaskIndex = 0;
    numberOfTasks = 0;
    capacity = INITIAL_SIZE;
    tasks = new Task[capacity];
}

void ToDoList::reorderArray() {
    for (int i = 0; i < numberOfTasks - firstTaskIndex; i++) {
       tasks[i] = tasks[i + firstTaskIndex];
    }
    numberOfTasks -= firstTaskIndex;
    firstTaskIndex = 0;
}

void ToDoList::resizeArray() {
    Task* newTasksArray = new Task[capacity * INCREASE_STEP];
    for (int i = 0; i < numberOfTasks; i++) {
        newTasksArray[i] = tasks[i];
    }
    delete[] tasks;
    tasks = newTasksArray;
    capacity = capacity * INCREASE_STEP;
}

void ToDoList::pushTask(Task task) {
    if (firstTaskIndex > 0) {
        this->reorderArray();
    } else if (numberOfTasks >= capacity) {
        this->resizeArray();
    }

    tasks[numberOfTasks++] = task;
}

Task ToDoList::popTask() {
    if (!isEmpty()) {
        return tasks[firstTaskIndex++];
    }

    Task nullTask;
    return nullTask;
}

bool ToDoList::isEmpty(){
    return firstTaskIndex == numberOfTasks;
}

void ToDoList::printSize() {
    cout << "Tasks: " << numberOfTasks - firstTaskIndex << " Capacity: " << capacity << endl;
}

ToDoList::~ToDoList() {
    delete[] tasks;
}
