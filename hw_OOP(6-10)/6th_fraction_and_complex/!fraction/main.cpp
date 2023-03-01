/*Создайте класс дробь (или используйте уже ранее созданный вами). 
используя перегрузку операторов реализуйте для него арифметические 
операции для работы с дробями (операции +, -, *, /).*/
#include "Fraction.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 };

    read(a, b);
    read(c, d);
    
    Fraction first(a, b);
    cout << "Первая дробь: " << first.getNominator() << "/" << first.getDenominator() << endl;
    Fraction second(c, d);
    cout << "Вторая дробь " << second.getNominator() << "/" << second.getDenominator() << endl;


    cout << "Сложение "; (first + second).print_answer();

    cout << "Вычитание "; (first - second).print_answer();

    cout << "Умножение "; (first * second).print_answer();

    cout << "Деление "; (first / second).print_answer();

	return 0;
}