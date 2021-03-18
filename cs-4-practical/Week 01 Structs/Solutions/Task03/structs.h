#ifndef student
#define student

const int MAX_STRING = 64;
const int EGN_LENGTH = 10;
const int FACULTY_NUMBER_LENGTH = 6;
const int NUMBER_OF_SUBJECTS = 5;

struct Mark 
{
    char *subject;
    double value;

    void read();
    void clean();
};

struct Student
{
    char *name;
    char *surname;
    char *family;
    char egn[EGN_LENGTH];
    char faculty_number[FACULTY_NUMBER_LENGTH];
    Mark marks[NUMBER_OF_SUBJECTS];

    void read();
    void printFullName();
    double getAverage();
    void clean();
};

#endif