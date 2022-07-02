/*Написать функцию, которая определяет, является ли «счастливым» шестизначное число.*/
#include <iostream>
#include <windows.h>
using namespace std;

template<typename T1> void is_lucky(T1 num) {
	T1 part1, part2;
	T1 sum1 = 0;
	T1 sum2 = 0;

	part1 = num / 1000;
	part2 = num % 1000;

	while (part1 != 0) {
		sum1 += part1 % 10;
		part1 = part1 / 10;
	}

	while (part2 != 0) {
		sum2 += part2 % 10;
		part2 = part2 / 10;
	}

	if (sum1 == sum2)
		cout << "У вас счастливое число" << endl;
	else
		cout << "Повезет в другой раз" << endl;

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num, exit;
	
	do {
	vvod: // 1
		cout << "Введите шестизначное число: ";
		cin >> num;
		if (num > 999999)
			goto vvod; // 1

		is_lucky(num);

		cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
		cin >> exit;

	} while (exit != 0);

	return 0;
}