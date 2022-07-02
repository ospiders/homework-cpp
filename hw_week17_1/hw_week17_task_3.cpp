/*Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. 
Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз). 
Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.*/

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int i, j, k;
	const int ROW = 6, COL = 5;


	int** mas = new int* [ROW];

	for (i = 0; i < ROW; i++)
		mas[i] = new int[COL];


	for (i = 0; i < ROW; i++) { //заполнение и вывод

		for (j = 0; j < COL; j++) {

			mas[i][j] = rand() % 100;
			cout << left << setw(3) << mas[i][j];
		}
		cout << endl;
	}


	cout << endl;
	int ch, num;
	do {
		cout << "1 - Вверх" << endl << "2 - Вниз" << endl
			 << "3 - Влево" << endl << "4 - Вправо" << endl
			 << "Введите сторону сдвига массива: ";

		cin >> ch;
	} while (ch != 1 && ch != 2 && ch != 3 && ch != 4);
	cout << endl;

	cout << "На какое количество сдвинуть массив: ";
	cin >> num;


	switch (ch) {

	case 1:

		for (k = 0; k < num; k++) {

			for (j = 0; j < COL; j++) {
				int tmp = mas[0][j];

				for (i = 0; i < ROW - 1; i++)
					mas[i][j] = mas[i + 1][j];

				mas[ROW - 1][j] = tmp;
			}
		}
		break;

	case 2:

		for (k = 0; k < num; k++) {

			for (j = 0; j < COL; j++) {
				int tmp = mas[ROW - 1][j];

				for (i = ROW - 1; i > 0; i--)
					mas[i][j] = mas[i - 1][j];

				mas[0][j] = tmp;
			}
		}
		break;

	case 3:

		for (k = 0; k < num; k++) {

			for (i = 0; i < ROW; i++) {
				int tmp = mas[i][0];

				for (j = 0; j < COL - 1; j++)
					mas[i][j] = mas[i][j + 1];

				mas[i][COL - 1] = tmp;
			}
		}
		break;

	case 4:

		for (k = 0; k < num; k++) {

			for (i = 0; i < ROW; i++) {
				int tmp = mas[i][COL - 1];

				for (j = COL - 1; j > 0; j--)
					mas[i][j] = mas[i][j - 1];

				mas[i][0] = tmp;
			}
		}
		break;
	}


	cout << endl;

	cout << "Результат:" << endl;
	for (int i = 0; i < ROW; i++) {

		for (int j = 0; j < COL; j++)
			cout << left << setw(3) << mas[i][j];

		cout << endl;
	}

	return 0;
}