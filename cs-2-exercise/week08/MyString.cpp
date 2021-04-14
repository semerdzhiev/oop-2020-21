#include "MyString.h"
#include <iostream>
#include <string.h>
using namespace std;
//istream
//atoi
std::ostream& operator<<(std::ostream& os, const MyString& a) {
    os<<a.str;
    return os;
};

std::istream& operator>>(std::istream& is, const MyString& a) {
    is>>a.str;
    return is;
}

MyString::MyString(const MyString& obj) {
    cout<<"MyString str copy constr"<<endl;
    int l = strlen(obj.str) + 1;
    this->str = new char[l];
    strcpy(this->str, obj.str);
}

MyString::MyString(char* str) {
    cout<<"MyString str copy"<<endl;
    int l = strlen(str) + 1;
    this->str = new char[l];
    strcpy(this->str, str);
}

MyString::~MyString() {
    cout<<"~MyString"<<endl;
    delete [] str;
}

MyString::MyString(MyString&& obj) {
    cout<<"MyString str move constr"<<endl;
    this->str = obj.str;
    obj.str = nullptr;
}

bool MyString::operator==(MyString& other) {
    return strcmp(this->str, other.str) == 0;
}

bool MyString::operator==(int other) {
    return atoi(this->str) == other;
}

bool operator==(int el, const MyString& other) {
    return atoi(other.str) == el;
}
