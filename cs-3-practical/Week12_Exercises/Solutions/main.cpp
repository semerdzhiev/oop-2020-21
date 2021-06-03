#include <iostream>
#include "table.h"
#include "chair.h"
#include "bed.h"
#include "collection.h"

using std::cout;

int main() {

    Table myTable(120, 80, 78, 230, 1, KITCHEN);
    myTable.print(std::cout);

    Chair myChair(40, 40, 45, 34, 1, METAL);
    myChair.print(std::cout);

    Bed myBed(200, 160, 25, 565, 1);
    myBed.print(std::cout);

    Collection myFurniture;
    
    myFurniture.add(&myTable);
    myFurniture.add(&myTable);
    myFurniture.add(&myChair);
    myFurniture.add(&myBed);

    myFurniture.save();

    myFurniture.load();

    myFurniture.save();

    return 0;
}