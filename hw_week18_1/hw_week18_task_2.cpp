/*Есть 3 двумерных массива A, B, C. Количество 
строк и столбцов для них вводит пользователь с клавиатуры для каждого из них. Реализуйте
■ Создайте одномерный массив, который содержит 
общие значения для A, B, C;
■ Создайте одномерный массив, который содержит 
уникальные значения для A, B, C;
■ Создайте одномерный массив, который содержит 
общие значения для A и C;
■ Создайте одномерный массив, который содержит 
отрицательные значения для A, B, C без повторений.*/

#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

int** Init_Arr(int ROW, int COL);

void Show_Arr_1D(int* arr, int size);

void Show_Arr_2D(int** arr, int ROW, int COL);

void Sort_Arr(int* arr, int ROW);

int* Arr_2D_To_1D(int** arr, int ROW, int COL);

int* Merge_Arrs(int* arr1, int* arr2, int* arr3, int ROW_A, int ROW_B, int ROW_C);

int* Find_Unique(int* arr, int& size);

void Comm_Arr_Val(int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr);

void Comm_Arr_Negative_Val(int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr);

void Comm_Arr_Val(int** arr_1th, int** arr_3th, int ROW_A, int COL_A, int ROW_C, int COL_C, int* arr);

void Unique_Arr_Val(int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ROW_A, COL_A, ROW_B, COL_B, ROW_C, COL_C;
	
	cout << "Введите количество строк 1 массива: ";
	cin >> ROW_A;
	cout << "Введите количество столбцов 1 массива: ";
	cin >> COL_A;

	cout << "\nИнициализация 1 массива:" << endl;
	int** A = Init_Arr(ROW_A, COL_A);

	cout << "\nВведите количество строк 2 массива: ";
	cin >> ROW_B;
	cout << "Введите количество столбцов 2 массива: ";
	cin >> COL_B;

	cout << "\nИнициализация 2 массива: " << endl;
	int** B = Init_Arr(ROW_B, COL_B);

	cout << "\nВведите количество строк 3 массива: ";
	cin >> ROW_C;
	cout << "Введите количество столбцов 3 массива: ";
	cin >> COL_C;

	cout << "\nИнициализация 3 массива: " << endl;
	int** C = Init_Arr(ROW_C, COL_C); 

	cout << "\n Вывод 1 массива:\n"; Show_Arr_2D(A, ROW_A, COL_A);
	cout << "\n Вывод 2 массива:\n"; Show_Arr_2D(B, ROW_B, COL_B);
	cout << "\n Вывод 3 массива:\n"; Show_Arr_2D(C, ROW_C, COL_C);

	int* first_task_arr = new int[30]();
	int* second_task_arr = new int[30]();
	int* third_task_arr = new int[30]();
	int* fourth_task_arr = new int[30]();

	Comm_Arr_Val(A, B, C, ROW_A, COL_A, ROW_B, COL_B, ROW_C, COL_C, first_task_arr);

	Unique_Arr_Val(A, B, C, ROW_A, COL_A, ROW_B, COL_B, ROW_C, COL_C, second_task_arr);

	Comm_Arr_Val(A, C, ROW_A, COL_A, ROW_C, COL_C, third_task_arr);

	Comm_Arr_Negative_Val(A, B, C, ROW_A, COL_A, ROW_B, COL_B, ROW_C, COL_C, fourth_task_arr);
	
	


	cout << "\nВывод одномерного массива, который содержит общие значения для A, B, C\n";	   
	Show_Arr_1D(first_task_arr, 30);

	cout << "\nВывод одномерного массива, который содержит уникальные значения для A, B, C\n";
	Show_Arr_1D(second_task_arr, 30);

	cout << "\nВывод одномерного массива, который содержит общие значения для A и C\n";
	Show_Arr_1D(third_task_arr, 30);

	cout << "\nВывод одномерного массива, который содержит отрицательные значения для A, B, C без повторений.\n";  
	Show_Arr_1D(fourth_task_arr, 30);


	for (int i = 0; i < ROW_A; i++)
		delete[] A[i];
	delete[] A;

	for (int i = 0; i < ROW_B; i++)
		delete[] B[i];
	delete[] B;

	for (int i = 0; i < ROW_C; i++)
		delete[] C[i];
	delete[] C;

	delete[] first_task_arr;
	delete[] second_task_arr;
	delete[] third_task_arr;
	delete[] fourth_task_arr;

	return 0;
}
		

int** Init_Arr(int ROW, int COL) 
{
	int** tmp = new int* [ROW]();

	for (int i = 0; i < ROW; i++)
		tmp[i] = new int[COL]();

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << "Введите значения в массив данных: ";
			cin >> tmp[i][j];
		}
	}
	return tmp;
}

void Show_Arr_1D(int* arr, int size) 
{
	for (int i = 0; i < size; i++) {
		if(arr[i] != 0)
			cout << arr[i] << " ";
	}

	cout << endl;

	return;
}

void Show_Arr_2D(int** arr, int ROW, int COL) 
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void Sort_Arr(int* arr, int ROW) 
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 1; j < ROW; j++) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
	return;
}

int* Arr_2D_To_1D (int** arr, int ROW, int COL) 
{
	int* temp = new int[ROW * COL]();

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp[i * COL + j] = arr[i][j];
		}
	}
	return temp;
}

