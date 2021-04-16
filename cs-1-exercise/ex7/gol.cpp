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

	void setAlive(int x, int y) {
		if (x < 0 || y < 0) {
			return;
		}
		if (x >= rows || y >= cols) {
			expandTheGrid(x + 1, y + 1);
		}
		*(grid + x * cols + y) = true;
	}

	int getNumberOfAliveNeighbours(int x, int y) const {
		int neighbours = 0;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				neighbours += this->isCellAlive(x + dx, y + dy);
			}
		}
		neighbours -= this->isCellAlive(x, y);
		return neighbours;
	}

	int getRows() const {
		return rows;
	}

	int getCols() const {
		return cols;
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

	void print() const {
		for (int i = 0; i < rows; i++) {
			cout << "|";
			for (int j = 0; j < cols; j++) {
				cout << " " << this->isCellAlive(i, j) << " | ";
			}
			cout << endl;
		}
	}
private:
	bool * grid;
	int rows;
	int cols;

private:
	void expandTheGrid(int toFitRows, int toFitCols) {
		int newRows = max(rows, toFitRows);
		int newCols = max(cols, toFitCols);
		bool * newGrid = new bool[newRows * newCols];

		for (int i = 0; i < newRows; i++) {
			for (int j = 0; j < newCols; j++) {
				*(newGrid + i * newCols + j) = this->isCellAlive(i, j);
			}
		}

		delete[] this->grid;

		this->grid = newGrid;
		this->rows = newRows;
		this->cols = newCols;
	}

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
	}

	void tick() {
		/*
			----> Any live cell with fewer than two live neighbours dies, as if by underpopulation.
			----> Any live cell with two or three live neighbours lives on to the next generation.
			----> Any live cell with more than three live neighbours dies, as if by overpopulation.
			Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
		*/
		// TODO: apply all rules

		Universe nextGeneration(NULL, 0, 0);
		for (int i = 0; i < this->universe.getRows(); i++) {
			for (int j = 0; j < this->universe.getCols(); j++) {
				int aliveNeighbours = this->universe.getNumberOfAliveNeighbours(i, j);

				if (this->universe.isCellAlive(i, j)) {
					if (2 == aliveNeighbours || 3 == aliveNeighbours) {
						nextGeneration.setAlive(i, j);
					}
				} else {
					if (3 == aliveNeighbours) {
						nextGeneration.setAlive(i, j);
					}
				}
			}
		}
		this->universe = nextGeneration;
	}

	Universe getUniverse() const {
		return this->universe;
	}

	void print() const {
		this->universe.print();
	}

private:
	Universe universe;
};
