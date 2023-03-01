/*Написать функцию для перевода числа, записанного в двоичном виде, 
в десятичное представление.*/
#include <iostream>
using namespace std;

int binary_in_to_digit(char key[]);

int main() {
	setlocale(LC_ALL, "");

	cout << "Введите двоичный код: ";
	char key[32];
	cin >> key;

	int number = binary_in_to_digit(key);

	cout << "Число " << key << " = " << number;

	return 0;
}

int binary_in_to_digit(char key[])
{
	int answer = 0;

	for (int i = 0; i < strlen(key); i++) {
		answer *= 2;
		answer += key[i] - '0';
	}

	return answer;
}