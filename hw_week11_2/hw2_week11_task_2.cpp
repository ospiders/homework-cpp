/*Написать функцию, реализующую алгоритм 
бинарного поиска заданного ключа в одномерном массиве.*/
#include <iostream>
using namespace std;

void binary_search(int mas[], int size, int key);

int main() {
	setlocale(LC_ALL, "");

	const int N = 5;
	int mas[N]{ 0 };

	cout << "Заполните массив числами: " << endl;
	for (int i = 0; i < N; i++)
		cin >> mas[i];

	cout << "Введите ключ для поиска в массиве: ";
	int key;
	cin >> key;

	binary_search(mas, N, key);

	return 0;
}

void binary_search(int mas[], int size, int key)
{	
	int l = 0, r = size - 1;
	int mid;

	while (l <= r) {
		mid = (l + r) / 2;

		if (mas[mid] == key) {
			cout << "\nНайдено совпадение в массиве: " << mas[mid] << endl;
			return;
		}

		if (mas[mid] > key)
			r = mid - 1;

		else
			l = mid + 1;
	}

	cout << "\nСовпадений не найдено!" << endl;
	return;
}