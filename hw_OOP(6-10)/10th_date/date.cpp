/*Создайте класс с именем Date для хранения даты (или 
используйте ранее созданный). 
В классе должна быть функция-член, которая увеличивает день на 1.
Напишите соответствующие конструкторы и функции-члены. 
В классе должны быть перегружены операциии ++, -- , 
!=, ==, >, <, >>, <<, =, +=, -=, ().
Используйте обычную и дружественную перегрузку.*/

#include <iostream>
#include <iomanip>
using namespace std;

class Date {

private:

	int _day;
	int _month;
	int _year;

	static const int daysInMonth[13];

public:

	Date(int day, int month, int year) : _day{ day }, _month { month }, _year { year } { }
	
	Date() : Date(1, 1, 1900) { }

	~Date() { }

	Date(const Date& object) : _day{ object._day }, _month{ object._month }, _year{ object._year } { }

	
	inline bool is_LeapYear(int year) const
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}

	inline bool is_EndOfMonth(int day) const
	{
		return ((_month == 2 && is_LeapYear(_year)) ? day == 29 : day == daysInMonth[_month]);
	}

	void date_Decrement()
	{
		// если первый день месяца
		if (_day == 1) {
			if (_month > 1) {// если месяц больше 1
				_month--; 
				_day = daysInMonth[_month] + is_EndOfMonth(_day); // последний день месяца и + 1 если в феврале 29 дней
			}
			else {// если месяц меньше 1
				_year--;
				_month = 12; 
				_day = daysInMonth[_month] + is_EndOfMonth(_day); 
			}
		}
		else
			_day--;
	}

	void date_Increment()
	{
		//если последний день месяца
		if (is_EndOfMonth(_day)) {
			if (_month < 12) {
				_month++;
				_day = 1; // первый день следующего месяца
			}
			else {// если последний день года
				_year++; 
				_month = 1; 
				_day = 1;
			}
		}
		else
			_day++; 

		return;
	}

	const Date& operator-=(int days)
	{
		for (int i = 0; i < days; i++)
			date_Decrement();

		return *this;
	}

	const Date& operator+=(int days)
	{
		for (int i = 0; i < days; i++)
			date_Increment();

		return *this;
	} 

	Date& operator--()
	{
		date_Decrement();

		return *this;
	}
	
	Date operator--(int)
	{
		Date temp = *this;
		date_Decrement();
 
		return temp;
	}

	Date& operator++() 
	{
		date_Increment();

		return *this;
	}

	Date operator++(int)
	{
		Date temp = *this; 
		date_Increment();

		return temp;
	}
	
	const Date& operator() (int day, int month, int year)
	{
		_day = day;
		_month = month;
		_year = year;

		return *this;
	}

	friend ostream& operator<< (ostream& output, const Date& object)
	{
		output << object._day << "." << object._month << "." << object._year << endl;

		return output;
	}

	friend istream& operator>> (istream& input, Date& object)
	{	
		do {
			do {
				do {
					cout << "¬ведите день: ";
					input >> object._day;
				} while (object._day < 1 || object._day > 31);

				cout << "¬ведите мес¤ц: ";
				input >> object._month;
			} while (object._month < 1 || object._month > 12);

			cout << "¬ведите год: ";
			input >> object._year;
		} while ((object._year < 1900 || object._year > 9999) || daysInMonth[object._month] + object.is_EndOfMonth(object._day) < object._day);

		return input;
	}

	const Date operator= (const Date object)
	{
		_day = object._day;
		_month = object._month;
		_year = object._year;
		
		return *this;
	}
	
	inline bool operator!= (const Date& object) const
	{
		return (_day != object._day && _month != object._month && _year != object._year);
	}

	inline bool operator== (const Date& object) const
	{
		return !(*this != object);
	}

	bool operator> (const Date& object) const
	{
		bool days_AreEqual{ _day == object._day };
		bool months_AreEqual{ _month == object._month };
		bool years_AreEqual{ _year == object._year };

		bool day_IsGreater{ _day > object._day };
		bool month_IsGreater{ _month > object._month };
		bool year_IsGreater{ _year > object._year };

		return (year_IsGreater || (month_IsGreater && years_AreEqual) || (day_IsGreater && months_AreEqual && years_AreEqual));
	}

	inline bool operator< (const Date& object) const
	{
		return !(*this > object);
	}
};
	
const int Date::daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


int main() {
	setlocale(LC_ALL, "");
	
	Date date1 { 12, 03, 2000 };
	Date date2 { 22, 11, 1992 };
	Date date3;

	cin >> date3;
	cout << date3 << endl;

	cout << date1 << endl;

	date1 += 432;
	cout << date1 << endl;

	date1 -= 432;
	cout << date1 << endl;

	date1(22, 11, 1992);
	cout << date1 << endl;
	cout << date2 << endl;

	cout << (date1 > date2) << endl;
	cout << (date1 < date2) << endl;
	cout << (date1 == date2) << endl;
	cout << (date1 != date2) << endl;
	cout << endl;

	return 0;
}