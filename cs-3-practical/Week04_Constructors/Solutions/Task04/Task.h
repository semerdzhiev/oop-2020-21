#ifndef TASK_H
#define TASK_H

class Task {
    const static int MAX_TITLE_LENGTH = 32;
    const static int MAX_DESCRIPTION_LENGTH = 128;

    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

public:
    Task();
    Task(char* title, char* description);

    Task& operator=(Task task);
    const char* getTitle();
    const char* getDescription();
    void printInfo();
};

#endif
