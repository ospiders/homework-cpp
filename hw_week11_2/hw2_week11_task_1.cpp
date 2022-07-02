/* Написать функцию, реализующую алгоритм 
линейного поиска заданного ключа в одномерном массиве.*/
#include <iostream>
using namespace std;

void line_search(int mas[], int size, int key);

int main() {
	setlocale(LC_ALL, "");

	const int N = 5;
	int mas[N] { 0 };

	cout << "Заполните массив числами: " << endl;
	for (int i = 0; i < N; i++)
		cin >> mas[i];

	cout << "Введите ключ для поиска в массиве: ";
	int key;
	cin >> key;

	line_search(mas, N, key);

	return 0;
}

void line_search(int mas[], int size, int key) 
{
	for (int i = 0; i < size; i++) {
		if (mas[i] == key) {
			cout << "\nНайдено совпадение в массиве: " << mas[i] << endl;
			return;
		}
	}

	cout << "\nСовпадений не найдено!" << endl;
	return;
}