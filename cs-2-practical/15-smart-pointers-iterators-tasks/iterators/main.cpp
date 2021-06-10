#include <iostream>
#include<vector>
#include"MyVector.h"

int main() {
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for(std::vector<int>::iterator it = vec.begin();it!=vec.end();++it) {
        std::cout<<(*it)<<' ';
    }
    std::cout<<'\n';

    MyVector<int> arr;
    arr.emplace_back(8);arr.emplace_back(98);arr.emplace_back(75);arr.emplace_back(64);
    for(MyVector<int>::Iterator it = arr.begin();
    it!=arr.end();++it) {
        std::cout<<*it<<' ';
    }
    std::cout<<'\n';
    for(int value : arr) {
        std::cout<<value<<' ';
    }
    return 0;
}
