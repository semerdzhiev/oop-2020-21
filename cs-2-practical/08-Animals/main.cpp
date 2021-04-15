#include "Planet.h"


int main() {
    Planet planet(50, 50);
    planet.addFamilyFauna(AnimalFamily("Cats", 5));
    planet.addFamilyZoo("Dogs", 10);
    planet.addFamilyFauna("Birds", 3);
    planet.print(std::cout);

    std::cout<<"\nAfter changes\n";
    planet.removeFamilyZoo("Dogs");
    planet.addFamilyZoo(AnimalFamily("Lizards",4));
    planet.print(std::cout);

    return 0;
}