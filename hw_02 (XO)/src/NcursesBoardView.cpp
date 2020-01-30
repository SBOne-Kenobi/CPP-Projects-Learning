#include "NcursesBoardView.hpp"

NcursesBoardView::NcursesBoardView(Board& board) : board_(board), x_(0), y_(0) { }

void NcursesBoardView::init() {
	initscr();
	keypad(stdscr, true);
	noecho();
	raw();
	if (has_colors()) {
		start_color();
		init_pair(NONE_PAIR, COLOR_BLACK, COLOR_WHITE);
		init_pair(X_PAIR, COLOR_RED, COLOR_WHITE);
		init_pair(O_PAIR, COLOR_BLUE, COLOR_WHITE);
		init_pair(BAD_PAIR, COLOR_WHITE, COLOR_RED);
	}

	changeColor(NONE_PAIR);
	for (int i = 0; i < Board::fieldSize; ++i) {
		if (i)
			printw("\n");
		for (int j = 0; j < Board::fieldSize; ++j)
			printw("%c", (char)board_.getPos(i, j));
	}
	move(x_, y_);
	changeColor(board_.getNext());
	printTurn();
	refresh();
}

void NcursesBoardView::printTurn() {
	message((board_.getNext() == Board::X ? " X move.  " : " O move.  "));
}

void NcursesBoardView::changeColor(int s) {
	attron(COLOR_PAIR(s));
}

void NcursesBoardView::changeColor(Board::Sign s) {
	switch (s) {
	case Board::X:
		changeColor(X_PAIR);
		break;
	case Board::O:
		changeColor(O_PAIR);
		break;
	case Board::none:
		changeColor(NONE_PAIR);
		break;
	}
}

void NcursesBoardView::message(const char* m) {	
	move(Board::fieldSize, 0);
	clrtoeol();
	printw("%s", m);
	move(y_, x_);
}

void NcursesBoardView::action(int key) {
	switch (key) {
	case KEY_LEFT:
		x_ = (x_ - 1 + Board::fieldSize) % Board::fieldSize;
		break;
	case KEY_RIGHT:
		x_ = (x_ + 1) % Board::fieldSize;
		break;
	case KEY_UP:
		y_ = (y_ - 1 + Board::fieldSize) % Board::fieldSize;
		break;
	case KEY_DOWN:
		y_ = (y_ + 1) % Board::fieldSize;
		break;
	case ' ':
		if (board_.canMove(x_, y_, board_.getNext())) {
			board_.move(x_, y_, board_.getNext());
			printw("%c", (char)board_.getPos(x_, y_));
			board_.changeNext();
			changeColor(board_.getNext());
		} else {
			halfdelay(5);
			changeColor(BAD_PAIR);
			message("Bad move! ");
			getch();
			raw();
			changeColor(board_.getNext());
		}
		break;
	default:
		break;
	}
	move(y_, x_);
}

void NcursesBoardView::endGame() {
	curs_set(false);
	board_.changeNext();
	changeColor(board_.getNext());
	switch (board_.getState()) {
	case Board::WIN_X:
		message(" X wins!  ");
		break;
	case Board::WIN_O:
		message(" O wins!  ");
		break;
	case Board::DRAW:
		changeColor(NONE_PAIR);
		message("  Draw.   ");
		break;
	default:
		endwin();
		return;
	}
	while (getch() != 'x');
	endwin();
}

void NcursesBoardView::doGameCycle() {
	init();
	int key;
	while (board_.getState() == Board::PROCESS && (key = getch()) != 'x') {
		action(key);
		printTurn();
		refresh();
	}
	endGame();
}
