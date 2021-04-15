
#ifndef WEEK07_TASK_H
#define WEEK07_TASK_H


class Task
{
public:
    Task(const char*, const char*);
    Task(const Task&);
    Task& operator=(const Task&);
    ~Task();

    const char *getName() const;
    const char *getDescription() const;

    void print() const;

private:
    static unsigned num;
    unsigned id;
    char *title;
    char *description;

    void setTitle(const char *);
    void setDescription(const char*);

    void copy(const Task&);
};


#endif //WEEK07_TASK_H
