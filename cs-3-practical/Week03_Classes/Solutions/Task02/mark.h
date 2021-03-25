#ifndef mark
#define mark

const int MAX_STRING = 64;

struct Mark
{
    char *subject;
    double value;

    void read();
    void clean();
};

#endif