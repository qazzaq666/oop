// num of 0s

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

    cout << "Массив: ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 11 - 5; // числа от -5 до 5, чтобы были нули
        cout << arr[i] << " ";
    }
    cout << endl;

    int count = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] == 0) count++;

    cout << "Количество нулей: " << count << endl;

    delete[] arr;
    return 0;
}
