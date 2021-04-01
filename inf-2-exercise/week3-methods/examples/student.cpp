ent/*
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
    string firstName;
    string lastName;
    string UCN;
    int fn;
    double grades[5];
};

bool bornInMarch(Student student) {
    return student.UCN[3] == '3';
}

void printAllInMarch(Student students[], int size) {
    for(int i = 0; i< size; ++i) {
        if(bornInMarch(students[i])) {
            cout<< students[i].firstName<< " ";
            cout<< students[i].lastName<< endl;
        }
    }
}

// students 1 max avg grade
double avgGrade(Student& student) {
    double sum = 0;
    for(int i = 0; i< 5; ++i) {
        sum += student.grades[i];
    }

    return sum / 5;
}

void printMaxAvgGradeStudentName(Student students[], int size) {
    int maxIndex = 0;
    for(int i = 1; i< size; ++i) {
        if(avgGrade(students[maxIndex]) < avgGrade(students[i])) {
            maxIndex = i;
        }
    }
    cout<< students[maxIndex].firstName<< endl;
}

void add(Student students[], int& size, Student s) {
    students[size] = s;
    ++size;
}

int minValueIndex(Student students[], int size, int startIndex) {
    int minInd = startIndex;
    for(int i = startIndex; i < size; ++i){
        if(students[minInd].fn > students[i].fn)
            minInd = i;
    }
    return minInd;
}

void sort(Student students[], int size) {
    Student temp;
    for(int i = 0; i < size; i++){
        temp = students[minValueIndex(students, size, i)];
        students[minValueIndex(students, size, i)] = students[i];
        students[i] = temp;
    }
}

void print(Student students[], int size) {
    for(int i = 0; i< size; ++i) {
        cout<< students[i].firstName<< " ";
        cout<< students[i].lastName<< " ";
        cout<< students[i].UCN<< " ";
        cout<< students[i].fn<< " ";
        for(int j = 0; j< 5; ++j) {
            cout<< students[i].grades[j]<< " ";
        }
        cout<< endl;
    }
}

int main() {
    Student students[10];
    int filled = 0;

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
    newStudent.firstName = "toni";
    newStudent.lastName = "petkov";
    newStudent.UCN = "23445";
    newStudent.fn = 23454;
    for(int i = 0; i< 5; ++i) {
        newStudent.grades[i] = grades1[i];
    }

    add(students, filled, newStudent);
    print(students, filled);

    cout<< endl;
    cout<< "born in march"<< endl;
    printAllInMarch(students, filled);

    cout<< endl;
    cout<< "max avg grade"<< endl;
    printMaxAvgGradeStudentName(students, filled);

    cout<< "sorted students"<< endl;
    sort(students, filled);
    print(students, filled);

    return 0;
}

