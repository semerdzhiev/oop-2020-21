#include <iostream>
#include<array>
#include<tuple>
#include<string>
#include<ranges>
#include <aspell.h>
#include<span>


template <std::size_t SIZE>
bool isIvanIn(const std::array<std::string, SIZE>& array) {
    for(const auto &str : array)
        if(str=="Ivan")
            return true;
    return false;
}

std::string f(const auto& array) {
    for(const auto &str : array)
        if(str=="Ivan")
            return "true";
    return "false";
}

template <size_t S>
bool g(const std::array<std::string, S>& array) {
    std::any_of(array.begin(), array.end(), [](const auto &s) { return s == "Petko"; });
}

struct MyStruct {
    int a;
    bool b;
    float f;
};

MyStruct funct() {
   return {2,false,3.14f};
}

template <size_t S>
void test(std::array<std::string,S> arr) {

}

int main() {
    std::array<std::string,5> array;
    array[0] = "Mitko"; array[1] ="Ivan";array[2]="Gosho";array[3]="Pesho",array[4] = "Petko";
    std::cout<<isIvanIn(array)<<std::endl<<f(array)<<'\n'<<g(array);
    test(array);
    return 0;
}
