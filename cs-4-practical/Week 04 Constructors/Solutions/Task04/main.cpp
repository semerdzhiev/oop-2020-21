#include <iostream>
#include <cstring>
#include "ToDoList.h"
#include "Task.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    ToDoList list;
    Task task1("Task1", "Clean your room");
    list.pushTask(task1);
    list.printSize();
    cout << "List is empty: " << (list.isEmpty() ? "true" : "false") << endl;

    for (int i = 0; i < 62; i++) {
        Task taskN("Task1", "Do your homework!");
        list.pushTask(taskN);
    }
    list.printSize();

    for (int i = 0; i < 15; i++) {
        Task task = list.popTask();
        task.printInfo();
    }
    list.printSize();

    for (int i = 0; i < 10; i++) {
        Task taskN("Task2", "Do your homework!");
        list.pushTask(taskN);
    }
    list.printSize();

    list.popTask();
    cout << "List is empty: " << (list.isEmpty() ? "true" : "false") << endl;

    return 0;
}
