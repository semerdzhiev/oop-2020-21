
#include <cassert>
#include <cstring>
#include <iostream>

#include "../Headers/Task.h"

unsigned Task::num = 1;

Task::Task(const char *title, const char *description)
{
    id = num;
    num++;
    setTitle(title);
    setDescription(description);
}

Task::Task(const Task &rhs)
{
    copy(rhs);
}

Task &Task::operator=(const Task &rhs)
{
    if (this != &rhs) {
        delete [] title;
        delete [] description;

        copy(rhs);
    }

    return *this;
}

Task::~Task()
{
    delete [] title;
    delete [] description;
}

void Task::setTitle(const char *title)
{
    assert(title);
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Task::setDescription(const char *description)
{
    assert(description);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

const char *Task::getName() const
{
    return title;
}

const char *Task::getDescription() const
{
    return description;
}

void Task::copy(const Task &task)
{
    id = task.id;
    this->title = new char[strlen(task.title) + 1];
    strcpy(this->title, task.title);

    this->description = new char[strlen(task.description) + 1];
    strcpy(this->description, task.description);
}

void Task::print() const {
    std::cout << "Id: " << id << ", Title: " << title
        << ", Description: " << description << std::endl;
}
