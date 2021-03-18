#include <iostream>
#include <fstream>
#include <cstring>

#include "Student.h"

using namespace std;

void printAllInMarch(Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        if (students[i].bornInMarch()) {
            cout << students[i].firstName << " ";
            cout << students[i].lastName << endl;
        }
    }
}

void printMaxAvgGradeStudentName(Student students[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (students[maxIndex].avgGrade() < students[i].avgGrade()) {
            maxIndex = i;
        }
    }
    cout << students[maxIndex].firstName << endl;
}

void add(Student students[], int& size, Student s) {
    students[size] = s;
    ++size;
}

int minValueIndex(Student students[], int size, int startIndex) {
    int minInd = startIndex;
    for (int i = startIndex; i < size; ++i) {
        if (students[minInd].fn > students[i].fn)
            minInd = i;
    }
    return minInd;
}

void sort(Student students[], int size) {
    Student temp;
    for (int i = 0; i < size; i++) {
        temp = students[minValueIndex(students, size, i)];
        students[minValueIndex(students, size, i)] = students[i];
        students[i] = temp;
    }
}

void print(Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << students[i].firstName << " ";
        cout << students[i].lastName << " ";
        cout << students[i].UCN << " ";
        cout << students[i].fn << " ";
        for (int j = 0; j < 5; ++j) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Student students[10];
    int filled = 0;

    ifstream in("students.txt");
    in >> filled;
    for (int i = 0; i < filled; ++i) {
        in >> students[i].firstName;
        in >> students[i].lastName;
        in >> students[i].UCN;
        in >> students[i].fn;
        for (int j = 0; j < 5; ++j) {
            in >> students[i].grades[j];
        }
    }
    in.close();

    double grades1[5] = { 4, 3, 5, 6, 5 };

    Student newStudent;
    newStudent.firstName = "toni";
    newStudent.lastName = "petkov";
    newStudent.UCN = "23445";
    newStudent.fn = 23454;
    for (int i = 0; i < 5; ++i) {
        newStudent.grades[i] = grades1[i];
    }

    add(students, filled, newStudent);
    print(students, filled);

    cout << endl;
    cout << "born in march" << endl;
    printAllInMarch(students, filled);

    cout << endl;
    cout << "max avg grade" << endl;
    printMaxAvgGradeStudentName(students, filled);

    cout << "sorted students" << endl;
    sort(students, filled);
    print(students, filled);

    return 0;
}

