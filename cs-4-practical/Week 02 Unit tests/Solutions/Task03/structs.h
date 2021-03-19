/**
 * \brief Structures for working with students and marks
 * \author D. Zhekov
 */
#ifndef student
#define student

const int MAX_STRING = 64;
const int EGN_LENGTH = 10;
const int FACULTY_NUMBER_LENGTH = 6;
const int NUMBER_OF_SUBJECTS = 5;

//! Defines mark
struct Mark
{
    char *subject; //!< stores mark subject
    double value; //!< stores mark value

    //! Function for reading from console
    void read();
    //! Function for cleaning
    void clean();
};

//! Defines student
struct Student
{
    char *name; //!< stores student name
    char *surname; //!< stores student surname
    char *family; //!< stores student family name
    char egn[EGN_LENGTH]; //!< stores student egn
    char faculty_number[FACULTY_NUMBER_LENGTH]; //!< stores student faculty number
    Mark marks[NUMBER_OF_SUBJECTS]; //!< stores student marks

    //! Function for reading from console
    void read();
    //! Funtion for printing full name
    void printFullName();
    //! Function for calculationg average mark
    double getAverage();
    //! Function for cleaning
    void clean();
};

#endif