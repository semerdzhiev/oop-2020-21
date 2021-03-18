#include <iostream>
#include "structs.h"

using std::cout;
using std::cin;
using std::endl;

const int MAX_NUMBER_OF_STUDENTS = 100;

void printMenu()
{
    cout << "Choose option:\n";
    cout << "1 - Add student\n";
    cout << "2 - Print information for students born in March\n";
    cout << "3 - Print information for student with highest marks\n";
    cout << "0 - Exit\n";
}

void printMarch(Student *students, int currentNumberOfStudents)
{
    int monthSecondDigitPosition = 3;

    for (int i = 0; i < currentNumberOfStudents; i++)
    {
        if (students[i].egn[monthSecondDigitPosition] == '3')
        {
            students[i].printFullName();
            cout << "Average: " << students[i].getAverage() << endl;
        }
    }
}

void printHighest(Student *students, int currentNumberOfStudents)
{
    double currentHighest = students[0].getAverage();
    int studentPositionWithHighest = 0;

    for (int i = 1; i < currentNumberOfStudents; i++)
    {
        double currentAverage = students[i].getAverage();
        if (currentAverage > currentHighest)
        {
            currentHighest = currentAverage;
            studentPositionWithHighest = i;
        }
    }

    students[studentPositionWithHighest].printFullName();
}

int main()
{
    int option, currentNumberOfStudents = 0;
    Student students[MAX_NUMBER_OF_STUDENTS];

    do
    {
        printMenu();

        cin >> option;

        switch (option)
        {
        case 1:
            if (currentNumberOfStudents < MAX_NUMBER_OF_STUDENTS)
            {
                students[currentNumberOfStudents++].read();
            }
            break;

        case 2:
            printMarch(students, currentNumberOfStudents);
            break;

        case 3:
            printHighest(students, currentNumberOfStudents);
            break;
        }
    } while (option);

    for(int i = 0; i < currentNumberOfStudents; i++) {
        students[i].clean();
    }

    return 0;
}