#ifndef mark
#define mark

struct Mark
{
    char *subject;
    double value;

    void read();
    void copy(Mark newMark);
    void clean();
};

#endif