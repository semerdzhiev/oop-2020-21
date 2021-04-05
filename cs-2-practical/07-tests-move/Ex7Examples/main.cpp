#include <iostream>

class A {
    int *arr;
    size_t len;
public:
    A(const int* _arr,size_t _len):len(_len) {
        arr = new int[len];
        for(size_t i=0;i<len;++i)
            arr[i]=_arr[i];
    }
    A(size_t _len):len(_len) {
        arr = new int[len];
    }
    ~A() {
        std::cout<<"Destructed!\n";
        delete[] arr;
    }

    void print() const {
        for(size_t i=0;i<len;++i)
            std::cout<<arr[i]<<' ';
        std::cout<<'\n';
    }
};

void f(int& n) {
    n*=n;
}



enum class COLOR {
    UNDEFINED = -1,
    RED,
    GREEN,
    BLUE
};

void h(const COLOR& col) {
    switch (col) {
        case COLOR::RED : std::cout<<"Red\n"; break;
        case COLOR::GREEN : std::cout<<"Green\n"; break;
        case COLOR::BLUE : std::cout<<"Blue\n"; break;
        default : std::cerr<<"Undefined color!\n";
    }
}

void powerTwo(int&& a) { //rvalue ref
    std::cout<<a*a<<std::endl;
}

struct B {
    B(){std::cout<<"constructed\n";}
    ~B(){std::cout<<"destructed\n";}
};

void g(const A& a) {
    a.print();
}

void g1(A& a) {

}

struct C {
    int a;
    int b;
    char c;
};

void test(const B& b){std::cout<<"lvalue\n";}

void test(B&& b){std::cout<<"rvalue\n";} //we can steal the object, because we know that's temp.
int main() {
    int len = 5;
    int arr[] = {1,2,3,4,5};
    A* a = new A(arr,len);
    g(*a);
    g(A(2));
    g1(*a);
    delete a;
    int temp = 3;
    const int& ref = temp;
    const int& n = 3;
    f(len);
    std::cout<<len<<std::endl;
    std::cout<<"Enum tests\n";
    h(COLOR::GREEN);
    powerTwo(2);
    //powerTwo(len);
    test(B());
    std::cout<<"----------------------------------------\n";
    B b;
    test(b);
    test(B()); //same as test({});
    return 0;
}
