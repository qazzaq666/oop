#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Введите коэффициенты a, b и c: ";
    cin >> a >> b >> c;

    if(a == 0) {
        if(b != 0) {
            double x = -c / b;
            cout << "Это линейное уравнение. Корень: " << x << endl;
        } else {
            if(c == 0) cout << "Уравнение имеет бесконечно много решений." << endl;
            else cout << "Решений нет." << endl;
        }
        return 0;
    }

    double discriminant = b*b - 4*a*c;
    cout << "Дискриминант D = " << discriminant << endl;

    if(discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2*a);
        double x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Два различных корня: x1 = " << x1 << ", x2 = " << x2 << endl;

        if(fabs(a*x1*x1 + b*x1 + c) < 1e-6 && fabs(a*x2*x2 + b*x2 + c) < 1e-6)
            cout << "Корни проверены: верно." << endl;
    }
    else if(discriminant == 0) {
        double x = -b / (2*a);
        cout << "Один корень: x = " << x << endl;

        if(fabs(a*x*x + b*x + c) < 1e-6)
            cout << "Корень проверен: верно." << endl;
    }
    else {
        double realPart = -b / (2*a);
        double imagPart = sqrt(-discriminant) / (2*a);
        cout << "Комплексные корни: x1 = " << realPart << "+" << imagPart << "i, x2 = " 
             << realPart << "-" << imagPart << "i" << endl;
        cout << "Проверка невозможна для комплексных корней стандартным способом." << endl;
    }

    return 0;
}
// 1, -2, -3