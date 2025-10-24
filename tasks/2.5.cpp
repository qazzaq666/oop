// 0 if < x, else unchanged

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    int *arr = new int[N];

    cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Введите число: ";
    cin >> x;

    for (int i = 0; i < N; i++)
        if (arr[i] < x) arr[i] = 0;

    cout << "Результат: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
