#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix {
    private:
    std::vector<std::vector<double>> matData;


    public:
    void inputMatrix();

    Matrix sumMatrix(const Matrix& other);// сложение матриц
    Matrix raznMatrix(const Matrix& other); //разность матриц
    Matrix umnMatrix(const Matrix& other);//произведение матриц
    Matrix delMatrix(const Matrix& other);//частное матриц A/B

    Matrix umnNum(double val); //умножение на число 
    Matrix delNum(double val);//деление на число

    void sumEqual();// +=
    void raznEqual();// -+
    void umnEqual();// *=
    void delEqual();// /=

    void equal();// Проверка равенства A = B

    Matrix obratn();// вычисление обратной матрицы
    Matrix transpon();//транспонирование матрицы
    Matrix determin();//вычисление детерминанта

    void norm();// вычисление нормали
    Matrix stepen(const Matrix& other);// возведение матрицы в степень
    void typeOf();// проверка типа матрицы (квадратная, диагональная, ну­левая, единичная, симметрическая, верхняя треугольная, нижняя треугольная)
    
    void standart();//
    

    
    


};

#endif
