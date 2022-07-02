/*Написать функцию, определяющую среднее арифметическое элементов передаваемого ей 
массива*/
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T1, typename T2> T1 average_mean(T1 nums[], T2 size) {
	T1 allsum = nums[0];

	for (int i = 1; i < size; i++)
		allsum += nums[i];

	return allsum / size;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 5;
	double mas[size]{ 0 };
	int exit;

	do {
		for (int i = 0; i < size; i++) {
			cout << "Введите число: ";
			cin >> mas[i];
		}

		cout << endl << average_mean(mas, size);

		cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
		cin >> exit;

	} while (exit != 0);

	return 0;
}