#include <iostream>
#include"FacultyMember.h"
int main() {
    FacultyMember member("Ivan", "018320", 82146, 999);
    std::cout<<member.getName()<<" "<<member.getUCN()<<' '<<member.getSalary()<<' '<<member.getFacultyNum()<<std::endl;
    member.setSalary(1200);
    std::cout<<member.getSalary()<<'\n';

    Person* p = new Student("Ivan","5",45546);

    return 0;
}
