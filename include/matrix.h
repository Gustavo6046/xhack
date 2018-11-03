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
        double* get(unsigned short x, unsigned short y);
        double getn(unsigned short x, unsigned short y);
        void print();

        unsigned short rows;
        unsigned short cols;
        double* data;
};

#endif // MATRIX_H
