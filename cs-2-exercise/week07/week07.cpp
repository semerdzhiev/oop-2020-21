#include <iostream>
#include <string.h>
using namespace std;


class MyString {
    private:
        char* str;
    public:
        MyString(char* str) {
            cout<<"MyString str copy"<<endl;
            int l = strlen(str) + 1;
            this->str = new char[l];
            strcpy(this->str, str);
        }
        ~MyString() {
            cout<<"~MyString"<<endl;
            delete [] str;
        }
        MyString(const MyString& obj) {
            cout<<"MyString str copy constr"<<endl;
            int l = strlen(obj.str) + 1;
            this->str = new char[l];
            strcpy(this->str, obj.str);
        }
        MyString(MyString&& obj) {
            cout<<"MyString str move constr"<<endl;
            this->str = obj.str;
            obj.str = nullptr;
        }
        friend void print(const MyString& a);
        friend std::ostream& operator<<(std::ostream& os, const MyString& a);

};

class Entity {
    private:
        MyString str;
    public:
        Entity(MyString& obj) : str(obj) {
            cout<<"Entity constructor..."<<endl;
        }
        Entity(MyString&& obj) : str((MyString&&) obj) {
            cout<<"Entity move constructor..."<<endl;
        }
        ~Entity() {
               cout<<"~Entity..."<<endl;
        }

};

std::ostream& operator<<(std::ostream& os, const MyString& a) {
    os<<a.str;
    return os;
};

void print(int&& a) {
    cout<<"&&"<<endl;
    cout<<a<<endl;
    return;

}

void print(int& a) {
    cout<<"&"<<endl;
    cout<<a<<endl;
    return;
}

void print(const MyString& a) {
    cout<<a.str<<endl;
}

int main ()
{  
    int b = 8;
    print(4);
    print(b);
    Entity test(MyString ("Test"));
    cout<<"-------------------"<<endl;
    MyString d("Test");
    Entity e(d);
    
    MyString d("Test1");
    cout<<d.getStr()<<endl;
    print(d);
    cout<<" "<< 5 << " "<< "pecko "<< d <<endl;
    return 0;
}