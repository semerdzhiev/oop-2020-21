#pragma once

#include "Task.h"

class TodoList {
public:
    TodoList();
    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;
    ~TodoList();

    void addTask(const char *title, const char *description);
    void removeTask(unsigned  id);

    void print() const;
    void reversePrint() const;

private:
    Task **tasks;
    unsigned size;
    unsigned capacity;

    void resize();
};
