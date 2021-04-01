#include "Student.h"

bool Student::bornInMarch() {
    return UCN[3] == '3';
}

double Student::avgGrade() {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += grades[i];
    }

    return sum / 5;
}