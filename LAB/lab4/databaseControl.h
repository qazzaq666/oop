#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct plane
{
    char type;     // марка (один символ)
    int hours;     // налет
    int nextTech;  // след. ТО
};

// char* DB_FILE = "planes.db";
const char* DB_FILE = "planes.db";

const int MAX_RECORDS = 100;  


void initDB() {
    fstream f(DB_FILE, ios::out | ios::binary);
    plane empty = {'\0', 0, 0};
    for (int i = 0; i < MAX_RECORDS; i++)
        f.write((char*)&empty, sizeof(plane));
}

// Получение количества записей
int getSize() {
    fstream f(DB_FILE, ios::in | ios::binary);
    plane p;

    int count = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        f.seekg(i * sizeof(plane));
        f.read((char*)&p, sizeof(plane));
        if (p.type != '\0') count++;
        else break;
    }
    return count;
}

// Чтение записи
plane readRecord(int index) {
    fstream f(DB_FILE, ios::in | ios::binary);
    f.seekg(index * sizeof(plane));
    plane p;
    f.read((char*)&p, sizeof(plane));
    return p;
}

// Запись записи
void writeRecord(int index, const plane& p) {
    fstream f(DB_FILE, ios::in | ios::out | ios::binary);
    f.seekp(index * sizeof(plane));
    f.write((char*)&p, sizeof(plane));
}

// swap(a, b)
void swapRecords(int i, int j) {
    plane a = readRecord(i);
    plane b = readRecord(j);
    writeRecord(i, b);
    writeRecord(j, a);
}

// clear() — полностью очищает БД
void clearDB() {
    initDB();
}

// erase(index) — удалить элемент и сдвинуть все влево
void eraseRecord(int index) {
    int size = getSize();
    for (int i = index; i < size - 1; i++) {
        plane next = readRecord(i + 1);
        writeRecord(i, next);
    }

    // последняя запись = пустая
    plane empty = {'\0', 0, 0};
    writeRecord(size - 1, empty);
}

void printRecord(int x){
    plane p = readRecord(x);
    cout << x << ") "
     << p.type << " | "
     << p.hours << " | "
     << p.nextTech << endl;
    }

// push_back()
void push_back(const plane& p) {
    int size = getSize();
    if (size >= MAX_RECORDS) return;
    writeRecord(size, p);
}

// pop_back()
void pop_back() {
    int size = getSize();
    if (size == 0) return;
    plane empty = {'\0', 0, 0};
    printRecord(size-1);
    writeRecord(size - 1, empty);

}

// insert(index, element)
void insertRecord(int index, const plane& p) {
    int size = getSize();
    if (size >= MAX_RECORDS) return;

    
    for (int i = size; i > index; i--) {
        plane prev = readRecord(i - 1);
        writeRecord(i, prev);
    }

    writeRecord(index, p);
}



// вывод всех данных
void printDB() {
    int size = getSize();
    for (int i = 0; i < size; i++) {
        plane p = readRecord(i);
        cout << i << ") "
             << p.type << " | "
             << p.hours << " | "
             << p.nextTech << endl;
    }
}