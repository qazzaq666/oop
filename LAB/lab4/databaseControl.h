#ifndef DATABASE_CONTROL_H
#define DATABASE_CONTROL_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const char DB_FILE[] = "aircraft_db.txt";

// ================= СТРУКТУРЫ =================

struct Aircraft {
    char type[50];        // Тип самолета (марка)
    double flightHours;   // Налет в часах
    double nextService;   // Следующее обслуживание (по налету)
};

struct Node {
    Aircraft data;
    Node* next;
};

// ================= ВСПОМОГАТЕЛЬНЫЕ =================

int getSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void printDB(Node* head) {
    int i = 0;
    if (!head) {
        cout << "DB is empty\n";
        return;
    }

    while (head) {
        cout << i++ << ") "
             << head->data.type << " | "
             << head->data.flightHours << " | "
             << head->data.nextService << endl;
        head = head->next;
    }
}

// ================= ОСНОВНЫЕ ОПЕРАЦИИ =================

// push_back
void push_back(Node*& head, const Aircraft& rec) {
    Node* newNode = new Node;
    newNode->data = rec;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    Node* cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = newNode;
}

// pop_back
void pop_back(Node*& head) {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* cur = head;
    while (cur->next->next)
        cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

// insert
void insertRecord(Node*& head, const Aircraft& rec, int pos) {
    if (pos <= 0 || !head) {
        Node* newNode = new Node;
        newNode->data = rec;
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur->next; i++)
        cur = cur->next;

    Node* newNode = new Node;
    newNode->data = rec;
    newNode->next = cur->next;
    cur->next = newNode;
}

// erase
void eraseRecord(Node*& head, int pos) {
    if (!head) return;

    if (pos == 0) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur->next; i++)
        cur = cur->next;

    if (!cur->next) return;

    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

// clear
void clearDB(Node*& head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// swap
void swapRecords(Node* head, int i, int j) {
    if (i == j) return;

    Node* a = head;
    Node* b = head;

    for (int k = 0; k < i && a; k++) a = a->next;
    for (int k = 0; k < j && b; k++) b = b->next;

    if (!a || !b) return;

    Aircraft temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// ================= ФАЙЛ =================

// запись
void saveToFile(Node* head) {
    ofstream fout(DB_FILE);
    if (!fout) {
        cout << "File open error\n";
        return;
    }

    while (head) {
        fout << head->data.type << " "
             << head->data.flightHours << " "
             << head->data.nextService << "\n";
        head = head->next;
    }
}

// чтение
void loadFromFile(Node*& head) {
    ifstream fin(DB_FILE);
    if (!fin) {
        cout << "File not found\n";
        return;
    }

    clearDB(head);

    Aircraft rec;
    while (fin >> rec.type >> rec.flightHours >> rec.nextService) {
        push_back(head, rec);
    }
}

#endif