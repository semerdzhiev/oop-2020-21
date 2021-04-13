#include <iostream>
#include "Headers/TodoList.h"

int main() {
    TodoList todo;

    todo.addTask("foo", "foo");
    todo.addTask("bar", "bar");
    todo.addTask("foobar", "foobar");

    todo.print();

    todo.removeTask("foo");

    todo.print();

    return 0;
}
