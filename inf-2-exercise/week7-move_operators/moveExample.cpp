/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class A {
    int n;
    int* arr;

    void copy(const A& other) {
        n = other.n;
        for(int i = 0; i< n; ++i) {
            arr[i] = other.arr[i];
        }
    }

public:
    A(int n, int dv = 0): n(n) {
        arr = new int[n];
    }

    A(const A& other) {
        copy(other);
    }

    A& operator=(const A& other) {
        if(this != &other) {
            copy(other);
        }
        return *this;

    }

    A(A&& other): n(n), arr(arr) {
        other.n = 0;
        other.arr = NULL;
    }

    A& operator=(A&& other) {
        if(this != &other) {
            delete [] arr;

            n = other.n;
            arr = other.arr;

            other.n = 0;
            other.arr = NULL;
        }
        return *this;
    }

    ~A() {
        delete [] arr;
    }

    A getOddIndexElements() {
        A result(n/2 + 1);
        for(int i = 1; i< n; i+=2) {
            result.arr[i/2 + 1] = arr[i];
        }
        return result;
    }

    void print() {
        cout<< n;
    }
};

int main()
{
    A a1(5);

    A a2 = a1.getOddIndexElements(); // good
    A a3(std::move(a1.getOddIndexElements())); // good

    // A a4(std::move(a3)); // dangerous

    return 0;
}
