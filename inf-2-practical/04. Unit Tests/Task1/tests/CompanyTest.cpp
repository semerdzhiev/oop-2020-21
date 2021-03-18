#define CATCH_CONFIG_MAIN
#include "./catch2/catch2.hpp"
#include "../headers/Company.hpp"
#include "../headers/Employee.hpp"

TEST_CASE("Company is default initalized correctly")
{
    Company company{};
    REQUIRE(company.count() == 0);
    REQUIRE(company.empty());
}

TEST_CASE("Adding an employee to company works")
{
    Company company{};
    Employee employee1{"Pesho", 30, 800};
    company.add(employee1);
    REQUIRE(company.count() == 1);
}

TEST_CASE("Firing non existing employee does nothing")
{
    Company company{};
    Employee employee1{"Pesho", 30, 800};
    company.add(employee1);
    auto fireResult = company.fire("Tosho");
    REQUIRE(!fireResult);
    REQUIRE(company.count() == 1);
}

TEST_CASE("Firing employee works")
{
    Company company{};
    Employee employee1{"Pesho", 30, 800};
    company.add(employee1);
    auto fireResult = company.fire("Pesho");
    REQUIRE(fireResult);
    REQUIRE(company.count() == 0);
}