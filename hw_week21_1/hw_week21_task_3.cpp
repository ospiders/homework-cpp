/* Шифр Цезаря — один из древнейших шифров. 
При шифровании каждый символ заменяется другим, 
отстоящим от него в алфавите на фиксированное число 
позиций. Ключ = 3*/
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* file2;

	const char* path2 = R"(C:\Users\Evgeniy\Desktop\putfile.txt)";

	char arr1[] = "Съешь же ещё этих мягких французских булок, да выпей чаю.";
	cout << arr1 << endl;

	const int key = 3;

	for (int i = 0; i < strlen(arr1); i++) {
		if (arr1[i] == 'г')
			arr1[i] = 'ё';

		else if (arr1[i] == 'Г')
			arr1[i] = 'Ё';

		else if (arr1[i] == 'ё')
			arr1[i] = 'и';

		else if (arr1[i] == 'Ё')
			arr1[i] = 'И';

		else if (arr1[i] >= 'д' && arr1[i] <= 'е')
			arr1[i] += key - 1;

		else if (arr1[i] >= 'Д' && arr1[i] <= 'Е')
			arr1[i] += key - 1;

		else if (arr1[i] >= 'а' && arr1[i] <= 'я') {
			arr1[i] += key;

			if (arr1[i] > 'я')
				arr1[i] += 'а';
		}

		else if (arr1[i] >= 'А' && arr1[i] <= 'Я') {
			arr1[i] += key;

			if (arr1[i] > 'Я')
				arr1[i] += 'А';
		}
	}

	cout << arr1 << endl;



	if ((fopen_s(&file2, path2, "w")) != NULL)
		cout << "This file is not exist!";

	else {
		fprintf(file2, "Зашифрованное сообщение: "); fprintf(file2, "%s", arr1);

		fclose(file2);
	}
	cout << "\n\n\t Шифр успешно записан в файл" << endl;

	return 0;

}