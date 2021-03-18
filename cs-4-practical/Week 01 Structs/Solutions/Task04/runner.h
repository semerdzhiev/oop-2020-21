#ifndef runner
#define runner

const int MAX_STRING = 128;
const int NUMBER_OF_MARATHONS = 12;

struct Runner
{
    char* name;
    char* family;
    double times[NUMBER_OF_MARATHONS];

    void read();
    double getPace();
    int beatNtimes(Runner *other);
    void clean();
};

#endif