#include"Fraction.h"

Fraction::Fraction(int n, int d) : nominator{ n }, denominator{ d } { FractionReduction(); }

Fraction::Fraction() : Fraction { 1 , 1 } { }

Fraction::~Fraction() { }

int Fraction::getDenominator() { return denominator; }

int Fraction::getNominator() { return nominator; }

Fraction Fraction::operator+ (Fraction fraction)
{
    return Fraction{ nominator * fraction.denominator + fraction.nominator * denominator, denominator * fraction.denominator };
}

Fraction Fraction::operator- (Fraction fraction)
{
    return Fraction{ nominator * fraction.denominator - fraction.nominator * denominator, denominator * fraction.denominator };
}

Fraction Fraction::operator* (Fraction fraction)
{
    return Fraction{ nominator * fraction.nominator, denominator * fraction.denominator };
}

Fraction Fraction::operator/ (Fraction fraction)
{
    return Fraction{ nominator * fraction.denominator, denominator * fraction.nominator };
}

void Fraction::FractionReduction() //сокращение дроби наименьшим общим делителем
{ 
    int tmp = reduce(nominator, denominator);

    if (tmp == 0 || denominator == 0) { //делить на ноль нельз¤
        nominator = 0;
        denominator = 0;
        return;
    }

    nominator = nominator / tmp;
    denominator = denominator / tmp;

    return;
}

int Fraction::reduce(int n1, int n2) //поиск наименьшего общего делител¤ через рекурсию
{
    if (n1 == 0) // дл¤ вывода дроби 0/1
        return 1;

    if (n2 == 0)
        return n1;

    return reduce(n2, n1 % n2);
}

Fraction& Fraction::print_answer() //вывод на экран ответа
{
    std::cout << " || Ответ: " << nominator << "/" << denominator << "\n";
    return *this;
}

void read(int& n1, int& n2)
{
    cout << "Введите числитель первой дроби: ";
    cin >> n1;
    do {
        cout << "Введите знаменатель первой дроби: ";
        cin >> n2;
        if (n2 == 0) cout << "ДЕЛИТЬ НА НОЛЬ НЕЛЬЗЯ!" << endl;
    } while (n2 == 0);
}