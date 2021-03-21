#include "catch2/catch.h"
#include "RetiredTeacher.h"
#define CATCH_CONFIG_MAIN

TEST_CASE("Array tests","[array]") {
    DynamicArray<int> arr(2);
    SECTION("testes with empty array") {
        REQUIRE(arr.getSize()==0);
        REQUIRE(arr.remove(2)==false);
    }

    arr.add(2);
    REQUIRE(arr.getSize()==1);
    arr.add(3);arr.add(5);
    REQUIRE(arr.getLast()==5);
    REQUIRE(arr.getFirst()==2);
    REQUIRE(arr.contains(3)==true);
    REQUIRE(arr.contains(99)==false);
}