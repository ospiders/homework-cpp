#include "phonebook.h"


void Phonebook::remove()
{
	if (_p_full_name != nullptr)
		_p_full_name = nullptr;

	if (_p_addition_information != nullptr)
		_p_addition_information = nullptr;
}


Phonebook::Phonebook(char* &f_name, long long h_phone, long long w_phone, long long m_phone, char* &addit_info) 
	: _p_full_name{ f_name }, _home_phone{h_phone}, _work_phone{w_phone},
	_mobile_phone{ m_phone }, _p_addition_information{ addit_info} {}

Phonebook::~Phonebook() { remove(); }


char* Phonebook::get_Full_Name() { return _p_full_name; }
long long Phonebook::get_Home_Phone() { return _home_phone; }
long long Phonebook::get_Work_Phone() { return _work_phone; }
long long Phonebook::get_Mobile_Phone() { return _mobile_phone; }
char* Phonebook::get_Addition_Information() { return _p_addition_information; }

void Phonebook::set_Full_Name(char* f_name) { deep_Array_Copy(_p_full_name, f_name); }
void Phonebook::set_Home_Phone(long long home_ph) { _home_phone = home_ph; }
void Phonebook::set_Work_Phone(long long work_ph) { _work_phone = work_ph; }
void Phonebook::set_Mobile_Phone(long long mobile_ph) { _mobile_phone = mobile_ph; }
void Phonebook::set_Addition_Information(char* addit_info) { deep_Array_Copy(_p_addition_information, addit_info); }


void Phonebook::read()
{
	char tmp_name[128];
	char tmp_info[128];

	cout << "Укажите ФИО абонента: ";
	cin.ignore();
	cin.getline(tmp_name, 128, '\n');
	deep_Array_Copy(_p_full_name, tmp_name);

	cout << "Укажите домашний телефон: ";
	cin >> _home_phone;

	cout << "Укажите рабочий телефон: ";
	cin >> _work_phone;

	cout << "Укажите мобильный телефон: ";
	cin >> _mobile_phone;

	cout << "Укажите дополнительную информацию: ";
	cin.ignore();
	cin.getline(tmp_info, 128, '\n');
	deep_Array_Copy(_p_addition_information, tmp_info);

	cout << endl;

	return;
}

void Phonebook::print()
{
	cout << "ФИО абонента: " << _p_full_name << endl
		<< "Домашний телефон: " << _home_phone << endl
		<< "Рабочий телефон: " << _work_phone << endl
		<< "Мобильный телефон: " << _mobile_phone << endl
		<< "Дополнительная информация: " << _p_addition_information << endl;

	return;
}

void Phonebook::write_In_File(FILE* file)
{
	if(_p_full_name != " ")
		fprintf(file, "%s\n%lld\n%lld\n%lld\n%s\n", _p_full_name, _home_phone, _work_phone, _mobile_phone, _p_addition_information);

	return;
}

void Phonebook::deep_Array_Copy(char*& dest, const char* source)
{
	int strSize = strlen(source) + 1;
	dest = new char[strSize];
	strcpy_s(dest, strSize, source);
}

//////////////////////

void add_Subscriber(Phonebook*& sub, int& size)
{
	Phonebook* tmp_sub = new Phonebook[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_sub[i] = sub[i];

	tmp_sub[size].read();

	delete[] sub;

	sub = tmp_sub;

	size += 1;
	return;
}

void delete_Subscriber(Phonebook*& sub, int key, int& size)
{
	for (int i = 0; i < size; i++) {
		if (i == key - 1) {
			for (int j = i; j < size - 1; j++)
				swap(sub[j], sub[j + 1]);

			size--;
			break;
		}
	}
	return;
}

void find_Subscriber(Phonebook*& sub, char* key, int size)
{
	cout << key << endl;
	bool isEqual = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen(key); j++) {
			if (sub[i].get_Full_Name()[j] == key[j])
				isEqual = true;

			else {
				isEqual = false;
				break;
			}
		}

		if (isEqual) {
			cout << "Абонент #" << i + 1 << endl;
			sub[i].print();
			isEqual = false;
		}
	}
	return;
}

void read_From_File(Phonebook*& sub, int& size, FILE* file)
{
	Phonebook* tmp_sub = new Phonebook[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_sub[i] = sub[i];

	char tmp_name[128]{0};
	long long tmp_home_ph = 0;
	long long tmp_work_ph = 0;
	long long tmp_mobile_ph = 0;
	char tmp_addit_info[128]{0};

	fscanf_s(file, "%[^\n]\n", tmp_name, sizeof(tmp_name));
	fscanf_s(file, "%lld\n", &tmp_home_ph);
	fscanf_s(file, "%lld\n", &tmp_work_ph);
	fscanf_s(file, "%lld\n", &tmp_mobile_ph);
	fscanf_s(file, "%[^\n]\n", tmp_addit_info, sizeof(tmp_addit_info));


	tmp_sub[size].set_Full_Name(tmp_name);
	tmp_sub[size].set_Home_Phone(tmp_home_ph);
	tmp_sub[size].set_Work_Phone(tmp_work_ph);
	tmp_sub[size].set_Mobile_Phone(tmp_mobile_ph);
	tmp_sub[size].set_Addition_Information(tmp_addit_info);


	delete[] sub;
	sub = tmp_sub;

	size += 1;

	return;
}

int menu()
{
	int answer;
	cout << "\tТелефонная книга\n"
		<< "1 - Добавить нового абонента\n"
		<< "2 - Удаление абонента\n"
		<< "3 - Поиск абонента по ФИО\n"
		<< "4 - Показать всех абонентов\n"
		<< "0 - Выход из программы\n> ";
	cin >> answer;

	cout << endl;
	return answer;
}

int subscriber_number()
{
	int answer;
	cout << "\n\tВыберите номер абонента для редактирования: ";
	cin >> answer;

	cout << endl;
	return answer;
}