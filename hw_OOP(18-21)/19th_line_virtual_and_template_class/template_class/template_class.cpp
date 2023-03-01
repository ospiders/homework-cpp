/*Задание 1.
Добавьте механизм виртуального наследования в задание 
1 и 2 из самостоятельной работы.
Задание 2.
Используя механизм шаблонного наследования создайте 
иерархию классов. Базовый класс под названием base
имеет следующие переменные-члены:
1. T1 value1; // некоторое значение.
2. T2 value2; // некоторое значение.
Потомок под названием child содержит дополнительные 
переменные-члены:
1. T3 value3.
2. T4 value4.
Потомок под названием child2 добавляет такие переменные-члены:
1. T5 value5.
2. T6 value6.
Каждый класс имеет необходимый набор конструкторов, 
деструкторов, функций-членов для работы со структурой 
класса.
В main протестировать работу класса.*/

#include <iostream>

template<typename T1, typename T2>
class base {
public:
	T1 value1{};
	T2 value2{};

	base(T1 type1, T2 type2) : value1{ type1 }, value2{ type2 } {}
	base() = default;

	virtual void print() { std::cout << "BASE " << value1 << " " << value2 << std::endl; }
};

template<typename T3, typename T4>
class child : public base<T3, T4> {
public:
	T3 value3{};
	T4 value4{};

	child(T3 type3, T4 type4) : value3{ type3 }, value4{ type4 } {}
	child() = default;

	virtual void print() { std::cout << "CHILD " << value3 << " " << value4 << std::endl; }
};

template<typename T5, typename T6>
class child2 : public base<T5, T6>{
public:
	T5 value5{};
	T6 value6{};

	child2(T5 type5, T6 type6) : value5{ type5 }, value6{ type6 } {}
	child2() = default;

	virtual void print() { std::cout << "CHILD2 " << value5 << " " << value6 << std::endl; }
};

int main() {

	child2<const char*, const char*> t1("3", "s");
	child2<int, long long> t2;

	base<char, char> t3('3', 't');
	base<char, int> t4;

	child<bool, char> t5;
	child<int, short> t6(4, 7);

	t1.print();
	t2.print();
	t3.print();
	t4.print();
	t5.print();
	t6.print();

	return 0;
}