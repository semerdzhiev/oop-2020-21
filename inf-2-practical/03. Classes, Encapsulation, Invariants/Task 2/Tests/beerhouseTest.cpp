#define CATCH_CONFIG_MAIN
#include "catch2/catch2.hpp"
#include "../Headers/beerhouse.hpp"

TEST_CASE("Creating beerhouse")
{
    Beerhouse beerhouse{};
 
    SECTION("Beerhouse object is created successfully")
    {
        REQUIRE(beerhouse.isEmpty());
    }

    SECTION("Adding element is changing the number of elements") 
    {
        Beer beer1("Tuborg", 4.6, 330);
        beerhouse.addBeer(beer1);

        REQUIRE_FALSE(beerhouse.isEmpty());
        REQUIRE(beerhouse.getNumberOfBeers()==1);
    }
}

TEST_CASE("Selling beers"){

    Beerhouse beerhouse{};
    
    Beer beer1("Tuborg", 4.6, 330);
    beerhouse.addBeer(beer1);
    Beer beer2("Tuborg", 4.6, 500);
    beerhouse.addBeer(beer1);


    SECTION("Selling beer with exact volume") 
    {

        Beer resultBeer = beerhouse.sellBeer("Tuboog", 500);
        REQUIRE(resultBeer.getBrand() == "Tuborg");;
        REQUIRE(resultBeer.getVolume() == 500);
    }

    SECTION("Selling beer with no matching volume") 
    {
        Beer resultBeer = beerhouse.sellBeer("Tuborg", 1000);
        REQUIRE(resultBeer.getBrand() == "Tuborg");
        REQUIRE(resultBeer.getVolume() != 1000);
    }

    SECTION("Selling beer subtracts number of beers")
    {
        unsigned prevNumber = beerhouse.getNumberOfBeers();
        beerhouse.sellBeer("Tuborg", 330);
        unsigned nextNumber = beerhouse.getNumberOfBeers();
        REQUIRE(prevNumber == nextNumber + 1);
    }

}