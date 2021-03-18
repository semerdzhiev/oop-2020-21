#define CATCH_CONFIG_MAIN
#include "../../catch2/catch2.hpp"
#include "structs.h"

TEST_CASE("Rectangular", "[rectangular]")
{
    Rectangular rectangular;
    rectangular.a.setPoint(0, 0);
    rectangular.b.setPoint(5, 5);

    SECTION("test contains - true")
    {

        Point point;
        point.setPoint(2, 2);

        REQUIRE(rectangular.contains(point));
    }

    SECTION("test contains - false")
    {
        Point point;
        point.setPoint(4, 6);

        REQUIRE_FALSE(rectangular.contains(point));
    }

    SECTION("test intersects - true")
    {
        Rectangular secondRectangular;
        secondRectangular.a.setPoint(2, 2);
        secondRectangular.b.setPoint(6, 6);

        REQUIRE(rectangular.intersectingWith(secondRectangular));
    }

    SECTION("test intersects - false")
    {
        Rectangular secondRectangular;
        secondRectangular.a.setPoint(6, 8);
        secondRectangular.b.setPoint(2, 8);

        REQUIRE_FALSE(rectangular.intersectingWith(secondRectangular));
    }
}