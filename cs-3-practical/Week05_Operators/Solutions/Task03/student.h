#ifndef STUDENT_H
#define STUDENT_H

#include "mark.h"

using std::ostream;

class Student
{
    const static int EGN_LENGTH = 11;
    const static int FACULTY_NUMBER_LENGTH = 7;
    const static int NUMBER_OF_SUBJECTS = 3;

    char *name;
    char *surname;
    char *family;
    char egn[EGN_LENGTH];
    char faculty_number[FACULTY_NUMBER_LENGTH];
    Mark marks[NUMBER_OF_SUBJECTS];

public:
    void read();
    void print();
    void printFN();

    char *getName();
    char *getFN();
    double getAverage() const;

    void clean();

    friend ostream &operator<<(ostream &out, const Student &student);
};

#endif