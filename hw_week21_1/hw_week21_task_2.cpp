/*  Дан текстовый файл. Необходимо создать 
новый файл и записать в него следующую статистику по 
исходному файлу:
■ Количество символов;
■ Количество строк;
■ Количество гласных букв;
■ Количество согласных букв;
■ Количество цифр.*/
#include <iostream>
using namespace std;

bool is_vowel(char symbol);

int main() {
	setlocale(LC_ALL, "");

	FILE* file1;
	FILE* file2;

	const char* path1 = R"(C:\Users\Evgeniy\Desktop\outfile.txt)";
	const char* path2 = R"(C:\Users\Evgeniy\Desktop\putfile.txt)";

	char arr1[128];

	int symbol_count = 0;
	int row_count = 0;
	int vowel_count = 0;
	int consonant_count = 0;
	int number_count = 0;
	int num_of_char;

	cout << "Программа для записи в файл #2 статистики символов, строк, гласных и согласных букв, цифр файла #1.\n" << endl;

	if ((fopen_s(&file1, path1, "r")) != NULL)
		cout << "This file is not exist!";

	else {
		while (!feof(file1)) {
			fgets(arr1, 127, file1);

			for (int i = 0; i < strlen(arr1); i++) {
				if (arr1[i] != '\n')
					symbol_count++;
				if (arr1[i] == '\n')
					row_count++;
				if (is_vowel(arr1[i]))
					vowel_count++;
				if (!is_vowel(arr1[i]))
					consonant_count++;
				if (arr1[i] >= '0' && arr1[i] <= '9')
					number_count++;
			}
		}
		fclose(file1);
	}
	
	//спросить у пользователя нужно ли записать в файл?
	cout << "\tСтатистика по файлу #1 собрана.\n" << endl;


	if ((fopen_s(&file2, path2, "w")) != NULL)
		cout << "This file is not exist!";

	else {
		fprintf(file2, "Количество символов: "); fprintf(file2, "%i", symbol_count);
		fprintf(file2, "\nКоличество строк: "); fprintf(file2, "%i", row_count);
		fprintf(file2, "\nКоличество гласных букв: "); fprintf(file2, "%i", vowel_count);
		fprintf(file2, "\nКоличество согласных букв: "); fprintf(file2, "%i", consonant_count);
		fprintf(file2, "\nКоличество цифр: "); fprintf(file2, "%i", number_count);
		
		fclose(file2);
	}

	cout << "\tСтатистика успешно записана в файл #2" << endl;

	return 0;
}


bool is_vowel(char symbol)
{
	bool find_vowel = false;
	char vowel[12] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y' };
	for (int i = 0; i < 12; i++) {
		if (symbol == vowel[i]) {
			find_vowel = true;
			break;
		}
	}
	return find_vowel;
}