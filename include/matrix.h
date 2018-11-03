#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    public:
        Matrix();
        Matrix(unsigned short rows, unsigned short cols, double* data = 0);

        virtual ~Matrix();

        Matrix operator* (Matrix B);
        Matrix T();
        double* get(unsigned short col, unsigned short row);
        double getn(unsigned short col, unsigned short row);
        void setn(unsigned short col, unsigned short row, double n);
        void print();

        unsigned short rows;
        unsigned short cols;
        double* data;
};

#endif // MATRIX_H
