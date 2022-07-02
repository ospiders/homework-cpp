/*Написать программу, которая заменяет все 
символы точки «.» в строке, введенной пользователем, 
на символы восклицательного знака «!».*/

#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

void replace_symbol(string& s) {
    replace(s.begin(), s.end(), '.', '!');
    cout << "Результат: " << s << endl;

    return;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string s;
    cout << "Введите набор символов: " << endl;
    getline(cin, s);

    replace_symbol(s);

    return 0;
}