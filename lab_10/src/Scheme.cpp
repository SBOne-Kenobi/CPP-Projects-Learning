#include "Scheme.hpp"

Scheme::Scheme(int capacity) : size_(0), capacity_(capacity), figures_(new Figure*[capacity]) { }

Scheme::~Scheme() {
	for (int i = 0; i < size_; ++i)
		delete figures_[i];
	delete[] figures_;
}

void Scheme::push_back_figure(Figure* fg) {
	figures_[size_++] = fg;
}

void Scheme::remove_figure(int id) {
	int cur = findPosById(id);
	if (cur == -1)
		return;
	for (int i = cur; i < size_ - 1; ++i)
		std::swap(figures_[i], figures_[i + 1]);
	delete figures_[--size_];
}

void Scheme::print_all_figures() const {
	for (int i = 0; i < size_; ++i)
		figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor) {
	int cur = findPosById(id);
	if (cur == -1)
		return;
	figures_[cur]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) const {
	for (int i = 0; i < size_; ++i)
		if (figures_[i]->is_inside(x, y))
			return figures_[i];
	return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
	int cur = findPosById(id);
	if (cur == -1)
		return;
	figures_[cur]->move(new_x, new_y);
}

int Scheme::getSize() const {
	return size_;
}

int Scheme::getCapacity() const {
	return capacity_;
}

Figure* Scheme::getFigure(int ind) const {
	return figures_[ind];
}

int Scheme::findPosById(int id) const {
	for (int i = 0; i < size_; ++i)
		if (figures_[i]->getId() == id)
			return i;
	return -1;
}

