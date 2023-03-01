/*Задание 1. Написать функцию, которая принимает два 
параметра: основание степени и показатель степени, и 
вычисляет степень числа на основе полученных данных.*/
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T1> T1 stepEn(T1 a, T1 b) {
	T1 res = 1;

	if (b == 0) return 1; 

	if (a == 0 ) return 0;

	else if (b < 0) {
		while (b) {
			res *= a;
			b++;
		}
		return 1 / res;
	}

	else {
		while (b) {
			res *= a;
			b--;
		}
		return res;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	double base, index;
	short exit;

	do {
	cout << ": ";
	cin >> base;
	cout << ": ";
	cin >> index;

	cout << base << " " << index << " = " << stepEn(base, index) << endl;

	cout << endl << "1, 0: ";
	cin >> exit; cout << endl;
	
	} while (exit != 0);

	return 0;
}