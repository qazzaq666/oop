#include <iostream>
#include "databaseControl.h"
using namespace std;

void menu() {
    cout << "\n===== AIRCRAFT DB =====\n";
    cout << "1. push_back\n";
    cout << "2. pop_back\n";
    cout << "3. insert\n";
    cout << "4. erase\n";
    cout << "5. swap\n";
    cout << "6. clear\n";
    cout << "7. print\n";
    cout << "8. save to file\n";
    cout << "9. load from file\n";
    cout << "0. exit\n";
    cout << "Choose: ";
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        menu();
        cin >> choice;

        if (choice == 1) {
            Aircraft rec;
            cout << "Enter type:";
            cin >> rec.type ;
            cout << "\nEnter hours:";
            cin >> rec.flightHours; 
            cout << "\nEnter nextService:";
            cin >> rec.nextService;
            push_back(head, rec);
        }

        else if (choice == 2) {
            pop_back(head);
        }

        else if (choice == 3) {
            Aircraft rec;
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter type:";
            cin >> rec.type ;
            cout << "\nEnter hours:";
            cin >> rec.flightHours; 
            cout << "\nEnter nextService:";
            cin >> rec.nextService;
            insertRecord(head, rec, pos);
        }

        else if (choice == 4) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            eraseRecord(head, pos);
        }

        else if (choice == 5) {
            int i, j;
            cout << "Enter two indices: ";
            cin >> i >> j;
            swapRecords(head, i, j);
        }

        else if (choice == 6) {
            clearDB(head);
        }

        else if (choice == 7) {
            printDB(head);
        }

        else if (choice == 8) {
            saveToFile(head);
        }

        else if (choice == 9) {
            loadFromFile(head);
        }

    } while (choice != 0);

    clearDB(head);
    return 0;
}