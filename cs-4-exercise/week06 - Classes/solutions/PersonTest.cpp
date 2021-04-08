#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include <cstring>
#include "Person.h"

TEST_CASE("Person - default constructor") {

    Person person;

    CHECK(person.getAge() == 20);
    CHECK(strcmp(person.getName(), "N/A") == 0);
    CHECK(strcmp(person.getAddress(), "N/A") == 0);
    CHECK(person.getHasDrivingLicense() == false);
 }

TEST_CASE("Person - constructor with parameters") {

    Person person("Test", "Sofia", 22, true);

    CHECK(person.getAge() == 22);
    CHECK(strcmp(person.getName(), "Test") == 0);
    CHECK(strcmp(person.getAddress(), "Sofia") == 0);
    CHECK(person.getHasDrivingLicense() == true);
}


TEST_CASE("Person - copy constructor") {

    Person person("Test", "Sofia", 22, true);

    Person person2 = person;

    CHECK(person2.getAge() == person.getAge());
    CHECK(strcmp(person2.getName(), person.getName()) == 0);
    CHECK(strcmp(person2.getAddress(), person.getAddress()) == 0);
    CHECK(person2.getHasDrivingLicense() == person.getHasDrivingLicense());
}

TEST_CASE("Person - operator= ") {

    Person person("Test", "Sofia", 22, true);

    Person person2;

    CHECK(person2.getAge() == 20);
    CHECK(strcmp(person2.getName(), "N/A") == 0);
    CHECK(strcmp(person2.getAddress(), "N/A") == 0);
    CHECK(person2.getHasDrivingLicense() == false);

    person2 = person;

    CHECK(person2.getAge() == person.getAge());
    CHECK(strcmp(person2.getName(), person.getName()) == 0);
    CHECK(strcmp(person2.getAddress(), person.getAddress()) == 0);
    CHECK(person2.getHasDrivingLicense() == person.getHasDrivingLicense());
}