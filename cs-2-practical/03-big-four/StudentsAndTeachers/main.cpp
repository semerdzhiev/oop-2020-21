#include <iostream>
#include "Course.h"
#include "DynamicArray.h"
#include "Student.h"
#include "RetiredTeacher.h"

int main() {
    DynamicArray<Student> arr;
    Student s1(45546, "Petko", "Informatics", 1),
            s2(45545, "Niki", "Informatics", 1),
            s3(50000, "Ivan", "Mathematics", 3),
            s4(60000, "Gosho", "Mathematics and Informatics", 4),
            s5(60003, "Ivan", "Mathematics and Informatics", 8);;
    DynamicArray<Student> arr1;
    arr1.add(s1);arr1.add(s2);arr1.add(s3);arr.add(s3);arr.add(s4);arr.add(s5);
    arr.add(Student{45546,"Petko","Informatics",1});
    arr.add(s2);
    arr.add(s3);
    arr.add(s4);
    arr.print();
    arr.remove(s4);
    arr.print();
    cout<<arr.contains(s5)<<endl;

    cout<<"Course info\n";
    Course dis("dis");
    dis.enrolStudent(s3);
    dis.enrolStudent(s4);
    dis.enrolStudent(s1);
    Course la("la");
    la.enrolStudents(arr);
    Course lp("lp");
    lp.enrolStudents(arr1);
    dis.printInformation();
    la.printInformation();
    lp.printInformation();

    cout<<"Retired teacher\n";
    RetiredTeacher masterOfAll("Tinko Tinchev",25);
    RetiredTeacher parvan("Parvanov",10);
    parvan.addCourse(dis);
    masterOfAll.addCourse(la);masterOfAll.addCourse(lp);masterOfAll.addCourse(dis);
    cout<<masterOfAll.checkCourse(la)<<endl;
    masterOfAll.printInformation();
    parvan.printInformation();
    return 0;
}