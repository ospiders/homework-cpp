/* Написать функцию, которая вставляет в строку 
в указанную позицию заданный символ.*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void add_symbol_in_pos(string& s, string& c, int& h) {

    s.insert((h - 1), c);
    cout << "Результат: " << s << endl;

    return;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите набор символов: " << endl;
    string s;
    getline(cin, s);

    string c;
    cout << "Введите cимвол, который хотите вставить: " << endl;
    cin >> c;

    int h;
    do {
        cout << "Введите номер позиции, в которую хотите вставить символ: " << endl;
        cin >> h;
    } while (h < 1 || h > (s.length() + 1));

    add_symbol_in_pos(s, c, h);

    return 0;
}