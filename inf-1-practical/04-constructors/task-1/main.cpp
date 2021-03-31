//#include <cstring>
//#include <iostream>
//#include <cassert>
//
//class Person {
//public:
//    Person(const char* newName) {
//        setName(newName);
//    }
//
//    void setName(const char *newName) {
//        name = new char[strlen(newName) + 1];
//        strcpy(name, newName);
//    }
//
//    // not using const can cause bad behaviour - check main
//    char *getName() const {
//        return name;
//    }
//
//    ~Person() {
//        delete [] name;
//    }
//
//private:
//    char *name;
//};
//
///*
//int main() {
//    char *input = new char[10];
//    std::cin >> input;
//
//    Person p(input);
//
//    std::cout << p.getName() << std::endl;
//
//    char *name = p.getName();
//
//    std::cout << name << std::endl;
//
//    // changes Person's name
//    name[0] = '.';
//
//    std::cout << "name " << name << std::endl;
//    std::cout << "person " << p.getName() << std::endl;
//
//    // Same as above one
//    p.getName()[2] = '1';
//
//    std::cout << "name " << name << std::endl;
//    std::cout << "person " << p.getName() << std::endl;
//
//
//    strcpy(name, "aaaaaaaaaaaaaaaa");
//    std::cout << "name " << name << std::endl;
//    std::cout << "person " << p.getName() << std::endl;
//
//    // access memory of another process - seg fault
//    p.getName()[100000] = '1';
//
//    std::cout << "name " << name << std::endl;
//    std::cout << "person " << p.getName() << std::endl;
//
//    return 0;
//}
//*/
//int main() {
//    int i = 1;
//    assert(i > 0 && i < 10);
//    assert(!(i > 0 && i < 10));
//
//    return 0;
//}

#include <iostream>
#include "Headers/Employee.h"
#include "Headers/Company.h"

int main() {
    Employee emp1("Pesho", "IT", 20, 700);
    Employee emp2("Sasho", "Support", 25, 1000);
    Employee emp3("Tosho", "HR", 24, 700);
    Employee emp4("Gosho", "IT", 30, 800);

    Company company;

    company.addEmployee(emp1);
    company.addEmployee(emp2);
    company.addEmployee(emp3);
    company.addEmployee(emp4);

    company.print();

    company.fireEmployee(emp1);

    std::cout << std::endl;
    company.print();

    std::cout << company.totalSalary() << std::endl;
    company.increase("Gosho", 0.1);
    std::cout << company.salaryByDept("IT") << std::endl;


}

