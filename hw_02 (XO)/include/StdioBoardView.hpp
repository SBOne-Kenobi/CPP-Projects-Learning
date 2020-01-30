#pragma once

#include <iostream>

#include "Board.hpp"

class StdioBoardView {
public:
	StdioBoardView(Board& board, bool silent = false);
	
	void doGameCycle();

private:
	Board& board_;
	bool silent_;
	
	bool check(int x, int y) const;
	void print() const;
	void print(Board::State state) const;
};
