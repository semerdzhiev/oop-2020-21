#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp> 
#include "gol.cpp" 

/*
Any live cell with fewer than two live neighbours dies, as if by underpopulation.
Any live cell with two or three live neighbours lives on to the next generation.
Any live cell with more than three live neighbours dies, as if by overpopulation.
Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

TEST_CASE( "Universe" ) {

	SECTION ("Compare with the empty grids") {
		bool grid[0][0] = {};
		Universe u1(&grid[0][0], 0, 0);
		Universe u2(&grid[0][0], 0, 0);

		REQUIRE (u1 == u2);
	}

	SECTION ("Compare with empty different sized grids") {
		bool grid1[2][2] = {
			{0, 0},
			{0, 0}
		};
		bool grid2[3][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		};
		Universe u1(&grid1[0][0], 2, 2);
		Universe u2(&grid2[0][0], 3, 3);

		REQUIRE (u1 == u2);
	}

	SECTION ("Compare with different alive cells") {
		bool grid1[2][2] = {
			{1, 0},
			{0, 0}
		};
		bool grid2[2][2] = {
			{0, 0},
			{0, 1}
		};
		Universe u1(&grid1[0][0], 2, 2);
		Universe u2(&grid2[0][0], 3, 3);

		REQUIRE (u1 != u2);
	}
}


TEST_CASE( "Tick a universe with an empty grid" ) {
	bool grid[0][0] = {};

	Universe seed(&grid[0][0], 0, 0);

	GameOfLife game(seed);
	game.tick();
    
    REQUIRE( seed == game.getUniverse() );
}

TEST_CASE( "Tick a universe of only dead cells" ) {
	bool grid[2][2] = {
		{0,0},
		{0,0}
	};

	Universe seed(&grid[0][0], 2, 2);

	GameOfLife game(seed);
	game.tick();
    
    REQUIRE( seed == game.getUniverse() );
}

TEST_CASE( "Tick a universe with a single alive cell" ) {
	bool grid[2][2] = {
		{1,0},
		{0,0}
	};

	Universe seed(&grid[0][0], 2, 2);

	GameOfLife game(seed);
	game.tick();
    
    Universe emptyUniverse(NULL, 0, 0);
    REQUIRE( emptyUniverse == game.getUniverse() );
}

TEST_CASE( "Tick a universe with a cell with that has two neighbours" ) {
	REQUIRE( false );
}


TEST_CASE( "Still Life" ) {
	bool grid[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};

	Universe seed(&grid[0][0], 4, 4);

	GameOfLife game(seed);
	game.tick();
    
    REQUIRE( seed == game.getUniverse() );
}

TEST_CASE( "Oscillator" ) {
    REQUIRE( false );
}


TEST_CASE( "Spaceship" ) {
    REQUIRE( false );
}