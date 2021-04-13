#include <cstring>

#include "../Headers/TodoList.h"

TodoList::TodoList()
{
    capacity = 2;
    size = 0;
    tasks = new Task*[capacity];
}

TodoList::~TodoList()
{
    for (int i = 0; i < size; i++)
    {
        delete tasks[i];
    }

    delete [] tasks;
}

void TodoList::addTask(const char *title, const char *description)
{
      if (size == capacity)
      {
          resize();
      }

      tasks[size] = new Task(title, description);
      size++;
}

void TodoList::removeTask(const char *title)
{
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(title, tasks[i]->getName()) == 0)
        {
            index = i;
            break;
        }
    }
    
    Task *temp = tasks[index];

    for (int i = index; i < size - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    size--;

    delete temp;
}

void TodoList::print() const
{
    for (int i = 0; i < size; ++i)
    {
        tasks[i]->print();
    }
}

void TodoList::reversePrint() const
{
    for (int i = size -1; i >= 0; i--)
    {
        tasks[i]->print();
    }
}

void TodoList::resize()
{
    capacity *= 2;
    Task **temp = new Task*[capacity];

    for (int i = 0; i < size; i++)
    {
        temp[i] = tasks[i];
    }

    delete [] tasks;
    tasks = temp;
}
