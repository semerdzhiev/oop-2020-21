#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;

// Class Dog
// poroda
// color
// weight
// name
// age
// method says -> Bau

class Animal {
protected:
    bool isDomasho;
public:
    int age;

    string color;
    string name;
    int getAge() {
        return age;
    }
    Animal() {
        name = "no name :(";
        cout<<"Animal constructor"<<endl;
        cout<<name<<endl;
    }
    Animal(string name, int age) {
        cout<<"Animal constructor with name and vazarst"<<endl;
        this->name = name;
        this->age = age;
    }
    ~Animal() {
        cout<<"Animal destructor"<<endl;
    }
};

class Dog : public Animal {
private:
    string poroda;
public:
    string getPoroda() {
        return poroda;
    }
    void says() {
        cout<<"Bau"<<endl;
    }
    Dog() {
        cout<<"Dog constructor"<<endl;
    }
    Dog(string name, string poroda) : Animal(name, 0) {
        this->poroda = poroda;
        this->isDomasho = true;
        cout<<"Dog constructor with name and poroda"<<endl;
    }
    Dog(string name, string poroda, int age) : Animal(name, age) {
        this->poroda = poroda;
        this->age *= 7;
        this->isDomasho = true;
        cout<<"Dog constructor with name and poroda"<<endl;
    }
    ~Dog() {
        cout<<"Dog destructor"<<endl;
    }
};

//class Cat : public Animal {
//public:
//    void says() {
//        cout<<"Myau"<<endl;
//    }
//};

int main() {
    Dog d("Sharo", "husky", 3);
    cout<<d.name<<endl;
    d.says();
    cout<<d.getAge()<<endl;
    cout<<d.getPoroda()<<endl;
   // cout<<d.isDomasho<<endl; how to get access for this field?
    return 0;
}