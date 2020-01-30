#include "Figure.hpp"

Figure::Figure(int id, int x, int y) : id(id), x(x), y(y) { }

Figure::~Figure() { }

void Figure::move(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

int Figure::getId() const {
	return id;
}

int Figure::getCenterX() const {
	return x;
}

int Figure::getCenterY() const {
	return y;
}
