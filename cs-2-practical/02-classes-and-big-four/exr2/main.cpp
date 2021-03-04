#include <iostream>

template <typename T>
void tempFoo() {
    static T x=0;
    x++;
    std :: cout<<x<<std::endl;
}

void foo() {
    int y=5;
    static int x = 5;
    y++;
    x++;
    printf("non static:%d static:%d\n", y,x);
}

inline int cube(int x) {
    return x * x * x;
}

struct A {
    int x;
        int y;

};

class B {

};




int main() {
//    foo();
//    foo();
//    foo();
    tempFoo<int>();
    tempFoo<double>();
    tempFoo<int>();
    tempFoo<double>();
    tempFoo<char>();
//    std :: cout<<cube(9)<< std::endl;
//

    //Struct
//    A a;
//    A *pnt = &a;
//    pnt->x=2;
//    std::cout<<pnt->x<<std::endl;
//    A *b = new A();
//    b->x=33;
//    std::cout<<b->x<<std::endl;
//    delete b;
    return 0;
}
