#include <iostream>
#include <cmath>
using namespace std;

const int N = 5; 

double sumPositive(double arr[]) {
    double sum = 0;
    for (int i = 0; i < N; ++i)
        if (arr[i] > 0)
            sum += arr[i];
    return sum;
}

void sortDescending(double arr[]) {
    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < N - i - 1; ++j)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int indexMaxAbs(double arr[]) {
    int idx = 0;
    for (int i = 1; i < N; ++i)
        if (fabs(arr[i]) > fabs(arr[idx]))
            idx = i;
    return idx;
}

int indexMinAbs(double arr[]) {
    int idx = 0;
    for (int i = 1; i < N; ++i)
        if (fabs(arr[i]) < fabs(arr[idx]))
            idx = i;
    return idx;
}

double BetweenMaxMin(double arr[]) {
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


// void FillArr(double(&arr)[N]){
//     for (int i=0; i< N; ++i){
//         arr[i]= rand()%10;        
//     }
// }


void FillArr(double(&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        double num = (rand() % 100) / 10.0;    // от 0 до 9.99
        int sign = (rand() % 2 == 0) ? 1 : -1;   // случайный знак
        arr[i] = num * sign;
    }
}


int main() {
    srand(time(0));
    double mass[N];
    FillArr(mass);    
    
    cout << "Исходный массив:\n";
    for (int i = 0; i < N; ++i)
    cout << mass[i] << " ";
    cout << endl;

    double sum = sumPositive(mass);
    double prod = BetweenMaxMin(mass);

    cout << "\nСумма положительных элементов: " << sum << endl;
    cout << "Произведение между минимальным и максимальным по модулю: " << prod << endl;

    sortDescending(mass);

    cout << "Массив после сортировки по убыванию:\n";
    for (int i = 0; i < N; ++i)
        cout << mass[i] << " ";
    cout << endl;

    return 0;
}