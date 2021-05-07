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

		REQUIRE( u1 == u2 );
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

		REQUIRE( u1 == u2 );
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
		Universe u2(&grid2[0][0], 2, 2);

		REQUIRE( u1 != u2 );
	}

	SECTION ("Compare with different sized grids and different alive cells") {
		bool grid1[4][4] = {
			{1, 0, 1, 0},
			{1, 1, 1, 0},
			{1, 1, 1, 0},
			{0, 0, 1, 0}
		};
		bool grid2[3][3] = {
			{1, 0, 1},
			{1, 1, 1},
			{1, 1, 1}
		};
		Universe u1(&grid1[0][0], 4, 4);
		Universe u2(&grid2[0][0], 3, 3);

		REQUIRE( u1 != u2 );
	}


	SECTION ("Set alive of a cell outside the grid") {
		bool grid[1][1] = {
			{0},
		};

		Universe universe(&grid[0][0], 1, 1);
		universe.setAlive(10, 5);

		REQUIRE( universe.isCellAlive(10, 5) );
	}

	SECTION ("Set alive inside the existing grid") {
		bool grid[2][2] = {
			{0, 0},
			{0, 0}
		};
		
		Universe universe(&grid[0][0], 2, 2);
		universe.setAlive(0, 1);

		REQUIRE( universe.isCellAlive(0, 1) );
	}

	SECTION ("Set alive with less cols, but more rows") {
		bool grid[2][2] = {
			{0, 1},
			{0, 0}
		};
		
		Universe universe(&grid[0][0], 2, 2);
		universe.setAlive(5, 0);

		REQUIRE( universe.isCellAlive(0, 1) );
		REQUIRE( universe.isCellAlive(5, 0) );
	}


	SECTION ("Set alive with less rows, but more cols") {
		bool grid[2][2] = {
			{0, 0},
			{1, 0}
		};
		
		Universe universe(&grid[0][0], 2, 2);
		universe.setAlive(0, 6);

		REQUIRE( universe.isCellAlive(1, 0) );
		REQUIRE( universe.isCellAlive(0, 6) );
	}

	SECTION ("getNumberOfAliveNeighbours with cell in the middle") {
		bool grid[3][3] = {
			{1, 0, 1},
			{0, 1, 1},
			{1, 1, 0}
		};
		Universe universe(&grid[0][0], 3, 3);
		REQUIRE( 5 == universe.getNumberOfAliveNeighbours(1, 1) );
	}

	SECTION ("getNumberOfAliveNeighbours with cell on one side") {
		bool grid[3][3] = {
			{1, 0, 1},
			{0, 1, 1},
			{1, 1, 0}
		};
		Universe universe(&grid[0][0], 3, 3);
		REQUIRE( 4 == universe.getNumberOfAliveNeighbours(1, 0) );
	}

	SECTION ("getNumberOfAliveNeighbours with cell on the corner") {
		bool grid[3][3] = {
			{1, 0, 1},
			{0, 1, 1},
			{1, 1, 0}
		};
		Universe universe(&grid[0][0], 3, 3);
		REQUIRE( 2 == universe.getNumberOfAliveNeighbours(0, 2) );
	}
}


TEST_CASE( "Tick a universe" ) {

	SECTION( "With an empty grid" ) {
		bool grid[0][0] = {};

		Universe seed(&grid[0][0], 0, 0);

		GameOfLife game(seed);
		game.tick();
	    
	    REQUIRE( seed == game.getUniverse() );
	}

	SECTION( "Of only dead cells" ) {
		bool grid[2][2] = {
			{0,0},
			{0,0}
		};

		Universe seed(&grid[0][0], 2, 2);

		GameOfLife game(seed);
		game.tick();
	    
	    REQUIRE( seed == game.getUniverse() );
	}

	SECTION( "With a single alive cell" ) {
		bool grid[2][3] = {
			{0,1,0},
			{0,0,0}
		};

		Universe seed(&grid[0][0], 2, 3);

		GameOfLife game(seed);
		game.tick();
	    
	    Universe emptyUniverse(NULL, 0, 0);
	    REQUIRE( emptyUniverse == game.getUniverse() );
	}

	SECTION( "Any live cell with TWO live neighbours lives on to the next generation" ) {
		bool grid[3][3] = {
			{1,0,0},
			{0,1,0},
			{0,0,1}
		};
		Universe seed(&grid[0][0], 3, 3);

		GameOfLife game(seed);
		game.tick();
	    
		REQUIRE( game.getUniverse().isCellAlive(1, 1) );
	}

	SECTION( "Any live cell with three live neighbours lives on to the next generation" ) {
		bool grid[4][4] = {
			{0,1,0,1},
			{0,0,1,0},
			{0,0,1,0}
		};
		Universe seed(&grid[0][0], 4, 4);

		GameOfLife game(seed);
		game.tick();

		REQUIRE( game.getUniverse().isCellAlive(1, 2) );
	}

	SECTION( "Alive cell with more than three live neighbours dies, as if by overpopulation" ) {
		bool grid[4][5] = {
			{0,1,0,1,0},
			{0,0,1,0,0},
			{0,1,0,1,0},
		};
		Universe seed(&grid[0][0], 4, 5);

		GameOfLife game(seed);
		game.tick();

		REQUIRE( !game.getUniverse().isCellAlive(1, 2) );
	}

	SECTION( "Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." ) {
		bool grid[4][5] = {
			{0,1,0,1,0},
			{0,0,1,0,0},
			{0,1,0,1,0},
		};
		Universe seed(&grid[0][0], 4, 5);

		GameOfLife game(seed);
		game.tick();
	    
		bool expectedGrid[4][5] = {
			{0,0,1,0,0},
			{0,1,0,1,0},
			{0,0,1,0,0},
		};
	    Universe expectedUniverse(&expectedGrid[0][0], 4, 5);
		REQUIRE( expectedUniverse == game.getUniverse() );
	}

	SECTION("Alive cells out of bound") {
	    bool grid[1][3] = {
	        {1,1,1},
	    };
	    Universe seed(&grid[0][0], 1, 3);
	    GameOfLife game(seed);
	    game.tick();

	    REQUIRE( game.getUniverse().isCellAlive(1, 1) );
	    REQUIRE( game.getUniverse().isCellAlive(0, 1) );
	    REQUIRE( game.getUniverse().isCellAlive(-1, 1) );
	}
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
    bool grid[1][3] = {
        {1,1,1},
    };
    Universe seed(&grid[0][0], 1, 3);
    GameOfLife game(seed);
    
    game.tick();
    REQUIRE( game.getUniverse().isCellAlive(1, 1) );
    REQUIRE( game.getUniverse().isCellAlive(0, 1) );
    REQUIRE( game.getUniverse().isCellAlive(-1, 1) );

    game.tick();
    REQUIRE( game.getUniverse().isCellAlive(0, 0) );
    REQUIRE( game.getUniverse().isCellAlive(0, 1) );
    REQUIRE( game.getUniverse().isCellAlive(0, 2) );
}


TEST_CASE( "Spaceship" ) {
    REQUIRE( true ); // TODO
}
