#pragma once

#include "Figure.hpp"

#include <utility>

class Scheme {
public:
    Scheme(int capacity); 
    ~Scheme();

    void push_back_figure(Figure* fg);
    void remove_figure(int id);

    void print_all_figures() const;
    void zoom_figure(int id, int factor);
    Figure* is_inside_figure(int x, int y) const;
    void move(int id, int new_x, int new_y);

	int getSize() const;
	int getCapacity() const;
	Figure* getFigure(int ind) const;

	int findPosById(int id) const;

private:
	int size_;
	int capacity_;
    Figure** figures_;
};
