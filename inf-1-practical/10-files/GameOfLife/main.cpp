#include <iostream>
#include <fstream>
#include "Board.h"

void read(std::istream&);
void write(std::ostream&);

int main() {
    std::ifstream in("sampleBoard.txt");
    Board b = Board::deserialize(in);
    std::ofstream b1("board1", std::ios::trunc);
    std::ofstream b2("board2", std::ios::trunc);
    b = b.advance();
    b.serialize(b1);
    b = b.advance();
    b.serialize(b2);

    std::fstream file;
    file.open("path", std::ios::in);
    read(file);
    file.close();
    file.open("path", std::ios::app);
    write(file);

    std::cout << "string" << 1 << std::endl;
}
