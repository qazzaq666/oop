#include <iostream>
#include <fstream>
#include <cstring>
#include "databaseControl.h"

using namespace std;

//TODO: подключение файла в мейне???
//изменения в реальном времени, 
//графич. интерфейс (text??)

int main() {
    // initDB();
    // clearDB();
    printDB();
    
    
    
    cout << "Кол-во: " << getSize()<<endl;
    // printRecord(4);
    // eraseRecord(6);
    
    //ADD
    // plane a = {'A', 120, 150};
    // plane b = {'B', 300, 350};
    // plane c = {'B', 500, 10};

    // push_back(a);
    // push_back(b);
    // push_back(c);
    
    // cout << "После push_back:" << endl;
    // printDB();

    // cout << "\ninsert(1, {D})" << endl;
    // plane d = {'D', 200, 250};
    // insertRecord(1, d);
    // printDB();

    // cout << "\nerase(2)" << endl;
    // eraseRecord(2);
    // printDB();

    // cout << "\nswap(0, 1)" << endl;
    // swapRecords(0, 1);
    // printDB();

    // cout << "\npop_back()" << endl;
    // pop_back();
    // printDB();

    return 0;
}