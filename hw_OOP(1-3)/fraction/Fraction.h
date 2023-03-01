#pragma once
class Fraction {// класс дробь

private:
	int nominator; // числитель
	int denominator;// знаменатель

public:	
	Fraction(int n, int d);
	Fraction();
	~Fraction();
	
	int getNominator();
	int getDenominator();

	Fraction& Addit(Fraction fraction); //сложение дробей

	Fraction& Subtract(Fraction fraction); //вычитание дробей

	Fraction& Multiply(Fraction fraction); //умножение дробей

	Fraction& Divide(Fraction fraction); //деление дробей

	Fraction& FractionReduction(); //сокращение значений входящей дроби наименьшим общим знаменателем
	
	int reduce(int n1, int n2); //поиск наименьшего общего знаменателя через рекурсию

	Fraction& print_answer();
};

