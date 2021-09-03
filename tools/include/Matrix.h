#ifndef SCHEDULING_MATRIX_H
#define SCHEDULING_MATRIX_H

#include <iostream>

using namespace std;

/**
 * Generation Matrix Object
 */
class Matrix {
private:
    int row;
    int column;
    bool** element = NULL;

public:
    Matrix();
    Matrix(int row, int column);
    Matrix(const Matrix &matrix);
    ~Matrix();

    int getRow() const;
    int getColumn() const;
    void setElement(int r, int c, bool e);
    bool getElement(int r, int c) const;
};

#endif
