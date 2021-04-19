#include <iostream>
#include "VehicleList.h"

int main() {
    size_t size;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cin.get();
    VehicleList vl(size);

    for (size_t i = 0; i < size; ++i) {
        char regnum[9];
        char description[100];

        std::cin.getline(regnum,9);
        std::cin.getline(description,100);

        try {
            vl.insert(regnum,description);
        } catch (...) {
            std::cerr<<"Invalid data!\n";
            --i;
        }
    }

    std::cout<<"Enter  regnum\n";
    char regnum[9];
    std::cin.getline(regnum,9);

    std::cout<<(vl.find(regnum) ? "Exist!\n" : "Does not exist\n");

    VehicleList vl2(3);
    vl2 = std::move(vl);


    return 0;
}