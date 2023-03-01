/*Создать класс Overcoat (верхн¤¤ одежда).
Реализовать перегруженные операторы:
1. Проверка на равенство типов одежды (операция ==).
2. Операцию присваивания одного объекта в другой 
(операция =).
3. Сравнение по цене двух пальто одного типа (операция>).*/
#include <iostream>
using namespace std;

class Overcoat {
private:

	char* _p_overcoat_type;
	size_t _size;
	int _cost;

public:

	Overcoat(const char* overcoat, int cost) : _p_overcoat_type{ new char[strlen(overcoat) + 1] }, _size{ strlen(overcoat) + 1 }, _cost{ cost } { strcpy_s(_p_overcoat_type, _size, overcoat); }

	Overcoat() : Overcoat(nullptr, 0) { }

	~Overcoat() { }

	bool operator== (const Overcoat& object) const
	{
		if (_size != object._size)
			return false;

		for (int i = 0; i < _size; i++) {
			if (_p_overcoat_type[i] != object._p_overcoat_type[i])
				return false;
		}

		return true;
	}

	const Overcoat& operator= (const Overcoat& object)
	{
		if (&object != this)
		{
			if (_size != object._size)
			{
				delete[] _p_overcoat_type;
				_size = object._size;
				_p_overcoat_type = new char[_size];
			}

			for (int i = 0; i < _size; ++i)
				_p_overcoat_type[i] = object._p_overcoat_type[i];

			_cost = object._cost;
		}
		return *this;
	}

	bool operator> (const Overcoat& object) const
	{
		return _cost > object._cost;
	}

	bool operator< (const Overcoat& object) const
	{
		return _cost < object._cost;
	}
};

int main() {

	Overcoat item1{ "jacket", 10000 };
	Overcoat item2{ "t-shirt", 1000 };
	Overcoat item3{ "sweater", 4000 };
	Overcoat item4{ "t-shirt", 1500 };
	Overcoat item5{ "overcoat", 4000 };

	item1 == item3 ? cout << true << endl : cout << false << endl;

	item2 == item4 ? cout << true << endl : cout << false << endl;

	item2 > item4 ? cout << true << endl : cout << false << endl;

	item1 > item3 ? cout << true << endl: cout << false << endl;

	item1 < item5 ? cout << true << endl : cout << false << endl;

	item2 < item1 ? cout << true << endl : cout << false << endl;

	return 0;
}