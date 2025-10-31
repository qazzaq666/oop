#include <iostream>
#include <cmath>
using namespace std;

const int N = 10; // <-- тут задаёшь размер массива

// --- 1. Сумма положительных элементов ---
double sumPositive(double arr[]) {
    double sum = 0;
    for (int i = 0; i < N; ++i)
        if (arr[i] > 0)
            sum += arr[i];
    return sum;
}

// --- 2. Сортировка по убыванию (пузырёк) ---
void sortDescending(double arr[]) {
    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < N - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// --- 3. Индекс максимального по модулю ---
int indexMaxAbs(double arr[]) {
    int idx = 0;
    for (int i = 1; i < N; ++i)
        if (fabs(arr[i]) > fabs(arr[idx]))
            idx = i;
    return idx;
}

// --- 4. Индекс минимального по модулю ---
int indexMinAbs(double arr[]) {
    int idx = 0;
    for (int i = 1; i < N; ++i)
        if (fabs(arr[i]) < fabs(arr[idx]))
            idx = i;
    return idx;
}

// --- 5. Произведение элементов между минимальным и максимальным по модулю ---
double productBetweenMinMax(double arr[]) {
    int minIdx = indexMinAbs(arr);
    int maxIdx = indexMaxAbs(arr);

    if (minIdx > maxIdx)
        swap(minIdx, maxIdx);

    if (maxIdx - minIdx <= 1)
        return 0;

    double prod = 1;
    for (int i = minIdx + 1; i < maxIdx; ++i)
        prod *= arr[i];

    return prod;
}

int main() {
    double arr[N] = { 1.5, -3.2, 0.7, 4.1, -2.5, 0.0, 6.9, -1.2, 3.3, -0.8 }; 
    // можешь заменить значения как хочешь

    cout << "Исходный массив:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    double sum = sumPositive(arr);
    double prod = productBetweenMinMax(arr);

    cout << "\nСумма положительных элементов: " << sum << endl;
    cout << "Произведение между минимальным и максимальным по модулю: " << prod << endl;

    sortDescending(arr);

    cout << "Массив после сортировки по убыванию:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
