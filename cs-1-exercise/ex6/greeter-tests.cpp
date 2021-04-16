#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp> 
#include "greeter.h" 

TEST_CASE( "isEmpty" ) {

	SECTION ( "with NULL" ) {
		REQUIRE( isEmpty(NULL) );	
	}

	SECTION( "Empty string" ) {
		REQUIRE( isEmpty("") );
	}

	SECTION( "Non-empty string" ) {
		REQUIRE( !isEmpty("AlaBalaNitsa") );
	}

	SECTION( "Only spaces" ) {
		REQUIRE( isEmpty("     ") );
	}
	
}

TEST_CASE( "Greeter" ) {
	
	Greeter g;

	SECTION( "Hello Message with name" ) {
	    REQUIRE( g.generateHelloMessage("stef") == "Hello stef!" );
	}

	SECTION( "Hello Message with upper case name" ) {
	    REQUIRE( g.generateHelloMessage("STEF") == "Hello STEF!" );
	}

	SECTION( "Hello Message with empty string" ) {
	    REQUIRE( g.generateHelloMessage("") == "Hello World!" );
	}

	SECTION( "Hello Message with NULL as name" ) {
	    REQUIRE( g.generateHelloMessage(NULL) == "Hello World!" );
	}

	SECTION( "Hello Message with long name" ) {
	    REQUIRE( g.generateHelloMessage("Maria de la Santa Cruz Rosalina Agnelia Rodriguez Cuellar Rene") == "Hello Maria de la Santa Cruz Rosalina Agnelia Rodriguez Cuellar Rene!" );
	}
}
