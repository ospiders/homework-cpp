/*Создайте шаблонный класс матрица. Необходимо реализовать динамическое выделение памяти, очистку памяти, 
заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические 
операции с помощью перегруженных операторов (+, –, *, /), поиск максимального и минимального элемента. */
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Matrix {

	T** _p_matrix;
	int _ROW;
	int _COL;

public:

	Matrix(int ROW, int COL) : _ROW{ ROW }, _COL{ COL }, _p_matrix{ new T*[ROW]()}
	{
		for (int i = 0; i < _ROW; i++)
			_p_matrix[i] = new T[_COL]();
	}

	Matrix() : Matrix(3, 3) { }

	~Matrix() { clear(); }

	void clear()
	{	
		for (int i = 0; i < _ROW; i++)
			delete[]_p_matrix[i];

		delete[]_p_matrix;
	}

	void print()
	{
		for (int i =  0; i < _ROW; i++) {
			for (int j = 0; j < _COL; j++)
				cout << left << setw(3) << _p_matrix[i][j] << " ";

			cout << endl;
		}
		cout << endl;

		return;
	}

	void read()
	{
		for (int i = 0; i < _ROW; i++) {
			for (int j = 0; j < _COL; j++) {
				print();
				cout << "Введите значение: ";
				cin >> _p_matrix[i][j];

				system("cls");
			}
		}
		print();

		return;
	}

	void matrix_Random()
	{
		for (int i = 0; i < _ROW; i++) 
			for (int j = 0; j < _COL; j++)
				_p_matrix[i][j] = rand() % 10;

		return;
	}

	T find_Max()
	{
		T tmp = _p_matrix[0][0];

		for (int i = 0; i < _ROW; i++) {
			for (int j = 0; j < _COL;)
				(tmp > _p_matrix[i][j]) ? j++ : tmp = _p_matrix[i][j++];
		}
		return tmp;
	}

	T find_Min()
	{
		T tmp = _p_matrix[0][0];

		for (int i = 0; i < _ROW; i++) {
			for (int j = 0; j < _COL;)
				(tmp < _p_matrix[i][j]) ? j++ : tmp = _p_matrix[i][j++];
		}
		return tmp;
	}

	const Matrix& operator+ (const Matrix& object)
	{
		for (int i = 0; i < _ROW; i++) 
			for(int j =  0; j < _COL; j++) 
				_p_matrix[i][j] += object._p_matrix[i][j];

		return *this;
	}

	const Matrix& operator- (const Matrix& object)
	{
		for (int i = 0; i < _ROW; i++) 
			for (int j = 0; j < _COL; j++) 
				_p_matrix[i][j] -= object._p_matrix[i][j];

		return *this;
	}

	const Matrix& operator* (const Matrix& object)
	{
		for (int i = 0; i < _ROW; i++)
			for (int j = 0; j < _COL; j++)
				_p_matrix[i][j] *= object._p_matrix[i][j];

		return *this;
	}

	const Matrix& operator/ (const Matrix& object)
	{
		for (int i = 0; i < _ROW; i++)
			for (int j = 0; j < _COL; j++)
				_p_matrix[i][j] /= object._p_matrix[i][j];

		return *this;
	}
	
};

void Matrix<char>::matrix_Random()
{
	for (int i = 0; i < _ROW; i++)
		for (int j = 0; j < _COL; j++)
			_p_matrix[i][j] = 65 + (char)(rand() % (90 - 65 + 1));

	return;
}

void Matrix<double>::matrix_Random()
{
	for (int i = 0; i < _ROW; i++)
		for (int j = 0; j < _COL; j++)
			_p_matrix[i][j] = (double)(rand() % (10 * 10)) / 10.0;

	return;
}

void Matrix<double>::print()
{
	for (int i = 0; i < _ROW; i++) {
		for (int j = 0; j < _COL; j++)
			cout << left << setw(6) << _p_matrix[i][j] << " ";

		cout << endl;
	}
	cout << endl;

	return;
}


int main() {
	setlocale(LC_ALL, "");

	//Matrix<char> add;
	//Matrix<char> daa;

	//Matrix<int> add;
	//Matrix<int> daa;

	Matrix<double> add;
	Matrix<double> daa;

	add.matrix_Random();
	daa.matrix_Random();


	cout << "Первая матрица со значениями\n";
	add.print();
	cout << "Максимальное значение в матрице #1: " << add.find_Max() << endl 
		 << "Минимальное значение в матрице #1: " << add.find_Min() << endl << endl;

	cout << "Вторая матрица со значениями\n";
	daa.print();
	cout << "Максимальное значение в матрице #2: " << daa.find_Max() << endl
		<< "Минимальное значение в матрице #2: " << daa.find_Min() << endl << endl;


	add + daa;
	cout << "Прибавление значений матрицы #1 к значениям в матрице #2\n";
	add.print();

	add - daa;
	cout << "Вычитание из значений матрицы #1 значений матрицы #2\n";
	add.print();

	add * daa;
	cout << "Умножение значений матрицы #1 на значения матрицы #2\n";
	add.print();

	add / daa;
	cout << "Деление значений из матрицы #1 на значения в матрице #2\n";
	add.print();


	return 0;
}