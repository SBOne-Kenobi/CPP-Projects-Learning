#include "Board.hpp"

Board::Board() : 
	state_(PROCESS),
	counter_(0), next_(O)
{
	for (int i = 0; i < fieldSize; ++i)
		for (int j = 0; j < fieldSize; ++j)
			field_[i][j] = none;
}

Board::Sign Board::getNext() const {
	return next_;
}

void Board::changeNext() {
	next_ = next_ == O ? X : O;
}

Board::Sign Board::getPos(int x, int y) const {
	return field_[x][y];
}

bool Board::validPos(int x) const {
	return x >= 0 && x < fieldSize;
}

bool Board::canMove(int x, int y, Sign sign) const {
	return validPos(x) && validPos(y) &&
			(field_[x][y] == none) && (state_ == PROCESS);
}

int Board::count(int x, int y, int dx, int dy) const {
	int cnt = 0;
	Sign cur = field_[x][y];
	while (cnt < winNum && validPos(x) && validPos(y) && field_[x][y] == cur)
		x += dx, y += dy, ++cnt;
	return cnt;
}

bool Board::checkX(int x, int y) const {
	int cnt = count(x, y, 1, 0) + count(x, y, -1, 0) - 1;
	return cnt >= winNum;
}

bool Board::checkY(int x, int y) const {
	int cnt = count(x, y, 0, 1) + count(x, y, 0, -1) - 1;
	return cnt >= winNum;
}

bool Board::checkD1(int x, int y) const {
	int cnt = count(x, y, 1, 1) + count(x, y, -1, -1) - 1;
	return cnt >= winNum;
}

bool Board::checkD2(int x, int y) const {
	int cnt = count(x, y, 1, -1) + count(x, y, -1, 1) - 1;
	return cnt >= winNum;
}

void Board::move(int x, int y, Sign sign) {
	field_[x][y] = sign;
	++counter_;

	if (checkX(x, y) || checkY(x, y) || checkD1(x, y) || checkD2(x, y))
		state_ = sign == X ? WIN_X : WIN_O;
	else if (counter_ == fieldSize * fieldSize)
		state_ = DRAW;
}

Board::State Board::getState() const {
	return state_;
}
