//
// Created by atanas on 5.05.21 г..
//

#ifndef GAMEOFLIFE_BOARD_H
#define GAMEOFLIFE_BOARD_H


#include <cstddef>
#include <fstream>

#define ALIVE '+'
#define DEAD '-'

class Board {
public:
    explicit Board(size_t new_size);
    Board(size_t new_size, char** board);
    Board(const Board& other);
    Board(Board&& tmp);
    Board& operator=(const Board& other);
    Board& operator=(Board&& other);
    ~Board();

    operator bool() const;
    Board advance() const;

    void serialize(std::ostream& out) const;
    friend std::ostream& operator<<(std::ofstream& out, const Board& board);
    static Board deserialize(std::istream& in);
    friend std::istream& operator>>(std::istream& in, Board& board);
private:
    size_t size;
    char** field;

    static char** createBoard(size_t m_size);
    static char** deepCopy(char** board, size_t size);
    void copy(const Board& other);
    void free();
    void move(Board& tmp);

    int adjCount(int i, int j) const;
    bool isInBounds(int i, int j) const;
};

/*
 * -----
 * --++-
 * ---+-
 */

#endif //GAMEOFLIFE_BOARD_H
