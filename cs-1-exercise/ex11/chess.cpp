#include<iostream>
using namespace std;

class ChessBoard;

// ////////////////////////////////////////////////////////

enum Player {
	WHITE, BLACK
};

// ////////////////////////////////////////////////////////

class Position {
public:
	Position(int column, int row) {
		this->column = column;
		this->row = row;
	}

	int getColumn() const {
		return this->column;
	}

	int getRow() const {
		return this->row;
	}
private:
	int column;
	int row;
};

// ////////////////////////////////////////////////////////

// Indexing of rows is a-h
// Indexing of columns is 1-8
class Move {
public:
	Move(char fromColumn, int fromRow, char toColumn, int toRow) {
		this->setFromColumn(fromColumn);
		this->setFromRow(fromRow);
		this->setToColumn(toColumn);
		this->setToRow(toRow);
	}

	void setFromColumn(char fromColumn) {
		this->fromColumn = assertValidColumnAndRowRange(fromColumn - 'a' + 1);
	}

	void setFromRow(int fromRow) {
		this->fromRow = assertValidColumnAndRowRange(fromRow);
	}

	void setToColumn(char toColumn) {
		this->toColumn = assertValidColumnAndRowRange(toColumn - 'a' + 1);
	}

	void setToRow(int toRow) {
		this->toRow = assertValidColumnAndRowRange(toRow);
	}

	Position getFromPosition() const {
		Position res(fromColumn, fromRow);
		return res;
	}

	Position getToPosition() const {
		Position res(toColumn, toRow);
		return res;
	}


private:
	int assertValidColumnAndRowRange(int x) {
		assert(1 <= x && x <= 8);
		return x;
	}

private:
	// indexing is 1-8 for rows and columns
	int fromColumn;
	int fromRow;
	int toColumn;
	int toRow;
};


// ////////////////////////////////////////////////////////

class Piece {
public:
	Piece(Player player) {
		this->player = player;
	}


	Player getPlayer() const {
		return player;
	}

	bool isWhite() const {
		return getPlayer() == Player::WHITE;
	}

	bool isBlack() const {
		return !isWhite();
	}

	// абстрактен метод = без имплементация. Не може да бъде private
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const = 0; 
	virtual ~Piece() {} // needed for the delete piece in the ChessBoard

private:
	Player player;
};


// ////////////////////////////////////////////////////////

/**
	Board Setup:
		Whites are in front of us
		Rows: 1-8 increment away from us
		On initial setup: rows 1 & 2 are black they move "up"
		On initial setup: rows 7 & 8 are black they move "down"
*/
class ChessBoard {
public:
	ChessBoard() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				this->pieces[i][j] = nullptr;
			}
		}
	}

	bool isEmpty(Position position) const {
		return nullptr == this->pieces[position.getColumn() - 1][position.getRow() - 1];
	}

	void set(char onColumn, int onRow, Piece* piece) {
		if (this->pieces[onColumn - 'a'][onRow - 1] != nullptr) {
			delete this->pieces[onColumn - 'a'][onRow - 1];
		}
		this->pieces[onColumn - 'a'][onRow - 1] = piece;
	}

	const Piece& get(char onColumn, int onRow) const {
		assert(this->pieces[onColumn - 'a'][onRow - 1] != nullptr);
		return *this->pieces[onColumn - 'a'][onRow - 1];
	}

	const Piece& get(Position onPosition) const {
		assert(this->pieces[onPosition.getColumn() - 1][onPosition.getRow() - 1] != nullptr);
		return *this->pieces[onPosition.getColumn() - 1][onPosition.getRow() - 1];
	}

	~ChessBoard() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->pieces[i][j] != nullptr) {
					delete this->pieces[i][j];
				}
			}
		}
	}

private:
	Piece* pieces[8][8];
};

// ////////////////////////////////////////////////////////

const int PAWS_STARTING_ROWS_WHITE = 2;
const int PAWS_STARTING_ROWS_BLACK = 7;

class Pawn : public Piece {
public:
	Pawn(Player player) : Piece(player) {}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const {
		Position fromPosition = move.getFromPosition();
		Position toPosition = move.getToPosition();

		int moveDirection = isWhite() ? 1 : -1;

		if (fromPosition.getColumn() == toPosition.getColumn()) {
			if ((toPosition.getRow() - fromPosition.getRow()) * moveDirection == 1) {
				return board.isEmpty(toPosition);
			}

			if ((toPosition.getRow() - fromPosition.getRow()) * moveDirection == 2) {
				if (isWhite() && fromPosition.getRow() != PAWS_STARTING_ROWS_WHITE) {
					return false;
				}

				if (isBlack() && fromPosition.getRow() != PAWS_STARTING_ROWS_BLACK) {
					return false;
				}


				Position middlePosition(fromPosition.getColumn(), fromPosition.getRow() + moveDirection);
				if (!board.isEmpty(middlePosition)) {
					return false;
				}

				if (!board.isEmpty(toPosition)) {
					return false;
				}

				return true;
			}

			return false;
		} else if (abs(fromPosition.getColumn() - toPosition.getColumn()) == 1) {
			if ((toPosition.getRow() - fromPosition.getRow()) * moveDirection != 1) {
				return false;
			}

			if (board.isEmpty(toPosition)) {
				return false;
			}

			if (board.get(toPosition).getPlayer() == this->getPlayer()) {
				return false;
			}

			return true;
		} else {
			return false;
		}
	}
};

// ////////////////////////////////////////////////////////

class Knight : public Piece {
public:
	Knight(Player player) : Piece(player) {}
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { return false; }
};

