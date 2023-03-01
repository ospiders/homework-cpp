/*Cоздайте класс Complex (комплексное число) или используйте уже созданный вами класс. 
Создайте перегруженные операторы для реализации арифметических операций для 
по работе с комплексными числами (операции +, -, *, /).*/
#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    double _a, _b;

public:
    ComplexNumber(double a, double b) : _a{ a }, _b{ b } { }

    ComplexNumber() : ComplexNumber(1, 1) { }

    ~ComplexNumber() { }

    void read() 
    {
        cout << "Введите вещественную часть: ";
        cin >> _a;
        cout << "Введите мнимую часть: ";
        cin >> _b;
        return;
    }

    void print() 
    {
        cout << _a << (_b > 0 ? "+" : "") << _b << "*i";
        return;
    }

    ComplexNumber operator+ (ComplexNumber& right) 
    {
        return ComplexNumber(_a + right._a, _b + right._b);
    }

    ComplexNumber operator- (ComplexNumber& right) 
    {
        return ComplexNumber(_a - right._a, _b - right._b);
    }

    ComplexNumber operator* (ComplexNumber& right) 
    {
        double a = _a, b = _b,
               c = right._a, d = right._b;

        return ComplexNumber(a * c - b * d, b * c + a * d);
    }

    ComplexNumber operator/ (ComplexNumber& right) 
    {
        double a = _a, b = _b,
               c = _a, d = _b;

        double resultA = (a * c + b * d) / (c * c + d * d),
               resultB = (b * c - a * d) / (c * c + d * d);

        return ComplexNumber(resultA, resultB);
    }
};



int main() {
    setlocale(LC_ALL, "");

    ComplexNumber a, b;

    cout << "Число А\n";
    a.read();
    cout << "Число B\n";
    b.read();

    cout << endl;

    cout << "Результат сложения: "; a.print(); cout << " + "; b.print(); cout << " = ";
    (a + b).print(); cout << endl;

    cout << "Результат вычитания: "; a.print(); cout << " - "; b.print(); cout << " = ";
    (a - b).print(); cout << endl;

    cout << "Результат умножения: "; a.print(); cout << " * "; b.print(); cout << " = ";
    (a * b).print(); cout << endl;

    cout << "Результат деления: "; a.print(); cout << " / "; b.print(); cout << " = ";
    (a / b).print(); cout << endl;

    return 0;
}