#include <iostream>
#include <string>
using namespace std;

class Person {
    int age;
    string name;

    void print() {}
};

class Employee {
    int id;
    string name;

    void print() {}
};

class Teacher: public Person, Employee {
    void printTeacher() {
        Person::print();
        Employee::print();
    }
};

int main() {
    Teacher t;

    return 0;
}
