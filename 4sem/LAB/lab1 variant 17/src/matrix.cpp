#include "matrix.hpp"
#include <cmath>
using namespace std;
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data.resize(r, vector<double>(c, 0));
}

Matrix::Matrix(const vector<vector<double>>& d) {
    data = d;
    rows = d.size();
    cols = d[0].size();
}

void Matrix::input() {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin >> data[i][j];
}

void Matrix::print() const {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix res(rows, cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            res.data[i][j] = data[i][j] + other.data[i][j];
    return res;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix res(rows, cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            res.data[i][j] = data[i][j] - other.data[i][j];
    return res;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix res(rows, other.cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<other.cols;j++)
            for(int k=0;k<cols;k++)
                res.data[i][j] += data[i][k] * other.data[k][j];
    return res;
}

Matrix Matrix::operator*(double value) const {
    Matrix res(rows, cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            res.data[i][j] = data[i][j] * value;
    return res;
}

Matrix Matrix::operator/(double value) const {
    Matrix res(rows, cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            res.data[i][j] = data[i][j] / value;
    return res;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            data[i][j] += other.data[i][j];
    return *this;
}

Matrix& Matrix::operator*=(double value) {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            data[i][j] *= value;
    return *this;
}

Matrix& Matrix::operator/=(double value) {
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            data[i][j] /= value;
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    return data == other.data;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

Matrix Matrix::transpose() const {
    Matrix res(cols, rows);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            res.data[j][i] = data[i][j];
    return res;
}

double Matrix::determinant() const {
    if(rows != cols) return 0;

    if(rows == 1) return data[0][0];
    if(rows == 2)
        return data[0][0]*data[1][1] - data[0][1]*data[1][0];

    double det = 0;
    for(int p=0;p<cols;p++){
        Matrix sub(rows-1, cols-1);

        for(int i=1;i<rows;i++){
            int colIndex=0;
            for(int j=0;j<cols;j++){
                if(j==p) continue;
                sub.data[i-1][colIndex] = data[i][j];
                colIndex++;
            }
        }

        det += data[0][p] * pow(-1,p) * sub.determinant();
    }
    return det;
}

Matrix Matrix::inverse() const {

    int n = rows;
    Matrix A = *this;
    Matrix I(n,n);

    for(int i=0;i<n;i++)
        I.data[i][i] = 1;

    for(int i=0;i<n;i++){
        double diag = A.data[i][i];

        for(int j=0;j<n;j++){
            A.data[i][j] /= diag;
            I.data[i][j] /= diag;
        }

        for(int k=0;k<n;k++){
            if(k==i) continue;

            double factor = A.data[k][i];

            for(int j=0;j<n;j++){
                A.data[k][j] -= factor * A.data[i][j];
                I.data[k][j] -= factor * I.data[i][j];
            }
        }
    }

    return I;
}

Matrix Matrix::power(int n) const {

    Matrix res = *this;

    for(int i=1;i<n;i++)
        res = res * (*this);

    return res;
}

double Matrix::norm() const {
    double sum = 0;
    for(auto& r : data)
        for(double v : r)
            sum += v*v;
    return sqrt(sum);
}

bool Matrix::isSquare() const { return rows==cols; }

bool Matrix::isZero() const {
    for(auto& r:data)
        for(double v:r)
            if(v!=0) return false;
    return true;
}

bool Matrix::isIdentity() const {
    if(!isSquare()) return false;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++){
            if(i==j && data[i][j]!=1) return false;
            if(i!=j && data[i][j]!=0) return false;
        }
    return true;
}

bool Matrix::isDiagonal() const {
    if(!isSquare()) return false;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(i!=j && data[i][j]!=0) return false;
    return true;
}

bool Matrix::isSymmetric() const {
    if(!isSquare()) return false;
    return *this == transpose();
}

bool Matrix::isUpperTriangular() const {
    if(!isSquare()) return false;
    for(int i=1;i<rows;i++)
        for(int j=0;j<i;j++)
            if(data[i][j]!=0) return false;
    return true;
}

bool Matrix::isLowerTriangular() const {
    if(!isSquare()) return false;
    for(int i=0;i<rows;i++)
        for(int j=i+1;j<cols;j++)
            if(data[i][j]!=0) return false;
    return true;
}