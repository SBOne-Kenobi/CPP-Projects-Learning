#include "StdioBoardView.hpp"

StdioBoardView::StdioBoardView(Board& board, bool silent) : board_(board), silent_(silent) { };

using std::cout;
using std::cin;

bool StdioBoardView::check(int x, int y) const {
	if (board_.canMove(x, y, board_.getNext()))
		return true;
	cout << "Bad move!\n";
	return false;
}

void StdioBoardView::print() const {
	cout << "\n";
	for (int i = 0; i < Board::fieldSize; ++i) {
		for (int j = 0; j < Board::fieldSize; ++j)
			cout << (char)board_.getPos(i, j);
		cout <<  "\n";
	}
}

void StdioBoardView::print(Board::State state) const {
	switch (state) {
	case Board::WIN_X:
		cout << "X wins!";
		break;
	case Board::WIN_O:
		cout << "O wins!";
		break;
	case Board::DRAW:
		cout << "Draw.";
		break;
	default:
		cout << "Something gone wrong...";
		break;
	}
	cout << "\n";
}

void StdioBoardView::doGameCycle() {
	while (board_.getState() == Board::PROCESS) {
		if (!silent_)
			print();
		int x, y;
		do {
			cout << (char)board_.getNext() << " move: ";
			cin >> x >> y;
			if (x == -1 && y == -1)
				return;
		} while (!check(x, y));
		board_.move(x, y, board_.getNext());
		board_.changeNext();
	}
	print();
	print(board_.getState());
}
