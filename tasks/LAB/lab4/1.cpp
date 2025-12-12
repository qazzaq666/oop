
#include <bits/stdc++.h>
using namespace std;

struct Aircraft {
    string type;      // марка / тип самолёта
    double hours;     // налёт в часах
    double next;      // следующее (по налёту в часах)

    string to_line() const {
        // формат: type|hours|next
        ostringstream oss;
        oss << type << "|" << hours << "|" << next;
        return oss.str();
    }

    static bool from_line(const string &line, Aircraft &out) {
        // Разделитель '|', допускаем пробелы вокруг
        auto trim = [](string s) {
            size_t a = s.find_first_not_of(" \t\r\n");
            size_t b = s.find_last_not_of(" \t\r\n");
            if (a == string::npos) return string();
            return s.substr(a, b - a + 1);
        };

        vector<string> parts;
        string cur;
        for (char c : line) {
            if (c == '|') {
                parts.push_back(trim(cur));
                cur.clear();
            } else cur.push_back(c);
        }
        parts.push_back(trim(cur));
        if (parts.size() != 3) return false;
        try {
            out.type = parts[0];
            out.hours = stod(parts[1]);
            out.next = stod(parts[2]);
        } catch (...) {
            return false;
        }
        return true;
    }
};

struct DB {
    vector<Aircraft> rows;

    void push_back(const Aircraft &a) { rows.push_back(a); }
    bool pop_back() {
        if (rows.empty()) return false;
        rows.pop_back();
        return true;
    }
    bool insert_at(size_t pos, const Aircraft &a) {
        if (pos > rows.size()) return false;
        rows.insert(rows.begin() + pos, a);
        return true;
    }
    bool erase_at(size_t pos) {
        if (pos >= rows.size()) return false;
        rows.erase(rows.begin() + pos);
        return true;
    }
    bool swap_idx(size_t i, size_t j) {
        if (i >= rows.size() || j >= rows.size()) return false;
        std::swap(rows[i], rows[j]);
        return true;
    }
    void clear() { rows.clear(); }

    bool save_to_file(const string &fname) const {
        ofstream ofs(fname);
        if (!ofs) return false;
        for (const auto &r : rows) ofs << r.to_line() << "\n";
        return true;
    }

    bool load_from_file(const string &fname) {
        ifstream ifs(fname);
        if (!ifs) return false;
        string line;
        vector<Aircraft> tmp;
        size_t ln = 0;
        while (getline(ifs, line)) {
            ++ln;
            if (line.find_first_not_of(" \t\r\n") == string::npos) continue; // пропускаем пустые строки
            Aircraft a;
            if (!Aircraft::from_line(line, a)) {
                cerr << "Ошибка парсинга на строке " << ln << ": \"" << line << "\"\n";
                return false;
            }
            tmp.push_back(a);
        }
        rows.swap(tmp);
        return true;
    }

    void print_table() const {
        cout << "Индекс | Тип самолёта | Налёт (ч) | Следующее (ч)\n";
        cout << "-------------------------------------------------\n";
        for (size_t i = 0; i < rows.size(); ++i) {
            cout << setw(6) << i << " | "
                 << setw(12) << rows[i].type << " | "
                 << setw(9) << rows[i].hours << " | "
                 << setw(12) << rows[i].next << "\n";
        }
        if (rows.empty()) cout << "(База пуста)\n";
    }
};

// Вспомогательные функции для ввода
string input_line_nonempty(const string &prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) return string();
        // trim
        size_t a = s.find_first_not_of(" \t\r\n");
        if (a == string::npos) {
            cout << "Пустая строка. Повтори.\n";
            continue;
        }
        size_t b = s.find_last_not_of(" \t\r\n");
        return s.substr(a, b - a + 1);
    }
}


double input_double(const string &prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) return 0.0;
        // trim
        size_t a = s.find_first_not_of(" \t\r\n");
        if (a == string::npos) { cout << "Нужно число. Повтори.\n"; continue; }
        size_t b = s.find_last_not_of(" \t\r\n");
        s = s.substr(a, b - a + 1);
        try {
            double v = stod(s);
            return v;
        } catch (...) {
            cout << "Неверный формат числа. Попробуй снова.\n";
        }
    }
}

