#include <iostream>
#include"Point1D.h"
#include "Point2D.h"
#include "MyVector.h"
#include<string>
#include<vector>
#include <utility>

struct Person {
    unsigned short age;
    std::string name;

    explicit Person(unsigned short age = 0, std::string name = "unknown") : age(age), name(std::move(name)) {
        std::cout<<"constructor\n";
    }

    Person(const Person& other)  = default;

    Person(Person&& other)  noexcept = default;

    Person& operator=(const Person& other) = default;
    Person& operator=(Person&& other) = default;


    friend std::ostream& operator<<(std::ostream &os, const Person &t) {
        os << t.age << ' ' << t.name << '\n';
        return os;
    }
};

void test(MyVector<Person>& vec) {
    Person p(8,"w");
    vec.push_back(p);
}

int main() {
    std::ofstream os("data.txt", std::ios::out | std::ios::app);
//    if (!os.is_open())
//        return 1;
//    Point1D p1(3), p2(77);
//    p1.add(p2);
//    p1.print(std::cout);
//    p1.toFile(os);
//    os.close();

//    MyVector<Person> vec(1);
//    //vec.emplace_back(21, "Petko");
//    Person p(4,"w");
//    vec.push_back(p);
//    std::cout << vec[0];
//    test(vec);
//    std::cout<<vec[1];
//    vec.emplace_back(8,"Gosho");
    MyVector<Point*> vec;
    auto* p1 = new Point1D;
    auto* p2 = new Point2D;
    vec.push_back(p1);vec.push_back(p2);
    vec[0]->print(std::cout);
    vec[1]->print(std::cout);
    vec[0]->toFile(os);
    delete p1;
    delete p2;
    os.close();
    return 0;
}
