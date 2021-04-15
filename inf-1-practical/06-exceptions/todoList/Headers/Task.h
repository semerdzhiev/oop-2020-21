#pragma once

class Task {
public:
    Task();
    Task(const char *title, const char *description);
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    ~Task();

    const char *getTitle() const;
    const char *getDescription() const;
    unsigned getId() const;

    void print() const;

private:
    static unsigned num;
    unsigned id;
    char *title;
    char *description;

    void setTitle(const char *title);
    void setDescription(const char *description);
};
