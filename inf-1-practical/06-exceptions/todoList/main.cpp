#include <iostream>
#include "Headers/TodoList.h"

int main() {
    TodoList todoList;

    todoList.addTask("foo", "foo");
    todoList.addTask("bar", "bar");
    todoList.addTask(nullptr, "foobar");
    todoList.addTask("foo", nullptr);
    todoList.addTask("foobar", "foobar");

    todoList.print();

    todoList.removeTask(1);
    todoList.print();

    return 0;
}
