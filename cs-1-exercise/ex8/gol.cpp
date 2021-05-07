#include<iostream>
using namespace std;

class Cell {
public:
	Cell(int row = 0, int col = 0) {
		this->row = row;
		this->col = col;
	}

	int getRow() const {
		return row;
	}

	int getCol() const {
		return col;
	}

	bool operator==(const Cell & other) {
		return this->row == other.row && this->col == other.col;
	}
private:
	int row;
	int col;
};

class Universe {
public:
	Universe(bool * grid, int rows, int cols) {
		initAliveCells(grid, rows, cols);
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

	bool isCellAlive(int r, int c) const {
		Cell cell(r, c);
		for (int i = 0; i < this->aliveCellsCount; i++) {
			if (this->aliveCells[i] == cell) {
				return true;
			}
		}
		return false;
	}

	void setAlive(int r, int c) {
		if (!isCellAlive(r, c)) {
			expandTheAliveCellsAndAdd(r, c);
		}
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

	int getFirstRow() const {
		int firstRow = 0;
		for (int i = 0; i < this->aliveCellsCount; i++) {
			if (firstRow > this->aliveCells[i].getRow()) {
				firstRow = this->aliveCells[i].getRow();
			}
		}
		return firstRow - 1;
	}

	int getLastRow() const {
		int lastRow = 0;
		for (int i = 0; i < this->aliveCellsCount; i++) {
			if (lastRow < this->aliveCells[i].getRow()) {
				lastRow = this->aliveCells[i].getRow();
			}
		}
		return lastRow + 2;
	}

	int getFirstCol() const {
		int firstCol = 0;
		for (int i = 0; i < this->aliveCellsCount; i++) {
			if (firstCol > this->aliveCells[i].getCol()) {
				firstCol = this->aliveCells[i].getCol();
			}
		}
		return firstCol - 1;
	}

	int getLastCol() const {
		int lastCol = 0;
		for (int i = 0; i < this->aliveCellsCount; i++) {
			if (lastCol < this->aliveCells[i].getCol()) {
				lastCol = this->aliveCells[i].getCol();
			}
		}
		return lastCol + 2;
	}

	bool operator==(const Universe & other) const {
		int minFirstRow = min(this->getFirstRow(), other.getFirstRow());
		int minFirstCol = min(this->getFirstCol(), other.getFirstCol());
		int maxLastRow = max(this->getLastRow(), other.getLastRow());
		int maxLastCol = max(this->getLastCol(), other.getLastCol());

		for (int i = minFirstRow; i < maxLastRow; i++) {
			for (int j = minFirstCol; j < maxLastCol; j++) {
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
		for (int i = getFirstRow(); i < getLastRow(); i++) {
			cout << "|";
			for (int j = getFirstCol(); j < getLastCol(); j++) {
				cout << " " << this->isCellAlive(i, j) << " | ";
			}
			cout << endl;
		}
	}
private:
	Cell * aliveCells;
	int aliveCellsCount;

private:
	void expandTheAliveCellsAndAdd(int row, int col) {
		Cell newCell(row, col);
		Cell * newAliveCells = new Cell[this->aliveCellsCount + 1];
		for (int i = 0; i < this->aliveCellsCount; i++) {
			newAliveCells[i] = this->aliveCells[i];
		}

		newAliveCells[this->aliveCellsCount] = newCell;

		delete[] this->aliveCells;
		this->aliveCells = newAliveCells;
		this->aliveCellsCount++;
	}


	void copy(const Universe & other) {
		copy(other.aliveCells, other.aliveCellsCount);
	}

	void copy(Cell * aliveCells, int aliveCellsCount) {
		this->aliveCellsCount = aliveCellsCount;
		this->aliveCells =new Cell[aliveCellsCount];

		for (int i = 0; i < aliveCellsCount; i++) {
			this->aliveCells[i] = aliveCells[i];
		}
	}

	void initAliveCells(bool * grid, int rows, int cols) {
		this->aliveCellsCount = 0;
		for (int i = 0; i < rows * cols; i++) {
			if (grid[i]) {
				this->aliveCellsCount++;
			}
		}
		this->aliveCells = new Cell[this->aliveCellsCount];
		int k = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (grid[i * cols + j]) {
					Cell cell(i, j);
					this->aliveCells[k++] = cell;
				}
			}
		}
	}

	void destroy() {
		if (aliveCells) {
			delete[] aliveCells;
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
		for (int i = this->universe.getFirstRow(); i < this->universe.getLastRow(); i++) {
			for (int j = this->universe.getFirstCol(); j < this->universe.getLastCol(); j++) {
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
