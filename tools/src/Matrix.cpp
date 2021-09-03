#include "Matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(int row, int column) {
    this->row = row;
    this->column = column;

    this->element = new bool*[row];
    for (int i = 0; i < row; ++i) {
        this->element[i] = new bool[column];
    }
}

Matrix::Matrix(const Matrix &matrix) {
    this->row = matrix.getRow();
    this->column = matrix.getColumn();

    this->element = new bool*[row];
    for (int i = 0; i < row; ++i) {
        this->element[i] = new bool[column];
        for (int j = 0; j < column; ++j) {
            this->element[i][j] = matrix.getElement(i, j);
        }
    }
}

Matrix::~Matrix() {
    if(this->element != NULL) {
        for (int i = 0; i < this->row; ++i) {
            if(this->element[i] != NULL) {
                delete [] this->element[i];
            }
        }
        delete [] this->element;
        this->element = NULL;
    }
}

int Matrix::getRow() const {
    return this->row;
}

int Matrix::getColumn() const {
    return this->column;
}

void Matrix::setElement(int r, int c, bool e) {
    this->element[r][c] = e;
}

bool Matrix::getElement(int r, int c) const {
    return this->element[r][c];
}