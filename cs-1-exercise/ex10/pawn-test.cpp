#include<iostream>
using namespace std;

class Move {
	
};

class ChessBoard {

};

class Piece {
public:
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const = 0; // абстрактен метод = без имплементация. Не може да бъде private
};


class Pawn : public Piece {
public:
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const {
		cout << "isValid_PAWN_Move " << endl;
		return true;
	}

	void sayPawnMove() {
		cout << "PAWN is movin'" << endl;
	}
};

class King : public Piece {
public:
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const {
		cout << "isValid_KING_Move " << endl;
		return true;
	}

	void sayKingMove() {
		cout << "King is comin'" << endl;
	}
};

int main() {
	Move move;
	ChessBoard board;

	Pawn pawn;
	pawn.isValidMove(move, board);
	pawn.sayPawnMove();

	cout << "===================================" << endl;

	King king;
	king.isValidMove(move, board);
	king.sayKingMove();

	cout << "===================================" << endl;

	Piece& piece1 = pawn;
	Piece& piece2 = king;
	piece1.isValidMove(move, board); // полиморфизъм
	piece2.isValidMove(move, board); // когато викаме метод през референция на родителския клас, но той извиква метода на "правилното" дете.
	// piece1.sayPawnMove(); // compilation error

	cout << "===================================" << endl;

	Piece* p1 = &pawn;
	Piece* p2 = &king;
	p1->isValidMove(move, board);
	p2->isValidMove(move, board);
	// p2->sayKingMove(); // compilation error

	cout << "===================================" << endl;

	Piece* pieces[] = {&pawn, &king, &pawn};
	for (int i = 0; i < 3; i++) {
		pieces[i]->isValidMove(move, board);
	}

	return  0;
}
