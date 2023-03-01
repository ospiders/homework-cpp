/*Реализуйте шаблонные функции для поиска максимума, 
минимума, сортировки массива (любым алгоритмом сортировки),
двоичного поиска в массиве, замены элемента массива на переданное значение*/

#include <iostream>
using namespace std;

template <typename T>
void print(T arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";

	cout << endl;
	return;
}

template <typename T>
void random(T arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = (rand() % 10);

	return;
}

template<>
void random(char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = 65 + (char)(rand() % (90 - 65 + 1));

	return;
}

template<>
void random(double arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = (double)(rand() % (10 * 10)) / 10.0;

	return;
}

template <typename T>
T find_Max(T arr[], size_t size)
{
	T tmp = arr[0];
	for (size_t i = 1; i < size;)
		(tmp > arr[i]) ? i++ : tmp = arr[i++];
		
	return tmp;
}

template <typename T>
T find_Min(T arr[], size_t size)
{
	T tmp = arr[0];
	for (size_t i = 1; i < size;)
		(tmp < arr[i]) ? i++ : tmp = arr[i++];

	return tmp;
}

template <typename T>
void bubble_Sort(T arr[], size_t size)
{
	for (size_t j = size - 1; j > 0; j--)
	{
		for (size_t i = 0; i < j; i++)
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
	}
}

template <typename T>
T binary_Search(T arr[], size_t size)
{
	T key;

	cout << "Введите значение элемента, которое хотите найти в массиве: ";
	cin >> key;

	size_t mid = 0, left = 0, right = size - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] == key) {
			cout << "Найдено совпадение в массиве: " << arr[mid] << endl;
			return arr[mid];
		}

		if (arr[mid] > key)
			right = mid - 1;

		else
			left = mid + 1;
	}

	cout << "Совпадений не найдено!\n";
	return 0;
}

template <typename T>
void set_Value(T arr[], size_t size)
{
	size_t index;
	T value;

	do {
		cout << "Введите индекс элемента, значение которого хотите заменить: ";
		cin >> index;
	} while (index < 0 || index >= size);

	cout << "Введите новое значение элемента: ";
	cin >> value;

	arr[index] = value;

	return;
}

int main() {
	setlocale(LC_ALL, "");

	const int size = 5;

	//int arr[size]{};

	double arr[size]{};

	//char arr[size]{};
	
	random(arr, size);

	cout << "Максимальный элемент: " << find_Max(arr, size) << endl;
	cout << "Минимальный элемент: " << find_Min(arr, size) << endl;

	bubble_Sort(arr, size);
	print(arr, size);

	binary_Search(arr, size);

	set_Value(arr, size);
	print(arr, size);
	
	return 0;
}