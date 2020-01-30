#pragma once

#include <ncurses.h>

#include "Board.hpp"

class NcursesBoardView {
public:

	enum COLOR_PAIRS { NONE_PAIR = 1, X_PAIR = 2, O_PAIR = 3, BAD_PAIR = 4 };

	NcursesBoardView(Board& board);
	
	void doGameCycle();

private:
	Board& board_;
	int x_, y_;

	void init();
	void action(int key);
	void endGame();
	void message(const char* m);
	void printTurn();
	void changeColor(int color);
	void changeColor(Board::Sign s);
};
