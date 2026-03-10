#include <iostream>
using namespace std;
#include "./include/matrix.hpp"

void printMenu() {
    cout << "\nMatrix menu:\n";
    cout << "1) Input matrix A\n";
    cout << "2) Input matrix B\n";
    cout << "3) Show A, B\n";
    cout << "4) A + B\n";
    cout << "5) A - B\n";
    cout << "6) A * B\n";
    cout << "7) A / B (A * inv(B))\n";
    cout << "8) A * num\n";
    cout << "9) A / num\n";
    // cout << "10) transpose A\n";
    // cout << "11) inverse A\n";
    // cout << "12) determinant A\n";
    // cout << "13) norm A\n";
    // cout << "14) A^k (integer k)\n";
    // cout << "15) type checks A\n";
    // cout << "16) Compare A == B\n";
    cout << "0) Exit\n";
}


int main() {
    printMenu();

    Matrix A,B;
    int choice = -1;
    cout << "Input: ";
    cin >> choice;
    switch (choice)
    {
    case 0:
        
        break;
    
    case 1:
        cout << "inp A";
        break;
    case 2:
        cout << "inp B";
        break;
    case 3:
        cout << "SHOW";
        break;
    case 4:
        cout << "A+B";
        break;

    case 5:
        cout << "A-B";
        break;

    case 6:
        cout << "A*B";
        break;

    case 7:
        cout << "A/B";
        
        break;
    case 8:
        cout << "A*num";
        
    case 9:
        cout << "A/num";
        
    
    
    
    
    }
    cout<<endl;
    
    
    
    // cout<<"wrong number";
    // cout << "2!" << endl;
    return 0;
}



// Описать класс, реализующий тип данных «вещественная матрица» и работу
// с ними. Класс должен реализовывать следующие операции над матрицами:
// • сложение, вычитание, умножение, деление (+, -, *, /) (умножение и деление,
// как на другую матрицу, так и на число);


// • комбинированные операции присваивания (+=, -=, *=, /=);
// • операции сравнения на равенство/неравенство;
// • операции вычисления обратной и транспонированной матрицы, операцию
// возведения в степень;
// • методы вычисления детерминанта и нормы;
// • методы, реализующие проверку типа матрицы (квадратная, диагональная, ну­
// левая, единичная, симметрическая, верхняя треугольная, нижняя треугольная);
// • операции ввода/вывода в стандартные потоки.
// Написать программу, демонстрирующую работу с этим классом. Программа
// должна содержать меню, позволяющее осуществить проверку всех методов класса.
