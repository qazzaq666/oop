#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Уравнение имеет бесконечно много решений." << endl;
            } else {
                cout << "Уравнение не имеет решений." << endl;
            }
        } else {
            double x = -c / b;
            cout << "Уравнение линейное, корень: x = " << x << endl;
        }
    } else {
        double discriminant = b*b - 4*a*c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2*a);
            double x2 = (-b - sqrt(discriminant)) / (2*a);
            cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (discriminant == 0) {
            double x = -b / (2*a);
            cout << "Один корень: x = " << x << endl;
        } else {
            cout << "Корней нет (дискриминант < 0)." << endl;
        }
    }

    return 0;
}
