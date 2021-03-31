
#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H


class Employee {
public:
    Employee();
    Employee(const char *newName, const char *department, int newAge, double newSalary);

    void setName(const char *newName);
    void setDepartment(const char *newDept);
    void setAge(int newAge);
    void setSalary(double newSalary);

    const char *getName() const;
    const char *getDepartment() const;
    int getAge() const;
    double getSalary() const;

    void print() const;

    bool equal(const Employee& empl);

private:
    char name[51];
    char department[51];
    int age;
    double salary;

};


#endif //UNTITLED_EMPLOYEE_H