class Bishop : public Piece {
public:
	Bishop(Player player) : Piece(player) {}
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { return false; }
};

class Rook : public Piece {
public:
	Rook(Player player) : Piece(player) {}
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { return false; }
};

class Queen : public Piece {
public:
	Queen(Player player) : Piece(player) {}
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { return false; }
};

class King : public Piece {
public:
	King(Player player) : Piece(player) {}
	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { return false; }
};

// ////////////////////////////////////////////////////////

class ChessGameRules {
public:
	bool isMoveValid(const Move & move, const ChessBoard & board) const {
		return true;
		// return isTheMoveInTheBoard(move, board)
		// 	&& isMovingFigureFromTheCorrectColor(move, board)
		// 	&& isCorrectPieceMove(move, board);
	}

// private:
// 	bool isCorrectPieceMove(Move move) {
// 		Piece * piece = chessBoard.getPiece(move.getFromPosition()); // ??? how to handle empty spaces
// 		return piece->isValidMove();
// 	}
};

class ChessGame {
public: 
	bool makeMove(Move move) {
		if (!rules.isMoveValid(move, this->board)) {
			return false;
		}

		// if (isCurrentPlayerCheckAfterTheMove()) {
		// 	return false;
		// }

		// applyMove(move);
		return true;
	}


	bool hasGameEnded() {
		return false;
	}

	// getGameStatus() -> NOT_STARTED, ONGOING, WHITE_WINS, BLACK_WINS, DRAW

private:
	ChessGameRules rules;
	ChessBoard board;
};


int testCaseNumber = 1;

void expect(bool isTrue) {
	if (isTrue) {
		cout << "Test Case " << testCaseNumber << " - OK" << endl;
	} else {
		cout << "Test Case " << testCaseNumber << " - ERROR" << endl;
	}
	testCaseNumber++;
}

int main() {
	// # TEST CASE pawn moves
	{	
		// # SECTION with initial board setup
		{
			ChessBoard chessBoard;
	
			// # SECTION valid pawn move forward (WHITE)
			{	
				Pawn pawn(Player::WHITE);
				Move move('a', 2, 'a', 3);
				expect(true == pawn.isValidMove(move, chessBoard));
			}

			// # SECTION valid first pawn move
			{	
				Pawn pawn(Player::WHITE);
				Move move('a', 2, 'a', 4);
				expect(true == pawn.isValidMove(move, chessBoard));
			}

			// # SECTION valid pawn moves
			{	
				Pawn whitePawn(Player::WHITE);
				Move whiteMove('a', 2, 'a', 3);
				expect(true == whitePawn.isValidMove(whiteMove, chessBoard)); // white player
				

				Pawn blackPawn(Player::BLACK);
				Move blakMove('a', 7, 'a', 6);
				expect(true == blackPawn.isValidMove(blakMove, chessBoard)); // black player
			}

			// # SECTION invalid pawn move
			{	
				Pawn pawn(Player::WHITE);
				Move move('a', 2, 'b', 3);
				expect(false == pawn.isValidMove(move, chessBoard));
			}
		}

		// # SECTION invalid pawn move backwards
		{	
			Pawn pawn(Player::WHITE);

			ChessBoard chessBoard;
			chessBoard.set('a', 3, new Pawn(Player::WHITE));
			chessBoard.set('a', 2, nullptr);

			Move move3('a', 3, 'a', 2);
			expect(false == pawn.isValidMove(move3, chessBoard));
		}


		// # SECTION movement is blocked
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('c', 4, new Pawn(Player::WHITE));
			chessBoard.set('c', 5, new Pawn(Player::BLACK));

			const Piece & pawn = chessBoard.get('c', 5);

			Move move('c', 5, 'c', 4);
			expect(false == pawn.isValidMove(move, chessBoard));
		}


		// # SECTION double movement is blocked
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('c', 2, new Pawn(Player::WHITE));
			chessBoard.set('c', 3, new Pawn(Player::BLACK));

			const Piece & pawn = chessBoard.get('c', 2);

			Move move('c', 2, 'c', 4);
			expect(false == pawn.isValidMove(move, chessBoard));
		}


		// # SECTION black pawn captures white pawn on the left side
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('c', 4, new Pawn(Player::WHITE));
			chessBoard.set('d', 5, new Pawn(Player::BLACK));

			const Piece & pawn = chessBoard.get('d', 5);

			Move move('d', 5, 'c', 4);
			expect(true == pawn.isValidMove(move, chessBoard));
		}

		// # SECTION black pawn captures white pawn on the right side
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('c', 4, new Pawn(Player::WHITE));
			chessBoard.set('b', 5, new Pawn(Player::BLACK));

			const Piece & pawn = chessBoard.get('b', 5);

			Move move('b', 5, 'c', 4);
			expect(true == pawn.isValidMove(move, chessBoard));
		}


		// # SECTION white pawn tries to capture missing figure
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('e', 4, new Pawn(Player::WHITE));

			const Piece & pawn = chessBoard.get('e', 4);

			Move move('e', 4, 'd', 5);
			expect(false == pawn.isValidMove(move, chessBoard));
		}


		// # SECTION white pawn tries to capture white pawn figure
		{	
		
			ChessBoard chessBoard;
			chessBoard.set('e', 4, new Pawn(Player::WHITE));
			chessBoard.set('d', 5, new Pawn(Player::WHITE));

			const Piece & pawn = chessBoard.get('e', 4);

			Move move('e', 4, 'd', 5);
			expect(false == pawn.isValidMove(move, chessBoard));
		}
	}

	return  0;
}
