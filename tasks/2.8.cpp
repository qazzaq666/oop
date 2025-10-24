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

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
