#include "phonebook.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* phonebook_file = nullptr;

	const char* path = R"(C:\Users\Evgeniy\Desktop\putfile.txt)";

	FILE* enter_file = nullptr;

	char enter_path[100];

	//const char* enter_path = R"(C:\Users\Evgeniy\Desktop\putfile.txt)";

	int phonebook_size = 0;
	Phonebook* phonebook = new Phonebook[phonebook_size]();

	int answer = 0, subscriber_num;

	char tmp_subscriber_name[128];

	bool skip_EnterFile = false;

	if (!skip_EnterFile) {
		cout << "Хотите загрузить данные сотрудников из файла?[0 - Нет/1 - Да]: ";
		cin >> skip_EnterFile;
		cout << endl;
	}

	if (skip_EnterFile) {
		cout << "Введите путь к файлу, из которого нужно загрузить данные\n> ";
		cin >> enter_path;
		cout << endl;


		if ((fopen_s(&enter_file, enter_path, "r")) != NULL)
			cout << "Файл не существует!\n\n";

		else {
			while (!feof(enter_file))
				read_From_File(phonebook, phonebook_size, enter_file);

			cout << "\n\tДанные загружены из файла\n\n\n";
			fclose(enter_file);
		}
	}

	do {
		answer = menu();
		switch (answer) {
		case 0:
			if ((fopen_s(&phonebook_file, path, "w")) != NULL)
				cout << "This file is not exist!";

			else {
				for (int i = 0; i < phonebook_size; i++)
					phonebook[i].write_In_File(phonebook_file);

				cout << "\n\tИзменения сохранены\n" << endl;
				fclose(phonebook_file);
			}
			break;

		case 1:
			cout << "\tДобавление нового абонента" << endl;
			add_Subscriber(phonebook, phonebook_size);
			cout << endl;
			break;

		case 2:
			subscriber_num = subscriber_number();
			delete_Subscriber(phonebook, subscriber_num, phonebook_size);
			cout << "\tУдаление абонента #" << subscriber_num << " выполнено" << endl;

			cout << endl;
			break;

		case 3:
			cout << "\n\tПоиск Абонента\n";
			cout << "Укажите имя для поиска абонента: ";
			cin.ignore();
			cin.getline(tmp_subscriber_name, 128, '\n');

			cout << endl;
			
			find_Subscriber(phonebook, tmp_subscriber_name, phonebook_size);
			
			cout << endl;
			break;

		case 4:
			cout << "\n\tСписок абонентов\n";

			for (int i = 0; i < phonebook_size; i++) {
				cout << "\nАбонент #" << i + 1 << endl;
				phonebook[i].print();
			}

			cout << endl;
			break;

		default:
			break;
		}
	} while (answer != 0);

	return 0;
}