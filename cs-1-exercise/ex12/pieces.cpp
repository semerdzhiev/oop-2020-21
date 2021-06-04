const int PAWS_STARTING_ROWS_WHITE = 2;
const int PAWS_STARTING_ROWS_BLACK = 7;

class Pawn : public Piece {
public:
	Pawn(Player player) : Piece(player) {}

	virtual char getInitials() const {
		return 'P';
	}

	virtual Piece * clone() const {
		return new Pawn(*this);
	}

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

	virtual char getInitials() const {
		return 'N';
	}

	virtual Piece * clone() const {
		return new Knight(*this);
	}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { // TODO IMPLEMENT 
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

class Bishop : public Piece {
public:
	Bishop(Player player) : Piece(player) {}

	virtual char getInitials() const {
		return 'B';
	}

	virtual Piece * clone() const {
		return new Bishop(*this);
	}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { // TODO IMPLEMENT
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

class Rook : public Piece {
public:
	Rook(Player player) : Piece(player) {}

	virtual char getInitials() const {
		return 'R';
	}

	virtual Piece * clone() const {
		return new Rook(*this);
	}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { // TODO IMPLEMENT
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

class Queen : public Piece {
public:
	Queen(Player player) : Piece(player) {}

	virtual char getInitials() const {
		return 'Q';
	}

	virtual Piece * clone() const {
		return new Queen(*this);
	}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { // TODO IMPLEMENT
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

class King : public Piece {
public:
	King(Player player) : Piece(player) {}

	virtual char getInitials() const {
		return 'K';
	}

	virtual Piece * clone() const {
		return new King(*this);
	}

	virtual bool isValidMove(const Move & move, const ChessBoard & board) const { // TODO IMPLEMENT
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