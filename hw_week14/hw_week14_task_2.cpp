/*Даны два массива: А[M] и B[N] (M и N вводятся 
с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать 
элементы массивов A и B, которые не являются общими 
для них, без повторений*/
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>
using namespace std;

void init_mas(int* mas, int size);

void show_mas(int* mas, int size);

void init_mas_C(int* mas1, int size1, int* mas2, int size2, int* mas3);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int M, N;
	cout << "Укажите размер первого массива: ";
	cin >> M;
	int* A = new int[M];
	init_mas(A, M);

	Sleep(500); //  пауза, чтобы второй массив не заполнился идентичными значениями (если пользователь быстро вводит значения)

	cout << "Укажите размер второго массива: ";
	cin >> N;
	int* B = new int[N];
	init_mas(B, N);

	int O = N + M; // чтобы не терять элементы в выводе, если все элементы A != B;	
	int* C = new int[O];

	show_mas(A, M);
	show_mas(B, N);

	init_mas_C(A, M, B, N, C);

	show_mas(C, O);

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}

void init_mas(int* mas, int size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		*(mas + i) = rand() % 15 + 1;
	return;
}

void show_mas(int* mas, int size) {
	for (int i = 0; i < size; i++)
		if (*(mas + i) > 0) 
			cout << left << setw(3) << *(mas + i) << " ";
	cout << endl;
	return;
}

void init_mas_C(int* mas1, int size1, int* mas2, int size2, int* mas3) {
	int k = 0;
	int tmp = 0;
	for (int i = 0; i < size1; i++) { // в A нет общих с B
		for (int j = 0; j < size2; j++) {
			if (*(mas1 + i) == *(mas2 + j))
				tmp++;
		}
		if (tmp == 0) {
			*(mas3 + k) = *(mas1 + i);
			k++;
		}
		tmp = 0;
	}

	for (int i = 0; i < size2; i++) { // в B нет общих с А
		for (int j = 0; j < size1; j++) {
			if (*(mas2 + i) == *(mas1 + j))
				tmp++;
		}
		if (tmp == 0) {
			*(mas3 + k) = *(mas2 + i);
			k++;
		}
		tmp = 0;
	}
	return;
}
