/*Написать функцию, которая удаляет из строки 
символ с заданным номером*/
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void del_symbol(string& s, int& ch) {

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == (char)ch) {
            s.erase(s.begin() + i);
            return;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string s;
    cout << "Введите набор символов: ";
	getline(cin, s);

    cout << "\n48 - 57 цифры" << endl
         << "65 - 90 английские прописные буквы" << endl
         << "97 - 122 английские строчные буквы" << endl
         << "192 - 223 русские прописные буквы" << endl
         << "224 - 255 русские строчные буквы" << endl;

    int ch;
    cout << "\nВведите номер символа, который хотите удалить: ";
	cin >> ch;

    del_symbol(s, ch);

    cout << "\nСимвол " << (char)ch << " удален из строки " << "'" << s << "'" << endl;
    return 0;
}