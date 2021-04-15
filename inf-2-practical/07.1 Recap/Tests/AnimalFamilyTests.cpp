#define CATCH_CONFIG_MAIN
#include <cstring>
#include "../catch2/catch2.hpp"
#include "../Headers/AnimalFamily.hpp"

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
    REQUIRE(animalFamily.getMembers() == 15);
}