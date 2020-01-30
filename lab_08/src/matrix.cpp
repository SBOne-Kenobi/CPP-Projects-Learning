#include "matrix.h"
#include <algorithm>

using std::size_t;

Matrix::Matrix(size_t r, size_t c) {
	_data = new int*[r];
	for (size_t i = 0; i < r; ++i) {
		_data[i] = new int[c];
		for (size_t j = 0; j < c; ++j)
			_data[i][j] = 0;
	}
	_rows = r;
	_cols = c;
}

size_t Matrix::get_rows() const {
	return _rows;
}

size_t Matrix::get_cols() const {
	return _cols;
}

Matrix::Matrix(Matrix const & m) {
	size_t r = m.get_rows();
	size_t c = m.get_cols();
	_data = new int*[r];
	for (size_t i = 0; i < r; ++i) {
		_data[i] = new int[c];
		for (size_t j = 0; j < c; ++j)
			_data[i][j] = m.get(i, j);
	}
	_rows = r;
	_cols = c;
}

Matrix::~Matrix() {
	for (size_t i = 0; i < _rows; ++i)
		delete[] _data[i];
	delete[] _data;
}

void Matrix::swap(Matrix& m) {
	using std::swap;
	swap(this->_rows, m._rows);
	swap(this->_cols, m._cols);
	swap(this->_data, m._data);
}

Matrix& Matrix::operator=(Matrix const & m) {
	if (&m != this)
		Matrix(m).swap(*this);
	return *this;
}

void Matrix::set(size_t i, size_t j, int val) {
	_data[i][j] = val;
}

int Matrix::get(size_t i, size_t j) const {
	return _data[i][j];
}

void Matrix::print(FILE* f) const {
	for (size_t i = 0; i < _rows; ++i) {
		for (size_t j = 0; j < _cols; ++j) {
			if (j)
				fprintf(f, " ");
			fprintf(f, "%d", _data[i][j]);
		}
		fprintf(f, "\n");
	}
}

bool Matrix::operator==(const Matrix& m) const {
	if (_rows != m.get_rows() || _cols != m.get_cols())
		return false;
	for (size_t i = 0; i < _rows; ++i)
		for (size_t j = 0; j < _cols; ++j)
			if (_data[i][j] != m.get(i, j))
				return false;
	return true;
}

bool Matrix::operator!=(const Matrix& m) const{
	return !(*this == m);
}

Matrix& Matrix::operator+=(const Matrix& m) {
	for (size_t i = 0; i < _rows; ++i)
		for (size_t j = 0; j < _cols; ++j)
			_data[i][j] += m.get(i, j);
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
	for (size_t i = 0; i < _rows; ++i)
		for (size_t j = 0; j < _cols; ++j)
			_data[i][j] -= m.get(i, j);
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
	((*this) * m).swap(*this);
	return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {
	return Matrix(*this) += m;
}

Matrix Matrix::operator-(const Matrix& m) const {
	return Matrix(*this) -= m;
}

Matrix Matrix::operator*(const Matrix& m) const {
	Matrix res(_rows, m.get_cols());
	for (size_t i = 0; i < res.get_rows(); ++i)
		for (size_t j = 0; j < res.get_cols(); ++j)
			for (size_t k = 0; k < _cols; ++k)
				res.set(i, j, res.get(i, j) + _data[i][k] * m.get(k, j));
	return res;
}

