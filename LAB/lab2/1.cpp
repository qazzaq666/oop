#include <iostream>
#include <cstring>
using namespace std;

void allocArr(int*& p, int n) {
    p = new int[n];
}

void reverseArr(int* arr, int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
}

int count_words(const char* src) {
    int c = 0;
    bool in = false;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != ' ' && src[i] != '\t' && src[i] != '\n') {
            if (!in) {
                c++;
                in = true;
            }
        } else {
            in = false;
        }
    }
    return c;
}
int main() {
    int arr[5] = {1488,78,3,4,5};
    cout << "---адреса---" << endl << arr << endl;
    cout << &arr[0] << endl;
    cout << "---разыменов и 1й---" << endl << *arr << endl;
    cout << arr[0] << endl;

    int* p = arr;
    for (int i = 0; i < 5; i++) {
        *(p + i) += 10;
    }
    cout << "===+10==="<<endl;
    for (int i = 0; i<5;i++){
        cout << arr[i] << " ";
    }
    cout << endl << "-dynamic-" << endl;
    int* dyn = nullptr;
    allocArr(dyn, 5);
    for (int i = 0; i < 5; i++) dyn[i] = i + 1;

    int i = 0;
    int* q = dyn;
    while (i < 5) {
        cout << *(q + i) << " ";
        i++;
    }
    cout << endl << "-reversed-" << endl;

    reverseArr(dyn, 5);
    for (int k = 0; k < 5; k++) cout << dyn[k] << " ";
    cout << endl;

    const char* s = "Я вашу маму знаю";
    cout<< "===words===" <<endl << count_words(s) << endl;
    cout << s << endl;

    delete[] dyn;
    return 0;
}



