#include "Test.hpp"
#include "Board.hpp"

class BoardTest : public Test {
private:
	//test getState()
	void testState1();
	void testState2();
	void testState3();
	void testState4();
	void testState5();

	//test move() and canMove()
	void testMove1();
	void testMove2();
	void testMove3();

	//test getNext() and changeNext()
	void testNext1();
	void testNext2();
	void testNext3();

	//test getPos()
	void testPos1();
	void testPos2();
	void testPos3();

public:
	void runAllTests() override;
};
