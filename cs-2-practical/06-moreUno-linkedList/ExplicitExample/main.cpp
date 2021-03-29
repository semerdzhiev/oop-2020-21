#include <iostream>
#include<cstring>

class A {
private:
    char *name;
    bool sex; //0-man 1-woman
public:
     explicit A(const char *_name) : sex(false) {
        name = new(std::nothrow) char[strlen(_name)];
        if (!name) {
            std::cerr << "Error!\n";
            exit(1);
        }
        strcpy(name, _name);
    }

     explicit A(bool _b) : sex(_b) {
        name = new(std::nothrow) char[8];
        if (!name) {
            std::cerr << "Error!\n";
            exit(1);
        }
        strcpy(name, "unknown");
    }

    void printName() const {
        std::cout << name << '\n';
    }

    void printSex() const {
        sex ? std::cout << "Woman\n" : std::cout << "Man\n";
    }
};

void printInfo(const A &a) {
    a.printName();
    a.printSex();
}

int main() {
//    A a = true;
//    A b = "Pesho";
//    a.printSex();
//    a.printName();
//    b.printName();
//
//    printInfo(false);
//    printInfo("Ivan");
//    printInfo(a);
//    printInfo(b);
    return 0;
}
