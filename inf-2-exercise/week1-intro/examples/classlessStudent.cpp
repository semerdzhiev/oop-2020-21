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

char firstName[10][30];
char lastName[10][30];
char UCN[10][10];
int fn[10];
double grades[10][5];

int filled = 0;

void add(char firstName1[30], char lastName1[30], char UCN1[10], int fn1, double grades1[5]) {
    strcpy(firstName[filled], firstName1);
    strcpy(lastName[filled], lastName1);
    strcpy(UCN[filled], UCN1);
    fn[filled] = fn1;
    for(int i = 0; i< 5; ++i) {
        grades[filled][i] = grades1[i];
    }

    ++filled;
}

int main() {

    ifstream in("students.txt");
    while(in>> firstName[filled]>> lastName[filled]>> UCN[filled]>> fn[filled]) {
        for(int i = 0; i< 5; ++i) {
            in>> grades[filled][i];
        }
        ++filled;
    }
    in.close();

    double grades1[5] = {4, 3, 5, 6, 5};
    add("toni", "petkov", "23445", 34534, grades1);

    for(int i = 0; i< filled; ++i) {
        cout<< firstName[i]<< " ";
        cout<< lastName[i]<< " ";
        cout<< UCN[i]<< " ";
        cout<< fn[i]<< " ";
        for(int j = 0; j< 5; ++j) {
            cout<< grades[i][j]<< " ";
        }
        cout<< endl;
    }

    return 0;
}
