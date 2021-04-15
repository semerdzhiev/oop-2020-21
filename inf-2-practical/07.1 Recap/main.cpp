#include "./Headers/Planet.hpp"

int main()
{
    Planet myPlanet(20, 20);

    myPlanet.addFamilyInFauna("lion", 5);
    myPlanet.addFamilyInFauna("dog", 8);
    myPlanet.addFamilyInFauna("horse", 5);

    // myPlanet.addFamilyInFauna("cat", 3);

    myPlanet.addFamilyInZoo("lion");
    myPlanet.addFamilyInZoo("dog");
    myPlanet.addFamilyInZoo("horse");

    // myPlanet.print();
    // cout << endl;

    // myPlanet.removeFamilyFromZoo("horse");

    // myPlanet.print();
    // cout << endl;

    // myPlanet.removeFamilyFromFauna("dog");

    myPlanet.print();

    return 0;
}