#define CATCH_CONFIG_MAIN
#include "../../catch2/catch2.hpp"
#include "structs.h"

TEST_CASE("Student", "[student]")
{
    SECTION("test average")
    {
        Student students[1];
        students[0].marks[0].value = 4;
        students[0].marks[1].value = 6;
        students[0].marks[2].value = 5;
        students[0].marks[3].value = 4;
        students[0].marks[4].value = 6;

        REQUIRE(students[0].getAverage() == 5);
    }
}