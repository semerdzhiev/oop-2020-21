#ifndef teacher
#define teacher

class Teacher
{
    const static int EGN_LENGTH = 11;
    const static int FACULTY_NUMBER_LENGTH = 7;
    const static int NUMBER_OF_SUBJECTS = 5;

    char *name;
    char *family;
    char *specialty;

public:
    void read();
    char* getName();
    char* getFN();
    double getAverage();
    void print();
    void clean();
};

#endif