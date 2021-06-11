#include <iostream>
#include<vector>
#include"MyVector.h"

int main() {
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for(std::vector<int>::iterator it = vec.begin();it!=vec.end();++it) {
        std::cout<<(*it)<<' ';
    }
    std::cout<<'\n';

    for(const auto& el : vec) {
        std::cout<<el<<' ';
    }
    std::cout<<'\n';

    MyVector<std::string> arr;
    arr.emplace_back("Ivan");arr.emplace_back("Atanas");arr.emplace_back("Peter");arr.emplace_back("John");
    for(MyVector<std::string>::Iterator it = arr.begin();
    it!=arr.end();++it) {
        std::cout<<*it<<' ';
    }
    std::cout<<'\n';
    for(const auto& value : arr) {
        std::cout<<value<<' ';
    }
    return 0;
}
