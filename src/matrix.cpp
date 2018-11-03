#include <assert.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
using std::setw;

#include "matrix.h"


Matrix::Matrix(unsigned short rows, unsigned short cols, double* data) {
    this->rows = rows;
    this->cols = cols;

    this->data = new double[rows * cols];

    if (data != 0)
        std::copy(data, data + this->rows * this->cols, this->data);
}

double* Matrix::get(unsigned short col, unsigned short row) {
    if (col == 0 && row == 0) return this->data;
    return this->data + (row * this->cols + col);
}

double Matrix::getn(unsigned short col, unsigned short row) {
    if (col == 0 && row == 0) return *this->data;
    return this->data[row * this->cols + col];
}

void Matrix::setn(unsigned short col, unsigned short row, double n) {
    if (col == 0 && row == 0) this->data[0] = n;
    this->data[row * this->cols + col] = n;
}

Matrix Matrix::T() {
    Matrix res(this->cols, this->rows);

    for (unsigned short r = 0; r < this->rows; r++)
        for (unsigned short c = 0; c < this->cols; c++)
            *(res.get(r, c)) = this->getn(c, r);

    return res;
}

void Matrix::print() {
    for (unsigned short r = 0; r < this->rows; r++) {
        std::cout << "| ";

        for (unsigned short c = 0; c < this->cols; c++)
            std::cout << setw(13) << this->getn(c, r) << "; ";

        std::cout << "|" << std::endl;
    }

    // debug purposes
    printf("   DATA ARRAY ADDRESS = %p\n", this->data);

    std::cout << std::endl;
}

Matrix Matrix::operator* (Matrix B) {
    assert(this->cols == B.rows);
    Matrix res(this->rows, B.cols, 0);

    for (unsigned short r1 = 0; r1 < this->rows; r1++)
        for (unsigned short r2 = 0; r2 < B.cols; r2++) {
            double prod = 0;

            for (unsigned short i = 0; i < this->cols; i++)
                prod += this->getn(i, r1) * B.getn(r2, i);

            res.setn(r2, r1, prod);
        }

    return res;
}

Matrix::~Matrix() {
    delete[] this->data;
}
