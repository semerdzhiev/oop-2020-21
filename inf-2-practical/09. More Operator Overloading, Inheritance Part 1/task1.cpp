#include <iostream>
#include <string>

using namespace std;


class Human
{
protected:
    string name{};
    string phone{};
public:
   
    Human() 
    {
        cout << "Human default constructor" << endl;
    }
    
    Human(const string& _name, const string& _phone): name{_name}, phone{_phone} 
    {
        cout << "Human constructor" << endl;
    }

    ~Human()
    {
        cout << "Human destructor" << endl;
    }

    void print() const
    {
        std::cout << name << " " << phone;
    }
};

class Student : private Human
{
private:
    unsigned faculty_number{};
    string major{};
public:

    Student() //: Human("","") -> вариант, ако Human няма конструктор по подразбиране, искаме Student да има такъв
    {
        cout << "Student default constructor" << endl;
    }

    Student( unsigned _fn, string _major, const string& name = "", const string& phone = "") :  Human(name, phone), 
                                                                                                faculty_number(_fn),
                                                                                                major(_major)
    {
        cout << " Student constructor" << endl;
    }

    ~Student()
    {
        cout << "Student destructor" << endl;
    }
    
    void print() const
    {
        Human:: print();
        cout << " " << faculty_number << " " << major << endl;
    }
};

class Teacher : Human
{
private:
    string subject{};
public:
    Teacher(const string& _subject, const string& _name, const string& _phone): Human(_name, _phone),
                                                                                subject(_subject)
    {}

    void print() const
    {
        Human:: print();
        cout << " " << subject << endl; 
    }
};

int main()
{   
    Student student{20012, "Informatics", "Anna", "1193931"};
    student.print();
    
    return 0;
}