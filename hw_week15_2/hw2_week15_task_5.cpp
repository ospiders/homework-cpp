/*Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается 
в строке.*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void del_symbol(string& s, char& c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            count++;
        }
    }
    cout << "Указанный вами символ встретился " << count << " раз" << endl;

    return;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите набор символов: " << endl;
    string s;
    getline(cin, s);

    cout << "Введите символ, который хотите найти: " << endl;
    char c;
    cin >> c;

    del_symbol(s, c);
    return 0;
}