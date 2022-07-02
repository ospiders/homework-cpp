/*Ќаписать функцию, котора€ принимает два параметра: основание степени и показатель 
степени, и вычисл€ет степень числа на основе полученных данных.*/
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T1> T1 stepEn(T1 a, T1 b) {
	T1 res = 1;

	if (b == 0) return 1; // любое число в степени 0 == 1

	if (a == 0 ) return 0; // 0 в любой степени == 0

	else if (b < 0) {
		while (b) {//отрицательна€ степень
			res *= a;
			b++;
		}
		return 1 / res;
	}

	else {
		while (b) { //положительна€
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
	cout << "¬ведите основание степени: ";
	cin >> base;
	cout << "¬ведите показатель степени: ";
	cin >> index;

	cout << base << " в степени " << index << " = " << stepEn(base, index) << endl;

	cout << endl << "≈сли хотите продолжить введите 1, выйти 0: ";
	cin >> exit; cout << endl;
	
	} while (exit != 0);

	return 0;
}