#include <cstring>
#include "catch2.h"
#include "AnimalFamily.h"
#include "Planet.h"
#include "Zoo.h"

TEST_CASE("AnimalFamily is Rule of 3 Compliant")
{
    AnimalFamily animalFamily("lion", 15);
    AnimalFamily copyOperatorAnimalFamily("dog", 10);
    REQUIRE_NOTHROW(AnimalFamily(animalFamily));
    REQUIRE_NOTHROW(copyOperatorAnimalFamily = animalFamily);
}

TEST_CASE("Can get AnimalFamily name")
{
    AnimalFamily animalFamily("lion", 15);
    REQUIRE(!strcmp("lion", animalFamily.getName()));
}

TEST_CASE("Can get AnimalFamily members count")
{
    AnimalFamily animalFamily("lion", 15);
    REQUIRE(animalFamily.getNumber() == 15);
}

TEST_CASE("Handles adding new families")
{
    Zoo zoo(10);
    AnimalFamily lion("lion", 5);
    AnimalFamily cat("cat", 2);
    AnimalFamily dog("dog", 5);
    REQUIRE_NOTHROW(zoo.addFamily(lion));
    REQUIRE_NOTHROW(zoo.addFamily(cat));
    REQUIRE_THROWS(zoo.addFamily(dog), "Reached capacity in Zoo");
}

TEST_CASE("Handles removing families")
{
    Zoo zoo(10);
    AnimalFamily lion("lion", 5);
    AnimalFamily cat("cat", 2);
    AnimalFamily dog("dog", 5);
    zoo.addFamily(lion);
    zoo.addFamily(cat);

    REQUIRE(zoo.removeFamily("lion") == &lion);
    REQUIRE(!zoo.removeFamily("dog"));
    REQUIRE_NOTHROW(zoo.addFamily(dog));
}

TEST_CASE("Fauna handles overflowing")
{
    Fauna fauna(20);
    REQUIRE_NOTHROW(fauna.addFamily("lion", 8));
    REQUIRE_NOTHROW(fauna.addFamily("dog", 9));
    REQUIRE_THROWS(fauna.addFamily("cat", 5), "Reached capacity in Fauna");
    REQUIRE_NOTHROW(fauna.addFamily("cat", 2));
}

TEST_CASE("Find works correctly")
{
    Fauna fauna(20);
    fauna.addFamily("lion", 8);
    fauna.addFamily("dog", 9);
    fauna.addFamily("cat", 2);

    const AnimalFamily *animalFamilyPtr = fauna.at(fauna.find("dog"));

    REQUIRE(!strcmp(animalFamilyPtr->getName(),"dog"));
    REQUIRE(animalFamilyPtr->getNumber()== 9);
}

TEST_CASE("Remove family works correctly")
{
    Fauna fauna(20);
    fauna.addFamily("lion", 8);
    fauna.addFamily("dog", 9);

    REQUIRE(fauna.find("lion"));
    REQUIRE(!fauna.find("cat"));

    fauna.addFamily("cat", 2);
    REQUIRE(fauna.find("cat"));

    REQUIRE_NOTHROW(fauna.removeFamily("horse"));

    fauna.removeFamily("cat");
    REQUIRE(!fauna.find("cat"));
}

