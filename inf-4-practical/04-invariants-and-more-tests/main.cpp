#include <cstring>
#include <iostream>

class Person {
public:
    Person(const char* newName) {
        setName(newName);
    }

    void setName(const char *newName) {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // not using const can cause bad behaviour - check main
    char *getName() const {
        return name;
    }

    ~Person() {
        delete [] name;
    }

private:
    char *name;
};


int main() {
    char *input = new char[10];
    std::cin >> input;

    Person p(input);

    std::cout << p.getName() << std::endl;

    char *name = p.getName();

    std::cout << name << std::endl;

    // changes Person's name
    name[0] = '.';

    std::cout << "name " << name << std::endl;
    std::cout << "person " << p.getName() << std::endl;

    // Same as above one
    p.getName()[2] = '1';

    std::cout << "name " << name << std::endl;
    std::cout << "person " << p.getName() << std::endl;


    strcpy(name, "aaaaaaaaaaaaaaaa");
    std::cout << "name " << name << std::endl;
    std::cout << "person " << p.getName() << std::endl;

    // access memory of another process - seg fault
    p.getName()[100000] = '1';

    std::cout << "name " << name << std::endl;
    std::cout << "person " << p.getName() << std::endl;

    return 0;
}
