#include <cstring>
#include "../catch2/catch2.hpp"
#include "../Headers/Fauna.hpp"
#include "../Headers/AnimalFamily.hpp"

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

    AnimalFamily* animalFamilyPtr = fauna.find("dog");

    REQUIRE(!strcmp(animalFamilyPtr->getName(), "dog"));
    REQUIRE(animalFamilyPtr->getMembers() == 9);
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