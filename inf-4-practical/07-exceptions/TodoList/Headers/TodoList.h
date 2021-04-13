#ifndef WEEK07_TODOLIST_H
#define WEEK07_TODOLIST_H


#include "Task.h"

class TodoList
{
public:
    TodoList();
    ~TodoList();

    void addTask(const char *, const char *);
    void removeTask(const char*);
    void print() const;
    void reversePrint() const;

private:
    Task **tasks;
    unsigned size;
    unsigned capacity;

    TodoList(const TodoList&);
    TodoList& operator=(const TodoList&);

    void resize();
};


#endif //WEEK07_TODOLIST_H
