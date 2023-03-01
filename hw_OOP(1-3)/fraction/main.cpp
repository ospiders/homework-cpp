#include <iostream>
#include <windows.h>
#include "Fraction.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, c, d;

    cout << "Введите числитель первой дроби: ";
    cin >> a;
    do {
        cout << "Введите знаменатель первой дроби: ";
        cin >> b;
        if (b == 0) cout << "ДЕЛИТЬ НА НОЛЬ НЕЛЬЗЯ!" << endl;
    } while (b == 0);

    cout << "Введите числитель второй дроби: ";
    cin >> c;
    do {
        cout << "Введите знаменатель второй дроби: ";
        cin >> d;
        if (d == 0) cout << "ДЕЛИТЬ НА НОЛЬ НЕЛЬЗЯ!" << endl;
    } while (d == 0);

    
    Fraction first(a, b);
    cout << "Первая дробь: " << first.getNominator() << "/" << first.getDenominator() << endl;
    Fraction second(c, d);
    cout << "Вторая дробь " << second.getNominator() << "/" << second.getDenominator() << endl;


    Fraction answer;

    answer = first.Addit(second).FractionReduction();
    cout << "Сложение "; answer.print_answer();

    answer = first.Subtract(second).FractionReduction();
    cout << "Вычетание "; answer.print_answer();

    answer = first.Multiply(second).FractionReduction();
    cout << "Умножение "; answer.print_answer();

    answer = first.Divide(second).FractionReduction();
    cout << "Деление "; answer.print_answer();

	return 0;
}
