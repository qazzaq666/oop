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

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;

    cout << "После обмена: ";
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}