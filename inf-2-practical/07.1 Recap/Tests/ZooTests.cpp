#include <cstring>
#include "../catch2/catch2.hpp"
#include "../Headers/Zoo.hpp"
#include "../Headers/AnimalFamily.hpp"

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