#define CATCH_CONFIG_MAIN
#include "../../catch2/catch2.hpp"
#include "runner.h"

TEST_CASE("Runner", "[runner]")
{

    Runner runner1;

    for (int i = 0; i < NUMBER_OF_MARATHONS; i++)
    {
        runner1.times[i] = i * 10;
    }

    SECTION("test pace")
    {
        REQUIRE(runner1.getPace() == 55.0);
    }

    SECTION("test beat N times")
    {
        Runner runner2;

        for (int i = 0; i < NUMBER_OF_MARATHONS; i++)
        {
            runner2.times[i] = i * 15;
        }

        REQUIRE(runner1.beatNtimes(&runner2) == 11);
    }
}