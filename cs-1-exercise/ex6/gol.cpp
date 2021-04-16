#include<iostream>
using namespace std;

class Universe {
public:
	Universe(bool * grid, int rows, int cols) {
		copy(grid, rows, cols);
	}

	Universe(const Universe & other) {
		copy(other);
	}

	Universe& operator=(const Universe & other) {
		if (this != &other) {
			destroy();
			copy(other);
		}
		return *this;
		
	}

	~Universe() {
		destroy();
	}

	bool isCellAlive(int x, int y) const {
		if (x < 0 || y < 0) {
			return false;
		}
		if (x >= rows || y >= cols) {
			return false;
		}
		// grid[x][y]
		return *(grid + x * cols + y);
	}

	bool operator==(const Universe & other) const {
		int maxRows = max(this->rows, other.rows);
		int maxCols = max(this->cols, other.cols);

		for (int i = 0; i < maxRows; i++) {
			for (int j = 0; j < maxCols; j++) {
				if (this->isCellAlive(i, j) != other.isCellAlive(i, j)) {
					return false;
				}
			}
		}
		return true;
	}

	bool operator!=(const Universe & other) const {
		return !this->operator==(other);
	}
private:
	bool * grid;
	int rows;
	int cols;

private:
	void copy(const Universe & other) {
		copy(other.grid, other.rows, other.cols);
	}

	void copy(bool * grid, int rows, int cols) {
		this->grid = new bool[rows * cols];
		for (int i = 0; i < rows * cols; i++) {
			this->grid[i] = grid[i];
		}
		this->rows = rows;
		this->cols = cols;
	}

	void destroy() {
		if (grid) {
			delete[] grid;	
		}
	}
};


class GameOfLife {
public:
	GameOfLife(Universe seed): universe(seed) {
		// this->universe = seed;
	}

	void tick() {
		// TODO: apply all rules
	}

	Universe getUniverse() const {
		return this->universe;
	}

private:
	Universe universe; // ???
};
