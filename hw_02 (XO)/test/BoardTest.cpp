#include "BoardTest.hpp"

void BoardTest::testState1() {
	Board b;
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(0, 0, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(1, 0, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(2, 0, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(5, 0, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 0, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(3, 0, Board::X);
	DO_CHECK(b.getState() == Board::WIN_X);
}

void BoardTest::testState2() {
	Board b;
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 2, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 3, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 7, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 6, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 5, Board::X);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 4, Board::X);
	DO_CHECK(b.getState() == Board::WIN_X);
}

void BoardTest::testState3() {
	Board b;
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 3, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(5, 4, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(9, 8, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(8, 7, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(7, 6, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(6, 5, Board::O);
	DO_CHECK(b.getState() == Board::WIN_O);
}

void BoardTest::testState4() {
	Board b;
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(4, 8, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(5, 7, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(9, 3, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(8, 4, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(7, 5, Board::O);
	DO_CHECK(b.getState() == Board::PROCESS);
	b.move(6, 6, Board::O);
	DO_CHECK(b.getState() == Board::WIN_O);
}

void BoardTest::testState5() {
	Board b;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < Board::fieldSize; ++j) {
			DO_CHECK(b.getState() == Board::PROCESS);
			b.move(i, j, b.getNext());
			b.changeNext();
		}
	for (int i = 4; i < 8; ++i)
		for (int j = Board::fieldSize - 1; j >= 0; --j) {
			DO_CHECK(b.getState() == Board::PROCESS);
			b.move(i, j, b.getNext());
			b.changeNext();
		}
	for (int i = 8; i < 10; ++i)
		for (int j = 0; j < Board::fieldSize; ++j) {
			DO_CHECK(b.getState() == Board::PROCESS);
			b.move(i, j, b.getNext());
			b.changeNext();
		}
	DO_CHECK(b.getState() == Board::DRAW);
}

void BoardTest::testMove1() {
	Board b;
	DO_CHECK(b.canMove(4, 4, Board::X) == true);
	b.move(4, 4, Board::X);
	DO_CHECK(b.canMove(4, 4, Board::X) == false);
	DO_CHECK(b.canMove(9, 0, Board::O) == true);
	b.move(9, 0, Board::O);
	DO_CHECK(b.canMove(9, 0, Board::O) == false);
	DO_CHECK(b.canMove(9, 0, Board::X) == false);
	DO_CHECK(b.canMove(4, 4, Board::O) == false);
}

void BoardTest::testMove2() {
	Board b;
	int cord[] = { 10, 10, -1, -2, 12, 4, 13, -13, 100, 9 };
	b.move(0, 0, Board::X);
	b.move(1, 0, Board::O);
	for (int i = 0; i < 10; i += 2)
		DO_CHECK(b.canMove(cord[i], cord[i + 1], Board::X) == false);
}

void BoardTest::testMove3() {
	Board b;
	b.move(0, 0, Board::X);
	b.move(0, 1, Board::X);
	b.move(0, 2, Board::X);
	b.move(0, 3, Board::X);
	b.move(0, 4, Board::X);
	int cord[] = { 0, 0, 1, 2, 2, 3, 0, 4, 4, 0, 0, 1, 1, 0 };
	for (int i = 0; i < 14; i += 2)
		DO_CHECK(b.canMove(cord[i], cord[i + 1], Board::X) == false);
}

void BoardTest::testNext1() {
	Board b;
	DO_CHECK(b.getNext() == Board::O);
	for (int i = 0; i < 10; ++i) {
		b.changeNext();
		if (i % 2 == 0)
			DO_CHECK(b.getNext() == Board::X);
		else
			DO_CHECK(b.getNext() == Board::O);
	}
}

void BoardTest::testNext2() {
	Board b;
	b.changeNext();
	DO_CHECK(b.getNext() == Board::X);
	for (int i = 0; i < 13; ++i) {
		b.changeNext();
		if (i % 2 == 1)
			DO_CHECK(b.getNext() == Board::X);
		else
			DO_CHECK(b.getNext() == Board::O);
	}
}

void BoardTest::testNext3() {
	Board b;
	for (int i = 0; i < 7; ++i) {
		DO_CHECK(b.canMove(0, 0, b.getNext()) == true);
		if (i % 2 == 1)
			DO_CHECK(b.getNext() == Board::X);
		else
			DO_CHECK(b.getNext() == Board::O);
		b.changeNext();
	}
}

void BoardTest::testPos1() {
	Board b;
	int cord[] = { 0, 0, 1, 2, 2, 3, 0, 4, 4, 0, 0, 1, 1, 0 };
	for (int i = 0; i < 14; i += 2) {
		DO_CHECK(b.getPos(cord[i], cord[i + 1]) == Board::none);
		b.move(cord[i], cord[i + 1], Board::X);
		DO_CHECK(b.getPos(cord[i], cord[i + 1]) == Board::X);
	}
}


void BoardTest::testPos2() {
	Board b;
	for (int i = 0; i < Board::fieldSize; ++i)
		b.move(i, i, Board::X);
	for (int i = 0; i < Board::fieldSize; ++i)
		for (int j = 0; j < Board::fieldSize; ++j)
			if (i == j)
				DO_CHECK(b.getPos(i, j) == Board::X);
			else
				DO_CHECK(b.getPos(i, j) == Board::none);
}


void BoardTest::testPos3() {
	Board b;
	for (int i = 0; i < Board::fieldSize; ++i)
		for (int j = 0; j < Board::fieldSize; ++j) {
			DO_CHECK(b.getPos(i, j) == Board::none);
			b.move(i, j, ((i + j) % 2 == 0) ? Board::X : Board::O);
		}
	for (int i = 0; i < Board::fieldSize; ++i)
		for (int j = 0; j < Board::fieldSize; ++j)
			DO_CHECK(b.getPos(i, j) == ((i + j) % 2 == 0 ? Board::X : Board::O));
}

void BoardTest::runAllTests() {
	testMove1();
	testMove2();
	testMove3();

	testNext1();
	testNext2();
	testNext3();

	testState1();
	testState2();
	testState3();
	testState4();
	testState5();

	testPos1();
	testPos2();
	testPos3();
}

