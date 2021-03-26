#include<iostream>

using namespace std;


class Universe {
public:
	Universe(bool * grid, int rows, int cols) {
	}

	bool operator==(const Universe & other) {
		return this == &other;
	}
private:
	// ???
}


class GameOfLife {
public:
	GameOfLife(Universe seed) {
		this->universe = seed;
	}

	void tick() {
		// TODO: apply all rules
	}

	Universe getUniverse() const {
		return this->universe;
	}

private:
	Universe universe; // ???
}

void assertEquals(Universe u1, Universe u2) {
	if (u1 == u2) {
		cout << "OK" << endl;
	} else {
		cout << "NOK" << endl;
	}
}

void testStillLife() {
	// Block
	// Alive cells are: (0,0), (1,0), (0,1), (1,1)

	// // option 1
	// Cell c1;
	// Cell seed[4] = {
	// 	c1,c1,c1,c1
	// };

	// // option 2
	// Seed seed;

	// option 3

	// option 3.1.
	{
		bool grid[4][4] = {
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		};
	}

	// // option 3.2.
	// {
	// 	const char* grid = 
	// 		"____\n"
	// 		"_AA_\n"
	// 		"_AA_\n"
	// 		"____";
	// }

	// // option 3.3.
	// {
	// 	Cell aliveCells[] = {
	// 		Cell(0, 0),
	// 		Cell(1, 0),
	// 		Cell(0, 1),
	// 		Cell(1, 1)
	// 	};
	// }
	
	Universe seed(&grid[0][0], 4, 4);
	// // option 3.4
	// {
	// 	seed.setAlive(0, 0);
	// 	seed.setAlive(1, 0);
	// 	seed.setAlive(0, 1);
	// 	seed.setAlive(1, 1);
	// }
	
	
	GameOfLife game(seed);
	game.tick();
	assertEquals(seed, game.getUniverse());
}

void testOscillator() {
	// Toad
}

void testSpaceship() {
	// Glider
}

int main() {
	testStillLife();
	testOscillator();
	testSpaceship();
	return 0;
}