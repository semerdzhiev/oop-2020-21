#include <iostream>
#include <cstring>
#include "../Headers/Task.h"

unsigned Task::num = 1;

Task::Task() {
    id = 0;
    title = nullptr;
    description = nullptr;
}

Task::Task(const char *title, const char *description) {
    setTitle(title);
    setDescription(description);
    id = num;
    num++;
}

Task::~Task() {
    delete [] title;
    delete [] description;
}

const char *Task::getTitle() const {
    return title;
}

const char *Task::getDescription() const {
    return description;
}

unsigned Task::getId() const {
    return id;
}

void Task::print() const {
    std::cout << "id: " << id <<
        ", title: " << title <<
        ", description: " << description << std::endl;
}

void Task::setTitle(const char *title) {
    if (title == nullptr) {
        throw std::invalid_argument("Task::setTitle - title is nullptr");
    }

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Task::setDescription(const char *description) {
    if (description == nullptr) {
        throw std::invalid_argument("Task::setDescription - description is nullptr");
    }
    try {
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
    } catch (const std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
        delete [] title;
        throw;
    }
}