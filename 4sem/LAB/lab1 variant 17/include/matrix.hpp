#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int r, int c);
    Matrix(const std::vector<std::vector<double>>& d);

    void input();
    void print() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator/(double value) const;
    Matrix operator*(double value) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator*=(double value);
    Matrix& operator/=(double value);

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    Matrix transpose() const;
    Matrix inverse() const;
    Matrix power(int n) const;

    double determinant() const;
    double norm() const;

    bool isSquare() const;
    bool isZero() const;
    bool isIdentity() const;
    bool isDiagonal() const;
    bool isSymmetric() const;
    bool isUpperTriangular() const;
    bool isLowerTriangular() const;
};

#endif