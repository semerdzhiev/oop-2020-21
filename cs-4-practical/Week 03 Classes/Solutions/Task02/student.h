#ifndef student
#define student

#include "mark.h"

struct Student
{
    const static int EGN_LENGTH = 10;
    const static int FACULTY_NUMBER_LENGTH = 6;
    const static int NUMBER_OF_SUBJECTS = 5;

    char *name;
    char *surname;
    char *family;
    char egn[EGN_LENGTH];
    char faculty_number[FACULTY_NUMBER_LENGTH];
    Mark marks[NUMBER_OF_SUBJECTS];

    void read();
    void print();
    void printFN();
    double getAverage();
    void clean();
};

#endif