/* Создайте структуру, описывающую комплексное число. 
Реализуйте арифметические операции с комплексными числами: сумму, разность, умножение, деление.*/
#include <iostream>
using namespace std;

struct ComplexNumber
{
    double a, b;

    ComplexNumber() {
        a = 0;
        b = 0;
    }

    ComplexNumber(double a, double b) {
        this->a = a;
        this->b = b;
    }

    void read() 
    {
        cout << "Введите вещественную часть: ";
        cin >> a;
        cout << "Введите мнимую часть: ";
        cin >> b;
        return;
    }

    void print() 
    {
        cout << a << (b > 0 ? "+" : "") << b << "*i";
        return;
    }

    ComplexNumber plus(ComplexNumber& right) 
    {
        return ComplexNumber(this->a + right.a, this->b + right.b);
    }

    ComplexNumber minus(ComplexNumber& right) 
    {
        return ComplexNumber(this->a - right.a, this->b - right.b);
    }

    ComplexNumber multiply(ComplexNumber& right) 
    {
        double a = this->a, b = this->b,
               c = right.a, d = right.b;
        return ComplexNumber(a * c - b * d, b * c + a * d);
    }

    ComplexNumber divide(ComplexNumber& right) 
    {
        double a = this->a, b = this->b,
               c = right.a, d = right.b;
        double resultA = (a * c + b * d) / (c * c + d * d),
               resultB = (b * c - a * d) / (c * c + d * d);
        return ComplexNumber(resultA, resultB);
    }
};



int main() {
    setlocale(LC_ALL, "");

    ComplexNumber a, b, result;

    cout << "Число А\n";
    a.read();
    cout << "Число Б\n";
    b.read();

    cout << endl;

    result = a.plus(b);
    cout << "Результат сложения: "; a.print(); cout << " + "; b.print(); cout << " = ";
    result.print(); cout << endl;

    result = a.minus(b);
    cout << "Результат вычитания: "; a.print(); cout << " - "; b.print(); cout << " = ";
    result.print(); cout << endl;

    result = a.multiply(b);
    cout << "Результат умножения: "; a.print(); cout << " * "; b.print(); cout << " = ";
    result.print(); cout << endl;

    result = a.divide(b);
    cout << "Результат деления: "; a.print(); cout << " / "; b.print(); cout << " = ";
    result.print(); cout << endl;

    return 0;
}