/*Написать перегруженные функции (int, double, char) для выполнения следующих задач:
 Инициализация квадратной матрицы;
 Вывод матрицы на экран;
 Определение максимального и минимального элемента на главной диагонали матрицы;
 Сортировка элементов по возрастанию отдельно для каждой строки матрицы.*/

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void matrix_init(int mas[][5], int sz) { // int
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			mas[i][j] = (rand() % 50);
		}
	}
	return;
}

void matrix_init(double mas[][5], int sz) { // double
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			mas[i][j] = (double)(rand() % (50 * 10)) / 10.0;
		}
	}
	return;
}

void matrix_init(char mas[][5], int sz) { // char
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			mas[i][j] = 65 + (char)(rand() % (90 - 65 + 1));
		}
	}
	return;
}

void matrix_show(int mas[][5], int sz) { // int
	cout << "Вывод матрицы int" << endl;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << left << setw(3) << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	return;
}

void matrix_show(double mas[][5], int sz) { // double
	cout << "Вывод матрицы double" << endl;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << left << setw(4) << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	return;
}

void matrix_show(char mas[][5], int sz) { // char
	cout << "Вывод матрицы char" << endl;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			cout << left << setw(3) << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	return;
}

void matrix_glav_diag(int mas[][5], int sz) { // int
	cout << "Вывод матрицы по диагонали int" << endl;

	int max = 0, min = mas[0][0];
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (i == j) {
				if (max < mas[i][j]) max = mas[i][j];
				if (min > mas[i][j]) min = mas[i][j];
				cout << left << setw(3) << mas[i][j] << " ";
			}
			else cout << setw(3) << " ";
		}
		cout << endl;
	}
	cout << "Минимальное число: " << min << " Максимальное число: " << max << endl << endl;
	return;
}

void matrix_glav_diag(double mas[][5], int sz) { // double
	cout << "Вывод матрицы по диагонали double" << endl;
	double max = 0, min = mas[0][0];
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (i == j) {
				if (max < mas[i][j]) max = mas[i][j];
				if (min > mas[i][j]) min = mas[i][j];
				cout << left << setw(3) << mas[i][j] << " ";
			}
			else cout << setw(4) << " ";
		}
		cout << endl;
	}
	cout << "Минимальное число: " << min << " Максимальное число: " << max << endl << endl;
	return;
}

void matrix_glav_diag(char mas[][5], int sz) { // char
	cout << "Вывод матрицы по диагонали char" << endl;
	char max = 0, min = mas[0][0];
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (i == j) {
				if (max < mas[i][j]) max = mas[i][j];
				if (min > mas[i][j]) min = mas[i][j];
				cout << left << setw(3) << mas[i][j] << " ";
			}
			else cout << setw(3) << " ";
		}
		cout << endl;
	}
	cout << "Минимальный символ: "  << min << " Максимальный символ: " << max << endl << endl;
	return;
}

void matrix_sort_line(int mas[][5], int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = sz - 1; k > j; k--) {
				if (mas[i][k - 1] > mas[i][k])
					swap(mas[i][k - 1], mas[i][k]);
			}
		}
	}
	return;
}

void matrix_sort_line(double mas[][5], int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = sz - 1; k > j; k--) {
				if (mas[i][k - 1] > mas[i][k])
					swap(mas[i][k - 1], mas[i][k]);
			}
		}
	}
	return;
}

void matrix_sort_line(char mas[][5], int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			for (int k = sz - 1; k > j; k--) {
				if (mas[i][k - 1] > mas[i][k])
					swap(mas[i][k - 1], mas[i][k]);
			}
		}
	}
	return;
}


int main() {
	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	const int N = 5;
	int i_matrix[N][N]{ 0 };
	double d_matrix[N][N]{ 0 };
	char c_matrix[N][N]{ 0 };

	matrix_init(i_matrix, N);

	matrix_show(i_matrix, N);

	matrix_glav_diag(i_matrix, N);

	matrix_sort_line(i_matrix, N);

	matrix_show(i_matrix, N);


	matrix_init(d_matrix, N);

	matrix_show(d_matrix, N);

	matrix_glav_diag(d_matrix, N);

	matrix_sort_line(d_matrix, N);

	matrix_show(d_matrix, N);


	matrix_init(c_matrix, N);

	matrix_show(c_matrix, N);

	matrix_glav_diag(c_matrix, N);

	matrix_sort_line(c_matrix, N);

	matrix_show(c_matrix, N);

	return 0;
}