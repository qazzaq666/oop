#include <iostream>
#include "databaseControl.h"

using namespace std;

void menu()
{
    cout << "\n===== DATABASE MENU =====\n";
    cout << "1. Print DB\n";
    cout << "2. Push back\n";
    cout << "3. Insert record\n";
    cout << "4. Erase record\n";
    cout << "5. Swap records\n";
    cout << "6. Pop back\n";
    cout << "7. Clear DB\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

plane inputPlane()
{
    plane p;
    cout << "Type (char): ";
    cin >> p.type;
    cout << "Hours: ";
    cin >> p.hours;
    cout << "Next tech: ";
    cin >> p.nextTech;
    return p;
}

int main()
{
    // initDB(); // если файл не существует

    int choice;

    while (true)
    {
        menu();
        cin >> choice;

        if (choice == 0) break;

        switch (choice)
        {
        case 1:
            printDB();
            break;

        case 2:
        {
            plane p = inputPlane();
            push_back(p);
            break;
        }

        case 3:
        {
            int index;
            cout << "Index1: ";
            cin >> index ;
            plane p = inputPlane();
            insertRecord(index, p);
            break;
        }
        case 4:
        {
            int index;
            cout << "Index2: ";
            cin >> index;
            eraseRecord(index);
            break;
        }

        case 5:
        {
            int a, b;
            cout << "First index: ";
            cin >> a;
            cout << "Second index: ";
            cin >> b;
            swapRecords(a, b);
            break;
        }

        case 6:
            pop_back();
            break;

        case 7:
            clearDB();
            break;

        default:
            cout << "Wrong choice\n";
        }
    }

    return 0;
}

