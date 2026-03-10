#include <iostream>
#include <limits>
#include "./include/matrix.hpp"
using namespace std;

int main(){

    int r,c;

    cout<<"Rows cols: ";
    cin>>r>>c;

    Matrix A(r,c);

    cout<<"Matrix A:\n";
    A.input();

    int choice;

    do{

        cout<<"\n1 Print\n";
        cout<<"2 Transpose\n";
        cout<<"3 Determinant\n";
        cout<<"4 Norm\n";
        cout<<"5 Power\n";
        cout<<"6 Check types\n";
        cout<<"0 Exit\n";

        cin>>choice;

        if(choice==1)
            A.print();

        if(choice==2){
            Matrix B = A.transpose();
            B.print();
        }

        if(choice==3)
            cout<<A.determinant()<<endl;

        if(choice==4)
            cout<<A.norm()<<endl;

        if(choice==5){
            int n;
            cin>>n;
            Matrix B = A.power(n);
            B.print();
        }

        if(choice==6){
            cout<<"Square: "<<A.isSquare()<<endl;
            cout<<"Zero: "<<A.isZero()<<endl;
            cout<<"Identity: "<<A.isIdentity()<<endl;
            cout<<"Diagonal: "<<A.isDiagonal()<<endl;
            cout<<"Symmetric: "<<A.isSymmetric()<<endl;
            cout<<"Upper triangular: "<<A.isUpperTriangular()<<endl;
            cout<<"Lower triangular: "<<A.isLowerTriangular()<<endl;
        }

    }while(choice!=0);

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
