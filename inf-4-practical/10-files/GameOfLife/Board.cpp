//
// Created by atanas on 5.05.21 г..
//

#include "Board.h"

Board::Board(size_t new_size) {
    size = new_size;
    field = createBoard(new_size);
}

Board::Board(size_t new_size, char **board) {
    size = new_size;
    field = deepCopy(board, size);
}

char** Board::createBoard(size_t m_size) {
    char** field = new char*[m_size];
    for (int i = 0; i < m_size; ++i) {
        field[i] = new char[m_size];
    }
    return field;
}

char **Board::deepCopy(char **board, size_t size) {
    char** newBoard = createBoard(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            newBoard[i][j] = board[i][j];
        }
    }
    return newBoard;
}

void Board::copy(const Board &other) {
    size = other.size;
    field = deepCopy(other.field, other.size);
}

void Board::free() {
    for (int i = 0; i < size; ++i) {
        delete [] field[i];
    }
    delete [] field;
}

Board::Board(const Board &other) {
    copy(other);
}

Board::Board(Board &&tmp) {
    move(tmp);
}

Board &Board::operator=(const Board &other) {
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Board &Board::operator=(Board &&other) {
    if (this != &other)
    {
        move(other);
    }
    return *this;
}

void Board::move(Board& tmp) {
    size = tmp.size;
    field = tmp.field;

    tmp.size = 0;
    tmp.field = nullptr;
}

Board::~Board() {
    free();
}

Board::operator bool() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (field[i][j] == ALIVE)
                return false;
        }
    }

    return true;
}

int Board::adjCount(int i, int j) const {
    int numberOfAliveAdjacent = 0;
    if (isInBounds(i -1, j - 1) && field[i-1][j-1] == ALIVE) ++numberOfAliveAdjacent;
    if (isInBounds(i -1, j) && field[i-1][j] == ALIVE) ++numberOfAliveAdjacent;
    if (isInBounds(i -1, j + 1) && field[i-1][j+1] == ALIVE) ++numberOfAliveAdjacent;

    if (isInBounds(i, j + 1) && field[i][j+1] == ALIVE) ++numberOfAliveAdjacent;
    if (isInBounds(i, j -1) && field[i][j-1] == ALIVE) ++numberOfAliveAdjacent;

    if (isInBounds(i +1, j - 1) && field[i+1][j-1] == ALIVE) ++numberOfAliveAdjacent;
    if (isInBounds(i +1, j) && field[i+1][j] == ALIVE) ++numberOfAliveAdjacent;
    if (isInBounds(i +1, j + 1) && field[i+1][j+1] == ALIVE) ++numberOfAliveAdjacent;

    return numberOfAliveAdjacent;
}

bool Board::isInBounds(int i, int j) const {
    if (i < 0 || i >= size)
        return false;

    if (j < 0 || j >= size)
        return false;

    return true;
}

Board Board::advance() const {
    Board generation(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (field[i][j] == ALIVE && adjCount(i, j) == 2) {
                generation.field[i][j] = ALIVE;
            } else if (adjCount(i, j) == 3) {
                generation.field[i][j] = ALIVE;
            }
            else {
                generation.field[i][j] = DEAD;
            }
        }
    }
    return generation;
}

void Board::serialize(std::ostream &out) const {
    out << size << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            out << field[i][j];
        }
        out << std::endl;
    }
}

Board Board::deserialize(std::istream &in) {
    size_t size;
    in >> size;
    Board initial(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            in >> initial.field[i][j];
        }
    }
    return initial;
}

std::ostream &operator<<(std::ostream &out, const Board &board) {
    board.serialize(out);
    return out;
}

std::istream &operator>>(std::istream &in, Board &board) {
    board = board.deserialize(in);
    return in;
}
