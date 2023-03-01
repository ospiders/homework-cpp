/*Добавить в уже существующий класс Array конструктор переноса*/
#include<iostream>
#include<windows.h>
using namespace std;

class _Array
{
	int* _p_array;
	int _size;

public:
	_Array(int size) : _p_array{ new int[size]() }, _size{size} { }

	_Array() : _Array(15) { }

	_Array(const _Array& object) : _p_array{ new int[object._size] }, _size{ object._size }
	{
		for (int i = 0; i < _size; i++)
			_p_array[i] = object._p_array[i];
	}

	~_Array() { delete[] _p_array; }

	void print()
	{	
		for (int i = 0; i < _size; i++)
			cout << _p_array[i] << " ";

		cout << _size << endl;
	}

	void random()
	{
		for (int i{ 0 }; i < _size; ++i)
			_p_array[i] = rand() % 10;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	_Array arr1 {};
	_Array arr2{ 10 };
	arr1.random();
	arr2.random();
	_Array arr3{ arr1 };

	arr1.print();
	arr2.print();
	arr3.print();

	return 0;
}