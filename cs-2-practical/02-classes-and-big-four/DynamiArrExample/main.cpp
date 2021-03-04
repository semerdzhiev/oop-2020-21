#include <iostream>
#include "DynamicArray.h"
using std::cin;
using std::cout;
using std::endl;


int main() {
    DynamicArray arr;
    size_t n;
    std::cin>>n;
    for(size_t i=0;i<n;++i) {
        int temp;
        cin>>temp;
        arr.add(temp);
    }
    arr.print();
    DynamicArray copy;
    copy=arr;
    DynamicArray copy2 = copy;
    return 0;
}
