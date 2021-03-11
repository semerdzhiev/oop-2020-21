#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "point.h"


TEST_CASE("Point", "[point]")
{
    Point testPoint1, testPoint2;

    SECTION("test distance with zeros")
    {
        testPoint1.x = 0;
        testPoint1.y = 0;

        REQUIRE(testPoint1.distance() == 0);
    }
    
    SECTION("test distance with negatives")
    {
        testPoint1.x = -3;
        testPoint1.y = -4;

        REQUIRE(testPoint1.distance() == 5);
    }

    SECTION("test distance with positives") {
        testPoint1.x = 3;
        testPoint1.y = 4;

        REQUIRE(testPoint1.distance() == 5);
    }
    
    SECTION("test distanceFrom with positives")
    {
        // testPoint1.x = 3;
        // testPoint1.y = 4;

        testPoint2.x = 3;
        testPoint2.y = 4;

        REQUIRE(testPoint1.distanceFrom(testPoint2) == 0);
    }

    SECTION("test distance with negatives")
    {
        // testPoint1.x = 3;
        // testPoint1.y = 4;

        testPoint2.x = -3;
        testPoint2.y = -4;

        REQUIRE(testPoint1.distanceFrom(testPoint2) == 10);
    }
}