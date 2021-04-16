#include "../Interp/UserVariable.h"
#include "catch_amalgamated.hpp"

TEST_CASE("UserVariable init test", "") {
	UserVariable var;
	REQUIRE(var.isInit() == false);
	var.setValue(3);
	REQUIRE(var.isInit() == true);
}

TEST_CASE("UserVariable set/get", "") {
	UserVariable var;
	var.setValue(3);
	REQUIRE(var.getValue() == 3);
}