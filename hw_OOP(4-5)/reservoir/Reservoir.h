/*Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название». Класс должен содержать: 
конструктор по умолчанию, конструктор с параметрами, 
при необходимости реализовать деструктор и конструктор копирования.
Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному 
типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов 
одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).
Написать интерфейс для работы с классом. Реализовать 
динамический массив объектов класса с возможностью 
добавления, удаления объектов из массива. Реализовать 
возможность записи информации об объектах массива 
в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функции члены (например, для отображения данных о водоёме и т.д.)*/
#pragma once

#include <iostream>
#include <windows.h>

using namespace std;

class Reservoir {
	char* _reservoir_name = nullptr;
	int _width = 0;
	int _length = 0;
	int _depth = 0;
	int _volume = 0;
	int _square = 0;

public:

	Reservoir(const char* name, int width, int length, int depth) : _reservoir_name { new char [strlen(name) + 1]()}, _width { width },
		_length{ length }, _depth{ depth }, _volume{ width * length * depth }, _square{ width * length } { strcpy_s(_reservoir_name, strlen(name) + 1, name); }

	Reservoir() : Reservoir("default_type", 0, 0, 0) { }

	Reservoir(const Reservoir& object) : _reservoir_name{ new char[strlen(object._reservoir_name) + 1]() }, _width{ object._width },
		_length{ object._length }, _depth{ object._depth }, _volume{ object._volume }, _square{ object._square }
		{ strcpy_s(_reservoir_name, strlen(object._reservoir_name) + 1, object._reservoir_name); }

	~Reservoir() { delete[] _reservoir_name; }

	int get_ReservoirSquare() { return _square; }
	int get_ReservoirVolume() { return _volume; }

	void set_Reservoir(char* name, int width, int length, int depth, int volume, int square)
	{
		reservoir_DeepArrayCopy(_reservoir_name, name);
		_width = width;
		_length = length;
		_depth = depth;
		_volume = volume;
		_square = square;

		return; 
	}

	Reservoir& calculate_Volume() 
	{
		_volume = _width * _length * _depth; 

		return *this; 
	}

	Reservoir& calculalte_Square()
	{
		_square = _width * _length;

		return *this;
	}

	Reservoir& read()
	{	
		char tmp_name[40];
		cout << "Введите имя резервуара: ";
		cin >> tmp_name;

		reservoir_DeepArrayCopy(_reservoir_name, tmp_name);

		cout << "Введите ширину резервуара: ";
		cin >> _width;
		cout << "Введите длинну резервуара: ";
		cin >> _length;
		cout << "Введите глубину резервуара: ";
		cin >> _depth;

		return *this;
	}

	void print() const
	{
		cout << "Название резервуара: " << _reservoir_name << endl
			<< "Размер: ширина: " << _width 
			<< " длинна: " << _length 
			<< " глубина: " << _depth << endl
			<< "Объем: " << _volume << endl
			<< "Площадь: " << _square << endl;

		cout << endl;
		return;
	}

	bool reservoir_NameCompare(Reservoir& object1, Reservoir& object2) 
	{ 
		bool isEqual{ false };

		int size1 = strlen(object1._reservoir_name);
		int size2 = strlen(object2._reservoir_name);
		
		if (size1 != size2)
			return false;

		for (int i = 0; i < strlen(object2._reservoir_name); i++) {
			if (object1._reservoir_name[i] == object2._reservoir_name[i])
				isEqual = true;

			else {
				isEqual = false;
				break;
			}
		}
		return isEqual;	
	}

	bool reservoir_SquareCompare(Reservoir& object1, Reservoir& object2) 
	{ 
		return object1._square == object2._square; 
	}

	Reservoir& operator= (const Reservoir& object)
	{
		if(this == &object)
			return *this;

		if (_reservoir_name != nullptr)
			delete[] _reservoir_name;

		reservoir_DeepArrayCopy(_reservoir_name, object._reservoir_name);

		_width = object._width;
		_length = object._length;
		_depth = object._depth;
		_volume = object._volume;
		_square = object._square;

		return *this;
	}

	void reservoir_DeepArrayCopy(char*& dest, const char* source)
	{
		int size = strlen(source) + 1;
		dest = new char[size];
		strcpy_s(dest, size, source);
	}

	void write_In_File(FILE* file)
	{
		fprintf(file, "%s\n%d\n%d\n%d\n%d\n%d\n", _reservoir_name, _width, _length, _depth, _volume, _square);

		return;
	}
};

/////////////////// CLASS END //////////////////////////

int menu()
{
	int choice;
	cout << "\tМеню настройки Резервуаров\n"
		<< "1 - Добавить резервуар\n"
		<< "2 - Удалить резервуар\n"
		<< "3 - Показать все резервуары\n"
		<< "4 - Сравнить резервуары на выбор\n"
		<< "0 - Выход\n> ";
	cin >> choice;

	cout << endl;
	return choice;
}

void add_Reservoir(Reservoir*& object, int& size)
{
	Reservoir* tmp_object = new Reservoir[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_object[i] = object[i];

	tmp_object[size].read().calculate_Volume().calculalte_Square();

	delete[] object;
	object = tmp_object;

	size += 1;

	return;
}

void remove_Reservoir(Reservoir*& object, int key, int& size)
{
	for (int i = 0; i < size; i++) {
		if (i == key - 1) {
			for (int j = i; j < size - 1; j++)
				swap(object[j], object[j + 1]);

			size--;
			break;
		}
	}
	return;
}

void compare_Reservoir(Reservoir*& object, int key1, int key2, int size)
{
	Reservoir tmp;

	if (key1 > size || key2 > size) {
		cout << "Такой резервуар не существует. Повторите попытку\n\n";
		return;
	}

	if (tmp.reservoir_NameCompare(object[key1 - 1], object[key2 - 1]))
		cout << "Резервуары соответствуют по типу\n";
	else
		cout << "Резервуары не соответствуют по типу\n";

	if (tmp.reservoir_SquareCompare(object[key1 - 1], object[key2 - 1]))
		cout << "Резервуары соответствуют по площади\n";
	else
		cout << "Резервуары не соответствуют по площади\n";

	return;
}

void read_From_File(Reservoir*& object, int& size, FILE* file)
{
	Reservoir* tmp_sub = new Reservoir[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_sub[i] = object[i];

	char tmp_name[128]{ 0 };
	int tmp_width = 0, tmp_length = 0,
		tmp_depth = 0, tmp_volume = 0, 
		tmp_square = 0;

	fscanf_s(file, "%[^\n]\n%d\n%d\n%d\n%d\n%d\n", tmp_name, sizeof(tmp_name), &tmp_width, &tmp_length, &tmp_depth, &tmp_volume, &tmp_square);

	tmp_sub[size].set_Reservoir(tmp_name, tmp_width, tmp_length, tmp_depth, tmp_volume, tmp_square);

	delete[] object;
	object = tmp_sub;

	size += 1;

	return;
}