size_t input_index(const string &prompt, size_t max_exclusive) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) return 0;
        // trim
        size_t a = s.find_first_not_of(" \t\r\n");
        if (a == string::npos) { cout << "Нужен индекс. Повтори.\n"; continue; }
        size_t b = s.find_last_not_of(" \t\r\n");
        s = s.substr(a, b - a + 1);
        try {
            long long idx = stoll(s);
            if (idx < 0 || (size_t)idx >= max_exclusive) {
                cout << "Индекс вне диапазона [0," << (max_exclusive ? max_exclusive - 1 : 0) << "]. Повтори.\n";
                continue;
            }
            return (size_t)idx;
        } catch (...) {
            cout << "Неверный индекс. Повтори.\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DB db;
    const string default_file = "airdb.txt";

    cout << "Простая СУБД для авиапарка (консольная)\n";
    cout << "Формат файла: Тип|Налет_в_часах|Следующее_по_налету\n";
    cout << "Подсказка: пример строки -> Boeing-737|12405.5|12600\n\n";

    // Попробуем загрузить автоматом, если есть файл
    if (db.load_from_file(default_file)) {
        cout << "Загружено из " << default_file << " (" << db.rows.size() << " записей).\n";
    }

    while (true) {
        cout << "\nМеню:\n";
        cout << " 1. Показать все записи\n";
        cout << " 2. Добавить в конец (push_back)\n";
        cout << " 3. Удалить последний (pop_back)\n";
        cout << " 4. Вставить по индексу (insert)\n";
        cout << " 5. Удалить по индексу (erase)\n";
        cout << " 6. Поменять местами два индекса (swap)\n";
        cout << " 7. Очистить базу (clear)\n";
        cout << " 8. Сохранить в файл\n";
        cout << " 9. Загрузить из файла (перезапишет текущие данные)\n";
        cout << "10. Экспорт в файл (указать имя)\n";
        cout << "11. Импорт из файла (указать имя)\n";
        cout << " 0. Выход\n";
        cout << "Выбери действие: ";

        string cmd;
        if (!getline(cin, cmd)) break;
        if (cmd.empty()) continue;

        if (cmd == "1") {
            db.print_table();
        } else if (cmd == "2") {
            Aircraft a;
            a.type = input_line_nonempty("Тип самолёта (марка): ");
            a.hours = input_double("Налёт в часах: ");
            a.next = input_double("Следующее (по налёту в часах): ");
            db.push_back(a);
            cout << "Добавлено.\n";
        } else if (cmd == "3") {
            if (db.pop_back()) cout << "Последняя запись удалена.\n";
            else cout << "База пуста.\n";
        } else if (cmd == "4") {
            size_t pos = 0;
            if (!db.rows.empty()) {
                cout << "Текущие записи: 0.." << db.rows.size() << "\n";
                // разрешаем вставку на позицию == size (вставка в конец)
                while (true) {
                    string s;
                    cout << "Введите индекс для вставки (0.." << db.rows.size() << "): ";
                    if (!getline(cin, s)) break;
                    try {
                        long long p = stoll(s);
                        if (p < 0 || (size_t)p > db.rows.size()) { cout << "Вне диапазона, повтори.\n"; continue; }

pos = (size_t)p;
                        break;
                    } catch (...) { cout << "Неверно. Повтори.\n"; }
                }
            }
            Aircraft a;
            a.type = input_line_nonempty("Тип самолёта (марка): ");
            a.hours = input_double("Налёт в часах: ");
            a.next = input_double("Следующее (по налёту в часах): ");
            if (db.insert_at(pos, a)) cout << "Вставлено на позицию " << pos << ".\n";
            else cout << "Не удалось вставить.\n";
        } else if (cmd == "5") {
            if (db.rows.empty()) { cout << "База пуста.\n"; continue; }
            size_t idx = input_index("Индекс для удаления: ", db.rows.size());
            if (db.erase_at(idx)) cout << "Запись " << idx << " удалена.\n";
            else cout << "Не удалось удалить.\n";
        } else if (cmd == "6") {
            if (db.rows.size() < 2) { cout << "Недостаточно записей для обмена.\n"; continue; }
            size_t i = input_index("Первый индекс: ", db.rows.size());
            size_t j = input_index("Второй индекс: ", db.rows.size());
            if (db.swap_idx(i, j)) cout << "Поменяно " << i << " <-> " << j << ".\n";
            else cout << "Не удалось выполнить swap.\n";
        } else if (cmd == "7") {
            cout << "Подтверди очистку базы (yes): ";
            string y;
            if (!getline(cin, y)) break;
            if (y == "yes") { db.clear(); cout << "База очищена.\n"; } else cout << "Отмена.\n";
        } else if (cmd == "8") {
            if (db.save_to_file(default_file)) cout << "Сохранено в " << default_file << ".\n";
            else cout << "Ошибка при записи в " << default_file << ".\n";
        } else if (cmd == "9") {
            cout << "Подтверждаешь загрузку из " << default_file << " (перезапишет текущее) (yes): ";
            string y;
            if (!getline(cin, y)) break;
            if (y == "yes") {
                if (db.load_from_file(default_file)) cout << "Загружено из " << default_file << ".\n";
                else cout << "Ошибка при загрузке из " << default_file << ".\n";
            } else cout << "Отмена.\n";
        } else if (cmd == "10") {
            string fname = input_line_nonempty("Имя файла для экспорта: ");
            if (db.save_to_file(fname)) cout << "Экспортировано в " << fname << ".\n";
            else cout << "Ошибка при записи в " << fname << ".\n";
        } else if (cmd == "11") {
            string fname = input_line_nonempty("Имя файла для импорта: ");
            cout << "Подтверждаешь загрузку из " << fname << " (перезапишет текущее) (yes): ";
            string y;
            if (!getline(cin, y)) break;
            if (y == "yes") {
                if (db.load_from_file(fname)) cout << "Загружено из " << fname << ".\n";
                else cout << "Ошибка при загрузке из " << fname << ".\n";
            } else cout << "Отмена.\n";
        } else if (cmd == "0") {
            cout << "Выход. Сохраняю в " << default_file << "...\n";
            db.save_to_file(default_file);
            break;
        } else {
            cout << "Неизвестная команда. Введи цифру из меню.\n";
        }
    }

    return 0;
}