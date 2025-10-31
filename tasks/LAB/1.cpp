
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
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = -1;
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Первый локальный максимум: " << arr[index] << ", индекс: " << index << endl;
    else
        cout << "Локальных максимумов нет" << endl;

    delete[] arr;
    return 0;
}
