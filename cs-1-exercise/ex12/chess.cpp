#include<iostream>
using namespace std;

class ChessBoard;

// ////////////////////////////////////////////////////////

enum Player {
	WHITE, BLACK
};

// ////////////////////////////////////////////////////////

// Indexing of columns is a-h
// Indexing of rows is 1-8
class Position {
public:
	Position(char column, int row) {
		this->setColumn(column);
		this->setRow(row);
	}

	char getColumn() const {
		return this->column + 'a' - 1;
	}

	int getColumnIndex() const {
		return this->column - 1;
	}

	int getRow() const {
		return this->row;
	}

	int getRowIndex() const {
		return this->row - 1;
	}

private:
	void setColumn(char column) {
		this->column = assertValidColumnAndRowRange(column - 'a' + 1);
	}

	void setRow(int row) {
		this->row = assertValidColumnAndRowRange(row);
	}

	int assertValidColumnAndRowRange(int x) {
		assert(1 <= x && x <= 8);
		return x;
	}

private:
	// indexing is 1-8 for rows and columns
	int column;
	int row;
};

// ////////////////////////////////////////////////////////


class Move {
public:
	Move(Position from, Position to) :
		from(from), 
		to(to) {
	}

	Move(char fromColumn, int fromRow, char toColumn, int toRow) :
			from(Position(fromColumn, fromRow)),
			to(Position(toColumn, toRow)){
	}

	Position getFromPosition() const {
		return this->from;
	}

	Position getToPosition() const {
		return this->to;
	}
private:
	Position from;
	Position to;
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
	virtual char getInitials() const = 0;
	virtual Piece * clone() const = 0;
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

	ChessBoard(const ChessBoard & other) {
		cout << "ChessBoard(const ChessBoard & other) " << endl;
		copy(other);
	}

	ChessBoard & operator=(const ChessBoard & other) {
		cout << "operator=(const ChessBoard & other) " << endl;
		if (this != &other) {
			destroy();
			copy(other);
		}
		return *this;
	}

	void move(Move move) {
		Position from = move.getFromPosition();
		Position to = move.getToPosition();

		if (this->pieces[to.getColumnIndex()][to.getRowIndex()] != nullptr) {
			delete this->pieces[to.getColumnIndex()][to.getRowIndex()];
		}
		this->pieces[to.getColumnIndex()][to.getRowIndex()] = this->pieces[from.getColumnIndex()][from.getRowIndex()];
		this->pieces[from.getColumnIndex()][from.getRowIndex()] = nullptr;
	}

	bool isEmpty(Position position) const {
		return nullptr == this->pieces[position.getColumnIndex()][position.getRowIndex()];
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
		assert(this->pieces[onPosition.getColumnIndex()][onPosition.getRowIndex()] != nullptr);
		return *this->pieces[onPosition.getColumnIndex()][onPosition.getRowIndex()];
	}

	~ChessBoard() {
		destroy();
	}

private:
	void copy(const ChessBoard & other) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (other.pieces[i][j] != nullptr) {
					this->pieces[i][j] = other.pieces[i][j]->clone();	
				} else {
					this->pieces[i][j] = nullptr;
				}
			}
		}
	}

	void destroy() {
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

#include "pieces.cpp"

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
	ChessGame() {
		this->initialBoardArrangement();
	}

	bool makeMove(Move move) {
		if (!rules.isMoveValid(move, this->board)) {
			return false;
		}

		// if (isCurrentPlayerCheckAfterTheMove()) {
		// 	return false;
		// }

		board.move(move);
		return true;
	}

	ChessBoard getBoard() const {
		return board;
	}


	bool hasGameEnded() {
		return false;
	}

	// getGameStatus() -> NOT_STARTED, ONGOING, WHITE_WINS, BLACK_WINS, DRAW

private:
	void initialBoardArrangement() {
		board.set('a', 1, new Rook(Player::WHITE));
		board.set('b', 1, new Knight(Player::WHITE));
		board.set('c', 1, new Bishop(Player::WHITE));
		board.set('d', 1, new Queen(Player::WHITE));
		board.set('e', 1, new King(Player::WHITE));
		board.set('f', 1, new Bishop(Player::WHITE));
		board.set('g', 1, new Knight(Player::WHITE));
		board.set('h', 1, new Rook(Player::WHITE));

		board.set('a', 2, new Pawn(Player::WHITE));
		board.set('b', 2, new Pawn(Player::WHITE));
		board.set('c', 2, new Pawn(Player::WHITE));
		board.set('d', 2, new Pawn(Player::WHITE));
		board.set('e', 2, new Pawn(Player::WHITE));
		board.set('f', 2, new Pawn(Player::WHITE));
		board.set('g', 2, new Pawn(Player::WHITE));
		board.set('h', 2, new Pawn(Player::WHITE));

		board.set('a', 8, new Rook(Player::BLACK));
		board.set('b', 8, new Knight(Player::BLACK));
		board.set('c', 8, new Bishop(Player::BLACK));
		board.set('d', 8, new Queen(Player::BLACK));
		board.set('e', 8, new King(Player::BLACK));
		board.set('f', 8, new Bishop(Player::BLACK));
		board.set('g', 8, new Knight(Player::BLACK));
		board.set('h', 8, new Rook(Player::BLACK));

		board.set('a', 7, new Pawn(Player::BLACK));
		board.set('b', 7, new Pawn(Player::BLACK));
		board.set('c', 7, new Pawn(Player::BLACK));
		board.set('d', 7, new Pawn(Player::BLACK));
		board.set('e', 7, new Pawn(Player::BLACK));
		board.set('f', 7, new Pawn(Player::BLACK));
		board.set('g', 7, new Pawn(Player::BLACK));
		board.set('h', 7, new Pawn(Player::BLACK));
	}

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

class ChessGameConsoleUI {
public:
	void startGame() {
		ChessGame game;
		
		visualizeBoard(game.getBoard());
		while (!game.hasGameEnded()) {
			char fromColumn;
			int fromRow;
			char toColumn;
			int toRow;
			cout << "from: ";
			cin >> fromColumn >> fromRow;
			cout << "to: ";
			cin >> toColumn >> toRow;

			if (game.makeMove(Move(Position(fromColumn, fromRow), Position(toColumn, toRow)))) {
				visualizeBoard(game.getBoard());
			} else {
				cout << "Wrong move!!!" << endl;
			}
		}
	}
private:
	void visualizeBoard(ChessBoard board) const {
		cout << " ---------------------------------" << endl;
		for (int i = 'a'; i <= 'h'; i++) {
			cout << " | ";
			for (int j = 1; j <= 8; j++) {
				if (!board.isEmpty(Position(i, j))) {
					cout << board.get(Position(i, j)).getInitials() << " | ";
				} else {
					cout << " " << " | ";
				}
			}
			cout << endl;
			cout << " ---------------------------------" << endl;
		}
	}
};

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

			{
				Pawn pawn(Player::WHITE);
				Move move(Position('a', 2), Position('a', 3));
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

	ChessGameConsoleUI ui;
	ui.startGame();


	return  0;
}
