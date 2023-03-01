#pragma once
#include <iostream>
#include <windows.h>
using namespace std;


class Human
{
	char* _human{ nullptr };
	static int _human_counter;
public:

	Human(const char* human) : _human{ new char[strlen(human) + 1]() } { strcpy_s(_human, strlen(human) + 1, human); }

	Human(const Human& object) : _human{ new char [strlen(object._human) + 1]() } {	strcpy_s(_human, strlen(object._human) + 1, object._human); }

	Human() 
	{
		char tmp_name[128];

		cout << "Введите ФИО жильца квартиры: ";
		cin.getline(tmp_name, 127, '\n');
		
		int size = strlen(tmp_name) + 1;

		_human = new char[size];
		strcpy_s(_human, size, tmp_name);

		_human_counter++;
	}

	~Human() { delete[] _human; }

	void print() { cout << "ФИО жильца: " << _human << endl; }

	static int get_HumansCount() { return _human_counter; }
};

int Human::_human_counter = 0;


////////////////////// APARTMENT ///////////////////////

class Apartment
{
	Human* _apartments{ nullptr };
	static int _apartments_counter;
	int _human_count{ 0 };
public:

	Apartment(int human_count) : _apartments{ new Human[human_count] } {}

	Apartment(const Apartment& object) : _apartments{ new Human[object._human_count] } {}

	Apartment() : _apartments{ nullptr } {
		cout << "Введите количество жильцов в квартире #" << get_ApartmentsCount() + 1 << ": ";
		cin >> _human_count;
		cin.ignore();
		_apartments = new Human[_human_count];

		_apartments_counter++;
	}

	~Apartment() { delete[] _apartments; }

	void print()
	{
		for (int i = 0; i < _human_count; i++)
			_apartments[i].print();
		cout << endl;
	}
	
	static int get_ApartmentsCount() { return _apartments_counter; }
};

int Apartment::_apartments_counter = 0;


///////////////////// HOUSE ///////////////////////////

class House
{
	Apartment* _apartments{ nullptr };
	int _apartments_count{ 0 };

public:

	House(int apartments_count) : _apartments{ new Apartment[apartments_count] } {}

	House(const House& object) : _apartments{ new Apartment[object._apartments_count] } {}

	House() : _apartments{ nullptr }
	{
		cout << "Введите количество квартир в доме: ";
		cin >> _apartments_count;
		cin.ignore();
		_apartments = new Apartment[_apartments_count];
	}

	~House() { delete[] _apartments; }

	void print()
	{
		cout << "Количество квартир в доме: " << _apartments_count << endl << endl;

		for (int i = 0; i < _apartments_count; i++) {
			cout << "В квартире #" << i + 1 << " проживают: " << endl;
			_apartments[i].print();
		}
	}
};