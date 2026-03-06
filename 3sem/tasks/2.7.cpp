// reverse array 2

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

    for (int i = 0; i < N / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }

    cout << "Перевернутый массив: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}