#include <iostream>
#include "computer_shop.h"
#include "computer_utils.h"

using std::cout;
using std::endl;

int main() {

    ComputerShop myShop;

    Computer comp1("Lenovo", "i5", "3060", 750, 2.76, 4, 2400, 1);

    myShop.addComputer(comp1);

    for (int i = 0; i < myShop.getSize(); i++) {
        myShop.getComputers()[i].print();
    }

    cout << "-----------\n";

    Computer comp2("Dell", "i3", "3010", 250, 1.76, 6, 1800, 1);

    myShop.addComputer(comp2);
    cout << myShop.getSize() << endl;

    cout << "-----------\n";

    myShop.getComputersInStock(ComputerUtils::isGoodForGaming)[0].print();

    cout << "-----------\n";

    myShop.buyComputer("Dell", 1900);

    return 0;
}