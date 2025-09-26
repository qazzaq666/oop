#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter operation (+ - * /): ";
    cin >> op;

    switch (op) {
        case '+': cout << "Result: " << a + b << endl; break;
        case '-': cout << "Result: " << a - b << endl; break;
        case '*': cout << "Result: " << a * b << endl; break;
        case '/':
            if (b != 0)
                cout << "Result: " << a / b << endl;
            else
                cout << "Error: division by zero!" << endl;
            break;
        default: cout << "Unknown operation!" << endl;
    }

    return 0;
}
