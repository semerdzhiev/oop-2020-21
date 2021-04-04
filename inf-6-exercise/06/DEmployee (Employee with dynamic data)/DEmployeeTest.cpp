#include "catch.hpp"
#include "DEmployee.h"

TEST_CASE("DEmployee: setSalary", "employee")
{
	double initialSalary = 1300;
	DEmployee me{ "Me", "Teacher", initialSalary };

	REQUIRE(me.getSalary() == Approx(initialSalary));

	SECTION("Setting a valid salary")
	{
		double expectedSalary = 1800;

		me.setSalary(expectedSalary);
		double actualSalary = me.getSalary();

		REQUIRE(me.getSalary() == Approx(expectedSalary));
	}

	SECTION("Setting a salary below the lower bound")
	{
		double expectedSalary = 610;

		me.setSalary(400);
		double actualSalary = me.getSalary();

		REQUIRE(me.getSalary() == Approx(expectedSalary));
	}

	SECTION("Setting a salary above the upper bound")
	{
		double expectedSalary = 10000;

		me.setSalary(15000);
		double actualSalary = me.getSalary();

		REQUIRE(me.getSalary() == Approx(expectedSalary));
	}
}