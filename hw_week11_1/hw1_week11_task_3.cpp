/*Число называется совершенным, если сумма всех его делителей равна ему самому. Напишите 
функцию поиска таких чисел во введенном интервале.*/

#include <iostream>
#include <windows.h>
using namespace std;

template<typename T1> T1 perfect_num(T1 num) {
	T1 res = 0;

	for (int i = 1; i < num; i++) {
			if (num % i == 0)
				res += i;
	}
	return res;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num = 1;
	cout << "Введите последовательность целых чисел, заканчивающуюся числом 0" << endl;

	while (num != 0) {
		cout << "Введите число: ";
		cin >> num;

		if (perfect_num(num) == num && num != 0)
			cout << "Найдено совершенное число: " << num << endl;

		else if (num == 0) 
			cout << "Завершение программы";

		else
			cout << "Число " << num << " не совершенное" << endl;
	}

	return 0;
}