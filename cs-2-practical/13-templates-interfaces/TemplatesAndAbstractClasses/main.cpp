#include <iostream>
#include"Point1D.h"
#include "MyVector.h"
#include<string>
#include <utility>

struct Person {
    unsigned short age;
    std::string name;

    explicit Person(unsigned short age = 0, std::string name = "unknown") : age(age), name(std::move(name)) {}

    friend std::ostream& operator<<(std::ostream &os, const Person &t) {
        os << t.age << ' ' << t.name << '\n';
        return os;
    }
};

int main() {
    std::ofstream os("data.txt", std::ios::out | std::ios::app);
    if (!os.is_open())
        return 1;
    Point1D p1(3), p2(77);
    p1.add(p2);
    p1.print(std::cout);
    p1.toFile(os);
    os.close();
    MyVector<Person> vec(3);
    vec.emplace_back(21, "Petko");
    std::cout << vec[0];
    return 0;
}
