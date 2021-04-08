#include "catch.hpp"
#include <cstring>
#include "Parking.h"
#include "Utils.h"
#include "Car.h"

TEST_CASE("Parking - default constructor") {

    Parking parking;

    CHECK(parking.getSize() == 0);
    CHECK(parking.getCapacity() == INITIAL_CAPACITY);
    CHECK(strcmp(parking.getName(), "N/A") == 0);
}


TEST_CASE("Parking - copy constructor") {

    Parking parking;
    parking.setName("Test");

    Parking parking2 = parking;

    CHECK(parking2.getSize() == 0);
    CHECK(parking2.getCapacity() == INITIAL_CAPACITY);
    CHECK(strcmp(parking2.getName(), "Test") == 0);
}

TEST_CASE("Parking - operator= ") {

    Parking parking;
    parking.setName("Test");

    Parking parking2;
    CHECK(strcmp(parking2.getName(), "N/A") == 0);

    parking2 = parking;

    CHECK(parking2.getSize() == 0);
    CHECK(parking2.getCapacity() == INITIAL_CAPACITY);
    CHECK(strcmp(parking2.getName(), "Test") == 0);
}


TEST_CASE("Parking - add Car") {

    Parking parking;

    Car car;
    parking.addCar(car);

    CHECK(parking.getSize() == 1);
    CHECK(parking.getCapacity() == INITIAL_CAPACITY);
}


TEST_CASE("Parking - add Car + resize") {

    Parking parking;

    Car car;
    parking.addCar(car);
    parking.addCar(car);
    parking.addCar(car);

    CHECK(parking.getSize() == 3);
    CHECK(parking.getCapacity() == INITIAL_CAPACITY * INCREMENT_STEP);
}

TEST_CASE("Parking - remove Car + valid index") {

    Parking parking;
    Car car;
    parking.addCar(car);
    CHECK(parking.getSize() == 1);

    parking.remove(0);

    CHECK(parking.getSize() == 0);
}


TEST_CASE("Parking - remove Car + not valid index") {

    Parking parking;
    Car car;
    parking.addCar(car);
    CHECK(parking.getSize() == 1);

    parking.remove(10);

    CHECK(parking.getSize() == 1);
}