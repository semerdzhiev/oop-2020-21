#include <iostream>
#include <string>
using namespace std;

class Animal {
    string name;
    int age;
public:
    Animal(string name, int age) : name(name), age(age) {}

    virtual void makeSound() const {
        cout<< "..."<< endl;
    }

    virtual ~Animal() {
        cout<< "animal destructor"<< endl;
    }
};

class Turtle: public Animal {
    double shellDiameter;
public:
    Turtle(string name, int age, double shellDiameter) : Animal(name, age), shellDiameter(shellDiameter) {}

    virtual void makeSound() const {
        cout<< "...."<< endl;
    }
};

enum Type {
    Canis, Vulpes
};

class Fox: public Animal {
    Type type;
public:
    Fox(string name, int age, Type type) : Animal(name, age), type(type) {}

    virtual void makeSound() const {
        cout<< "wa pa pa pa pow"<< endl;
    }

    virtual ~Fox() {
        cout<< "fox destructor"<< endl;
    }
};

void printAnimal(const Animal* animal) {
    animal->makeSound();
}

int main() {
    Animal a("Bobby", 5);
    a.makeSound();

    Turtle t("Gosho", 45, 30);
    t.makeSound();

    Fox f("Freddy", 5, Canis);
    f.makeSound();

    /*Fox* fp = &f;
    Fox& fr = f;

    fp->makeSound();
    fr.makeSound();

    Animal* afp = &f;
    afp->makeSound();*/

    printAnimal(&a);
    printAnimal(&t);
    printAnimal(&f);

    //Animal* df = new Fox("Gabby", 7, Canis);
    //delete df;

    return 0;
}
