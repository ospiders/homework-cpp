/* Дано два текстовых файла. 
Выяснить, совпадают ли их строки.
Если нет, то вывести несовпадающую 
строку из каждого файла*/
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	FILE* file1;
	FILE* file2;

	const char* path1 = R"(C:\Users\Evgeniy\Desktop\outfile.txt)";
	const char* path2 = R"(C:\Users\Evgeniy\Desktop\putfile.txt)";

	char arr1[128];
	char arr2[128];

	bool isEqual = false;

	if (((fopen_s(&file1, path1, "r")) != NULL) || ((fopen_s(&file2, path2, "r")) != NULL))
		cout << "This file is not exist!";

	else {
		while (!feof(file1) || !feof(file2)) {
			fgets(arr1, 127, file1);
			fgets(arr2, 127, file2);

			if (arr1[strlen(arr1) - 1] == '\n')
				arr1[strlen(arr1) - 1] = '\0';

			if (arr2[strlen(arr2) - 1] == '\n')
				arr2[strlen(arr2) - 1] = '\0';

			if (strlen(arr1) == strlen(arr2)) {
				for (int j = 0; j < strlen(arr1); j++) {
					if (arr1[j] == arr2[j])
						isEqual = true;
					else
						isEqual = false;
				}
				if (!isEqual) {
					cout << "Строка из файла #1 " << '"' << arr1 << '"' << " не совпадает со строкой из файла #2 " << '"' << arr2 << '"' << endl;
					isEqual = true;
				}
			}
			else
				cout << "Строка из файла #1 " << '"' << arr1 << '"' << " не совпадает со строкой из файла #2 """ << '"' << arr2 << '"' << endl;
		}
		fclose(file1);
		fclose(file2);
	}

	return 0;
}