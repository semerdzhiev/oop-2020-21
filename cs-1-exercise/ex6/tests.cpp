#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp> 
// #include "catch_amalgamated.hpp"

TEST_CASE( "Dummy test - OK" ) {
    REQUIRE( true );
}

TEST_CASE( "Dummy test - KO" ) {
    REQUIRE( false );
}