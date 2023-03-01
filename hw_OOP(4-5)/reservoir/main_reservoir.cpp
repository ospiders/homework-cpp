#include "Reservoir.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int menu_choice = 0, key_choice1 = 0, key_choice2 = 0;

	int reservoirs_count = 0;	
	Reservoir* reservoirs = new Reservoir[reservoirs_count]();

	FILE* reservoir_file = nullptr;
	const char* path = R"(C:\Users\Evgeniy\Desktop\reservoirfile.txt)";

	FILE* enter_file = nullptr;
	const char* enter_path = R"(C:\Users\Evgeniy\Desktop\reservoirfile.txt)";

	if ((fopen_s(&enter_file, enter_path, "r")) != NULL)
		cout << "This file is not exist!";

	else {
		while (!feof(enter_file))
			read_From_File(reservoirs, reservoirs_count, enter_file);

		cout << "\n\tДанные загружены из файла\n\n";
		fclose(enter_file);
	}

	do {
		menu_choice = menu();

		switch (menu_choice) {
		case 0:
			if ((fopen_s(&reservoir_file, path, "w")) != NULL)
				cout << "This file is not exist!";

			else {
				for (int i = 0; i < reservoirs_count; i++)
					reservoirs[i].write_In_File(reservoir_file);

				cout << "\tИзменения сохранены\n" << endl;
				fclose(reservoir_file);
			}

			cout << "\n\tВыход!\n";
			break;

		case 1:
			cout << "\tДобавить новый резервуар\n\n";

			add_Reservoir(reservoirs, reservoirs_count);

			cout << endl;
			break;

		case 2:
			cout << "\tУдалить резервуар\n\n";

			cout << "Выведите номер резервуара, который хотите удалить: ";
			cin >> key_choice1;

			remove_Reservoir(reservoirs, key_choice1, reservoirs_count);

			cout << endl;
			break;

		case 3:
			cout << "\tСписок резервуаров\n\n";

			for (int i = 0; i < reservoirs_count; i++) {
				cout << "Резервуар #" << i + 1 << endl;
				reservoirs[i].print();
			}

			cout << endl;
		break;

		case 4:
			cout << "\tСравнение резервуаров\n\n";

			cout << "Введите номер резервуара: ";
			cin >> key_choice1;
			cout << "Введите номер резервуара, с которым хотите сравнить: ";
			cin >> key_choice2;
			cout << endl;

			compare_Reservoir(reservoirs, key_choice1, key_choice2, reservoirs_count);

			cout << endl;
			break;

		default:
			break;
		}
	} while (menu_choice != 0);

	return 0;
}