#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    int maxVal = a; // предполагаем, что a самое большое

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;

    cout << "The biggest: ";

    bool first = true;
    if (a == maxVal) {
        cout << "A";
        first = false;
    }
    if (b == maxVal) {
        if (!first) cout << " and ";
        cout << "B";
        first = false;
    }
    if (c == maxVal) {
        if (!first) cout << " and ";
        cout << "C";
    }

    cout << endl;

    return 0;
}