int* Merge_Arrs(int* arr1, int* arr2, int* arr3, int ROW_A, int ROW_B, int ROW_C) 
{
	int* tmp_arr = new int[(ROW_A + ROW_B + ROW_C)]();

	for (int i = 0; i < ROW_A; i++) {
		tmp_arr[i] = arr1[i];
	}

	for (int i = ROW_A; i < ROW_A + ROW_B; i++) {
		tmp_arr[i] = arr2[i - ROW_A];
	}

	for (int i = ROW_A + ROW_B; i < ROW_A + ROW_B + ROW_C; i++) {
		tmp_arr[i] = arr3[i -  (ROW_A + ROW_B)];
	}

	return tmp_arr;
}

int* Find_Unique(int* arr, int& size) 
{
	int* tmp_arr = new int[size]();

	for (int i = 0; i < size; i++) {
		int not_uniq = 0;

		for (int j = 0; j < i; j++) { 
			if (arr[i] == arr[j])
				not_uniq++;
		}

		for (int k = i + 1; k < size; k++) {
			if (arr[i] == arr[k])
				not_uniq++;
		}

		if (not_uniq == 0)
			tmp_arr[i] = arr[i];
	}

	return tmp_arr;
}

void Comm_Arr_Val(int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr) 
{	
	int* tmp_arr1 = Arr_2D_To_1D(arr_1th, ROW_A, COL_A);
	int* tmp_arr2 = Arr_2D_To_1D(arr_2th, ROW_B, COL_B);
	int* tmp_arr3 = Arr_2D_To_1D(arr_3th, ROW_C, COL_C);

	int arr1_size = ROW_A * COL_A;
	int arr2_size = ROW_B * COL_B;
	int arr3_size = ROW_C * COL_C;

	Sort_Arr(tmp_arr1, arr1_size);
	Sort_Arr(tmp_arr2, arr2_size);
	Sort_Arr(tmp_arr3, arr3_size);

	int i = 0, j = 0, k = 0;

	while (i < arr1_size && j < arr2_size && k < arr3_size) {

		if (tmp_arr1[i] == tmp_arr2[j] && tmp_arr2[j] == tmp_arr3[k]) {
			arr[i] = tmp_arr1[i];
			i++; j++; k++;
		}

		else if (tmp_arr1[i] < tmp_arr2[j])
			i++;

		else if (tmp_arr2[j] < tmp_arr3[k])
			j++;

		else
			k++;
	}
	return;
}

void Comm_Arr_Negative_Val(int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr) 
{
	int* tmp_arr1 = Arr_2D_To_1D(arr_1th, ROW_A, COL_A);
	int* tmp_arr2 = Arr_2D_To_1D(arr_2th, ROW_B, COL_B);
	int* tmp_arr3 = Arr_2D_To_1D(arr_3th, ROW_C, COL_C);

	int arr1_size = ROW_A * COL_A;
	int arr2_size = ROW_B * COL_B;
	int arr3_size = ROW_C * COL_C;

	Sort_Arr(tmp_arr1, arr1_size);
	Sort_Arr(tmp_arr2, arr2_size);
	Sort_Arr(tmp_arr3, arr3_size);

	int i = 0, j = 0, k = 0;

	while (i < arr1_size && j < arr2_size && k < arr3_size) {

		if (tmp_arr1[i] == tmp_arr2[j] && tmp_arr2[j] == tmp_arr3[k]) {
			if(tmp_arr1[i] < 0)
				arr[i] = tmp_arr1[i];

			i++; j++; k++;
		}

		else if (tmp_arr1[i] < tmp_arr2[j])
			i++;

		else if (tmp_arr2[j] < tmp_arr3[k])
			j++;

		else
			k++;
	}
	return;
}

void Comm_Arr_Val(int** arr_1th, int** arr_3th, int ROW_A, int COL_A, int ROW_C, int COL_C, int* arr) 
{
	int* tmp_arr1 = Arr_2D_To_1D(arr_1th, ROW_A, COL_A);
	int* tmp_arr3 = Arr_2D_To_1D(arr_3th, ROW_C, COL_C);

	int arr1_size = ROW_A * COL_A;
	int arr3_size = ROW_C * COL_C;

	Sort_Arr(tmp_arr1, arr1_size);
	Sort_Arr(tmp_arr3, arr3_size);

	int i = 0, j = 0;

	while (i < arr1_size && j < arr3_size) {

		if (tmp_arr1[i] == tmp_arr3[j]) {
			arr[i] = tmp_arr1[i];
			i++; j++;
		}

		else if (tmp_arr1[i] < tmp_arr3[j])
			i++;

		else
			j++;
	}

	return;
}

void Unique_Arr_Val (int** arr_1th, int** arr_2th, int** arr_3th, int ROW_A, int COL_A, int ROW_B, int COL_B, int ROW_C, int COL_C, int* arr) 
{
	int* tmp_arr1 = Arr_2D_To_1D(arr_1th, ROW_A, COL_A);
	int* tmp_arr2 = Arr_2D_To_1D(arr_2th, ROW_B, COL_B);
	int* tmp_arr3 = Arr_2D_To_1D(arr_3th, ROW_C, COL_C);

	int arr1_size = ROW_A * COL_A;
	int arr2_size = ROW_B * COL_B;
	int arr3_size = ROW_C * COL_C;

	int* tmp_3arr = Merge_Arrs(tmp_arr1, tmp_arr2, tmp_arr3, arr1_size, arr2_size, arr3_size);
	int tmp_3arr_size = arr1_size + arr2_size + arr3_size;

	tmp_3arr = Find_Unique(tmp_3arr, tmp_3arr_size);
	
	for (int i = 0; i < tmp_3arr_size; i++) {
		if (tmp_3arr[i] != 0) {
			arr[i] = tmp_3arr[i];
		}
	}

	return;

}