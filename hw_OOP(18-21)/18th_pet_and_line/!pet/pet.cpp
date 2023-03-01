/*Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай».
С помощью конструктора установить имя каждого животного и его характеристики.*/

#include <iostream>

class Pet {

	std::string _nickname;
	int _weight;

public:

	Pet(std::string nickname, int weight) : _nickname{ nickname }, _weight{ weight } {}
	~Pet() {}

	void print() 
	{
		std::cout << "Кличка: " << _nickname << "\nВес: " << _weight << " кг.\n";
	}
};

class Dog : public Pet {

public:
	Dog(std::string nickname, int weight) : Pet(nickname, weight) {}
};

class Cat : public Pet {

public:
	Cat(std::string nickname, int weight) : Pet(nickname, weight) {}
};

class Parrot : public Pet {

public:
	Parrot(std::string nickname, int weight) : Pet(nickname, weight) {}
};

int main() {
	std::setlocale(LC_ALL, "");

	Dog dog("Дарвин", 6);
	dog.print();

	Cat cat("Буся", 3);
	cat.print();

	Parrot parrot("Вася", 1);
	parrot.print();

	return 0;
}