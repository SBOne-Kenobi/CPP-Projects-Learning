#include "Rectangle.hpp"

Rectangle::Rectangle(int id, int x, int y, int width, int height) : 
	Figure(id, x, y), 
	width(width), height(height)
{ }

void Rectangle::print() const {
	printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
}

bool Rectangle::is_inside(int x, int y) const {
	return 2 * (x - this->x) <= width && 2 * (x - this->x) >= -width &&
		2 * (y - this->y) <= height && 2 * (y - this->y) >= -height;
}

void Rectangle::zoom(int factor) {
	width *= factor;
	height *= factor;
}

int Rectangle::getWidth() const {
	return width;
}

int Rectangle::getHeight() const {
	return height;
}
