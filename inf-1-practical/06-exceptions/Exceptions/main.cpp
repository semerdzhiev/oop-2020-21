#include <iostream>
#include "MessageProcessor.h"

int main() {
    MessageProcessor m1("long msg");
    MessageProcessor m2("some error");
    MessageProcessor m3(nullptr);

    m1.printMessage();
    try {
        m2.printMessage();
        m3.printMessage();
    } catch (...) {
        std::cerr << "supressed error" <<std::endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
