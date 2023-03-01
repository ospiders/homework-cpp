/*Разработать класс String, который в дальнейшем будет 
использоваться для работы со строками. Класс должен 
содержать: 
•	 Конструктор по умолчанию, позволяющий создать строку длиной 80 символов; 
•	 Конструктор, позволяющий создавать строку произвольного размера; 
•	 Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя. 
Необходимо создать деструктор, а также использовать 
механизмы делегирования конструкторов, если это возможно.
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран. Также нужно реализовать 
статическую функцию-член, которая будет возвращать количество созданных объектов строк*/
#include<iostream>
#include<windows.h>
using namespace std;

class _String
{
	char* str;
	static int object_count;

public:
	_String(int size) : str{ new char[size + 1] } { str[size] = '\0'; object_count++; }
	
	_String() : _String(80) { object_count++; }

	_String(const char* enter_str) : str { new char [strlen(enter_str) + 1] }
	{
		int len = strlen(enter_str);
		for (int i = 0; i < len; i++)
			str[i] = enter_str[i];

		str[len] = '\0';
		object_count++;
	}

	~_String() { delete[] str; }

	void print()
	{
		cout << str << " " << strlen(str) << endl;
	}

	void read()
	{
		cout << "Введите строку перезаписи: ";
		cin.getline(str, 128, '\n');
	}

	static int get_ObjectCount() { return object_count;	}
};

int _String::object_count = 0;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str[128]{ 0 };
	cout << "Введите строку инициализации: ";
	cin.getline(str, 128, '\n');
	const char* p_str{ str };

	_String str1{ "hello world" };
	_String str2;
	_String str3{p_str};
	_String str4(1);
	_String str5;

	str2.read();

	str1.print();
	str2.print();
	str3.print();
	str4.print();
	str5.print();

	cout << "Количество обьектов класса: " << _String::get_ObjectCount();

	return 0;
}