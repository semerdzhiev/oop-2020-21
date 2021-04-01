/*
Да се състави програма, която съхранява в масив следните данни за група студенти:

собствено име
фамилия
ЕГН
факултетен номер (6 цифри)
оценките по 5 дисциплини
и извършва следните операции, избирани от меню:

добавя към масив данните на нов студент;
извежда на екрана имената и успеха на студентите, родени през м. Март
извежда на екрана имената на студента с най-висок среден успех
сортиране на група студенти (без/със компаратор)

*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char firstName[30];
    char lastName[30];
    char UCN[10];
    int fn;
    double grades[5];
};

Student students[10];
int filled = 0;

void add(Student s) {
    students[filled++] = s;
}

int main() {

    ifstream in("students.txt");
    while(in>> students[filled].firstName>> students[filled].lastName>> students[filled].UCN>> students[filled].fn) {
        for(int i = 0; i< 5; ++i) {
            in>> students[filled].grades[i];
        }
        ++filled;
    }
    in.close();

    double grades1[5] = {4, 3, 5, 6, 5};
    Student newStudent;
    strcpy(newStudent.firstName, "toni");
    strcpy(newStudent.lastName, "petkov");
    strcpy(newStudent.UCN, "23445");
    newStudent.fn = 23454;
    for(int i = 0; i< 5; ++i) {
        newStudent.grades[i] = grades1[i];
    }
    add(newStudent);

    for(int i = 0; i< filled; ++i) {
        cout<< students[i].firstName<< " ";
        cout<< students[i].lastName<< " ";
        cout<< students[i].UCN<< " ";
        cout<< students[i].fn<< " ";
        for(int j = 0; j< 5; ++j) {
            cout<< students[i].grades[j]<< " ";
        }
        cout<< endl;
    }

    return 0;
}

