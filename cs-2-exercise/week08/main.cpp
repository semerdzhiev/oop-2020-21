#include <iostream>
#include "Singleton.h"
#include "MyString.cpp"

int& test() {
    static int i = 0;
    cout<<i++<<endl;
    return i;
}

int main() {
    // .  vs  ->
    Singleton* d = Singleton::getInstance();
    Singleton* e = Singleton::getInstance();
    Singleton* f = Singleton::getInstance();

    test();
    test() = 5;
    test();
    test();

    char str[] = {"333\0"};
    MyString a(str);
    MyString b(str);
    cout<<a<<endl;
    int *c;
    try {
        c = new int[10000000000L];
        throw std::out_of_range("Line 13 failed");
    }
    catch(std::bad_alloc& e) {
        cout<<"bad alloc";
    }
    catch(std::exception& e) {
        cout<<"Error exception "<<e.what();
    }
    catch(...) {
        cout<<"Error";
    }
    delete [] c;
    return 0;

}