#include "catch.hpp"
#include <cstring>
#include "Car.h"


TEST_CASE("Car - default constructor") {

    Car car;

    CHECK(car.getColor() == 0);
    CHECK(strcmp(car.getModel(), "N/A") == 0);
    CHECK(strcmp(car.getNumber(), "N/A") == 0);
}