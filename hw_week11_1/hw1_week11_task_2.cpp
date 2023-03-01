/*Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму 
чисел из диапазона между ними*/
#include <iostream>
#include <windows.h>
using namespace std;

template<typename T1> T1 sumAll(T1 a, T1 b) {
	T1 res = a;

	while (a < b) {
		res += a + 1;
		a++;
	}
	return res;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int first_num, second_num, exit;

	do {
		cout << "|Программа для нахождения суммы чисел из диапазона между ними|" << endl;
		cout << "Введите первое число: ";
		cin >> first_num;
		cout << "Введите второе число: ";
		cin >> second_num;

		cout << "Сумма чисел в диапазоне между числами " << first_num << " и " << second_num << " = " << sumAll(first_num, second_num) << endl;

		cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
		cin >> exit; cout << endl;

	} while (exit != 0);

	return 0;
}