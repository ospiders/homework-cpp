/*Написать функцию, определяющую количество положительных, отрицательных и нулевых 
элементов передаваемого ей массива.*/
#include <iostream>
#include <windows.h>
using namespace std;

void show_plus_minus_zero(int m[], int s) {
	int minus_count = 0;
	int plus_count = 0;
	int zero_count = 0;

	for (int i = 0; i < s; i++) {
		if (m[i] < 0) minus_count++;

		else if (m[i] > 0) plus_count++;

		else zero_count++;
	}

	cout << "Количество отрицательных елементов: " << minus_count << endl
		 << "Количество положительных елемнтов: " << plus_count << endl
		 << "Количество елементов с нулевым значением: " << zero_count << endl;

	return;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 10;
	int mas[size]{ };
	int exit;

	cout << "Заполните массив с размером в " << size << " чисел" << endl; 
	do {
		for (int i = 0; i < size; i++) {
			cout << "Введите " << i + 1 << " число: ";
			cin >> mas[i];
		}

		show_plus_minus_zero(mas, size);

		cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
		cin >> exit; cout << endl;

	} while (exit != 0);

	return 0;
}