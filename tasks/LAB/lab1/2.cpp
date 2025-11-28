#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

const int ARR_SIZE = 10;

void fillArr(int(&arr)[ARR_SIZE]);
void printArr(int(&arr)[ARR_SIZE]);
int maxAbs(int(&arr)[ARR_SIZE]);
int sumBetweenFirstTwoPositive(int(&arr)[ARR_SIZE]);
void sortNullsLast(int(&arr)[ARR_SIZE]);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int mass[ARR_SIZE];
    
    fillArr(mass);
    printArr(mass);
    
    int maxAbsVal = maxAbs(mass);
    cout << "Максимальный по модулю элемент: " << maxAbsVal << endl;

    int sum = sumBetweenFirstTwoPositive(mass);
    cout << "Сумма между первым и вторым положительными элементами: " << sum << endl;

    sortNullsLast(mass);
    cout << "Массив после перемещения нулей в конец: ";
    printArr(mass);
    
    return 0;
}

void fillArr(int(&arr)[ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; ++i) {
        int sign = (rand() % 2 == 0) ? 1 : -1;
        arr[i] = sign * (rand() % 10);
    }
}

void printArr(int(&arr)[ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int maxAbs(int(&arr)[ARR_SIZE]) {
    int maxVal = arr[0];
    for (int i = 1; i < ARR_SIZE; ++i)
        if (abs(arr[i]) > abs(maxVal))
            maxVal = arr[i];
    return maxVal;
}

int sumBetweenFirstTwoPositive(int(&arr)[ARR_SIZE]) {
    int first = -1, second = -1;
    for (int i = 0; i < ARR_SIZE; ++i)
        if (arr[i] > 0) {
            if (first == -1)
                first = i;
            else {
                second = i;
                break;
            }
        }

    if (first == -1 or second == -1) {
        cout << "Недостаточно положительных элементов для подсчёта суммы." << endl;
        return 0;
    }

    int sum = 0;
    for (int i = first + 1; i < second; ++i)
        sum += arr[i];
    return sum;
}

void sortNullsLast(int(&arr)[ARR_SIZE]) {
    int temp[ARR_SIZE];
    int index = 0;

    for (int i = 0; i < ARR_SIZE; ++i)
        if (arr[i] != 0)
            temp[index++] = arr[i];

    while (index < ARR_SIZE)
        temp[index++] = 0;

    for (int i = 0; i < ARR_SIZE; ++i)
        arr[i] = temp[i];
}
