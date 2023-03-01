#include <iostream>
#include "Fraction.h"

Fraction::Fraction(int n, int d) : nominator { n }, denominator { d } {}

Fraction::Fraction() : Fraction { 1 , 1 } {}

Fraction::~Fraction() { }

int Fraction::getDenominator() { return denominator; }

int Fraction::getNominator() { return nominator; }

Fraction& Fraction::Addit(Fraction fraction) //сложение дробей
{
    nominator = (nominator * fraction.denominator) + (fraction.nominator * denominator);
    denominator = denominator * fraction.denominator;

	return *this;
}

Fraction& Fraction::Subtract(Fraction fraction) //вычитание дробей
{
    nominator = (nominator * fraction.denominator) - (fraction.nominator * denominator);
    denominator = denominator * fraction.denominator;

    return *this;
}

Fraction& Fraction::Multiply(Fraction fraction) //умножение дробей
{
    nominator = nominator * fraction.nominator;
    denominator = denominator * fraction.denominator;

    return *this;
}

Fraction& Fraction::Divide(Fraction fraction) //деление дробей
{   

    if (fraction.nominator == 0) { // делить на ноль нельзя
        nominator = 0;
        denominator = 0;
        return *this;
    }

    nominator = nominator * fraction.denominator;
    denominator = denominator * fraction.nominator;

    return *this;
}

Fraction& Fraction::FractionReduction() //сокращение дроби наименьшим общим делителем
{ 
    int tmp = reduce(nominator, denominator);

    if (tmp == 0) { //делить на ноль нельзя
        nominator = 0;
        denominator = 0;
        return *this;
    }

    nominator = nominator / tmp;
    denominator = denominator / tmp;

    return *this;
}

int Fraction::reduce(int n1, int n2) //поиск наименьшего общего делителя через рекурсию
{
    if (n1 == 0) // для вывода дроби 0/1
        return 1;

    if (n2 == 0)
        return n1;

    return reduce(n2, n1 % n2);
}

Fraction& Fraction::print_answer() //вывод на экран ответа
{
    std::cout << " || Ответ: " << this->nominator << "/" << this->denominator << "\n";
    return *this;
}