#include <iostream>
//#include "test.cpp"
#include "Player.h"
#include "Player.h"

void LOG(const char *msg){
    std::cout<<msg<<std::endl;
}

void INIT();
void staticF();
void nonStatic();
int x=1;


int main() {
    //LOG("ad");
    //staticF();
    nonStatic();
    std::cout<<x<<std::endl;
    //INIT();
    return 0;
}