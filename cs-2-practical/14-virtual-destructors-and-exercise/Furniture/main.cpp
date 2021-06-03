#include <iostream>
#include<vector>
#include "Bed.h"
#include "Table.h"
#include "Chair.h"
#include "MyVector.h"


int main() {
    MyVector<Furniture*> arr;
    Bed b(5,6,7,100,5,105);
    Chair c(2);
    Table t(6);
    arr.push_back(&b);arr.push_back(&c);arr.push_back(&t);
    for(size_t i=0;i<arr.getSize();++i) {
        arr[i]->print(std::cout);
    }
    std::cout<<"=------------------------=\n";
    arr.removeFurniture(Chair(2));
    for(size_t i=0;i<arr.getSize();++i) {
        arr[i]->print(std::cout);
    }
    return 0;
}
