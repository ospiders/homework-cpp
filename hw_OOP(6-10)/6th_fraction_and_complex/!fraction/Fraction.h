#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

class Fraction {

private:
	int nominator; 
	int denominator;

public:	
	Fraction(int n, int d);
	Fraction();
	~Fraction();
	
	int getNominator();
	int getDenominator();

	Fraction operator+ (Fraction fraction);

	Fraction operator- (Fraction fraction);

	Fraction operator* (Fraction fraction);

	Fraction operator/ (Fraction fraction);

	void FractionReduction(); //сокращение значений входящей дроби наименьшим общим делителем
	
	int reduce(int n1, int n2); //поиск наименьшего общего делителя через рекурсию

	Fraction& print_answer();
};

void read(int& n1, int& n2);