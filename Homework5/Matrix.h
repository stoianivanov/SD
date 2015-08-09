#pragma once
#include <iostream>
#include "Simulation.h"
class Matrix
{
public:
    Matrix(size_t M=0, size_t N=0);
    Matrix(size_t M, size_t N, double** initMatrix);
    Matrix(const Matrix& );
    Matrix& operator= (const Matrix&);
    ~Matrix();
    void setElem(size_t x, size_t y, double elem);
    double getElem(size_t x, size_t y)const;
    size_t getM() const;
    size_t getN() const;
    void print() const;
    void init(Simulation& sim);
private:
    void copy(const Matrix&);
    void destroy();
    void allocate(size_t M, size_t N);
private:
    size_t M;
    size_t N;
    double** matrix;
};
