#pragma once

class Board {
public:
	enum Sign : char { X = 'X', O = 'O', none = '.' };
	enum State { WIN_X, WIN_O, DRAW, PROCESS };
	enum Properties { fieldSize = 10, winNum = 5 };

	bool canMove(int x, int y, Sign sign) const;
	void move(int x, int y, Sign sign);
	void changeNext();

	State getState() const;
	Sign getPos(int x, int y) const;
	Sign getNext() const;

	Board();

private:
	Sign field_[fieldSize][fieldSize];
	State state_;
	int counter_;
	Sign next_;

	int count(int x, int y, int dx, int dy) const;
	bool checkX(int x, int y) const;
	bool checkY(int x, int y) const;
	bool checkD1(int x, int y) const;
	bool checkD2(int x, int y) const;
	bool validPos(int x) const;
};
