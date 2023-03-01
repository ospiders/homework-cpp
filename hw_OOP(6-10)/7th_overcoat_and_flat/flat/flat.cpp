/*Создать класс Flat (квартира).
Реализовать перегруженные операторы:
1. Проверка на равенство площадей квартир (операция ==).
2. Операцию присваивания одного объекта в другой (операция =).
3. Сравнение двух квартир по цене (операция>).*/

#include <iostream>
using namespace std;

class Flat {
private:

	double _square;
	int _cost;

public:

	Flat(double square, int cost) : _square { square }, _cost{ cost } { }

	Flat() : Flat(0, 0) { }

	~Flat() { }

	bool operator== (const Flat& object) const
	{
		if(_square != object._square)
			return false;

		return true;
	}

	const Flat& operator= (const Flat& object)
	{
		_square = object._square;
		_cost = object._cost;

		return *this;
	}

	bool operator> (const Flat& object) const
	{
		return _cost > object._cost;
	}

	bool operator< (const Flat& object) const
	{
		return _cost < object._cost;
	}
};

int main() {

	Flat flat1{ 26.7, 1000000 };
	Flat flat2{ 36.5, 4088000 };
	Flat flat3{ 24.1, 928800 };
	Flat flat4{ 45.6, 7340000 };
	Flat flat5{ 26.7, 1200000 };

	flat1 == flat5 ? cout << true << endl : cout << false << endl;

	flat2 == flat3 ? cout << true << endl : cout << false << endl;

	flat2 > flat4 ? cout << true << endl : cout << false << endl;

	flat1 > flat3 ? cout << true << endl : cout << false << endl;

	flat1 < flat5 ? cout << true << endl : cout << false << endl;

	flat2 < flat1 ? cout << true << endl : cout << false << endl;

	return 0;
}