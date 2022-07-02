/*Написать функцию, удаляющую столбец двух мерного массива по указанному номеру.*/
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int ROW = 5, COL = 5;
	int i, j;


	int** arr_p = new int* [ROW];

	for (i = 0; i < ROW; i++)
		arr_p[i] = new int[COL];


	for (i = 0; i < ROW; i++) {

		for (j = 0; j < COL; j++) {
			arr_p[i][j] = j + 1;

			cout << arr_p[i][j] << " ";
		}
		cout << "\n";
	}


	cout << endl;

	int col_new;
	do {
		cout << "Укажите позицию, где хотите удалить столбик: ";
		cin >> col_new;

		if(col_new <= 0 || col_new > COL)
			cout << "Выход за пределы массива\n";

	} while (col_new <= 0 || col_new > COL);
	col_new--;

	cout << endl;


	for (i = 0; i < ROW; i++) {

		for (j = 0; j < COL; j++) {	
			int jx = j;

			if (j >= col_new)
				--jx;

			if (j == col_new)
				arr_p[i][j] = arr_p[i][j];

			else
				arr_p[i][jx] = arr_p[i][j];
		}
	}


	for (i = 0; i < ROW; i++) {

		for(j = 0; j < COL - 1; j++)
			cout << arr_p[i][j] << " ";

		cout << endl;
	}


	for (i = 0; i < ROW; i++)
		delete[]arr_p[i];

	delete[]arr_p;

	return 0;
}