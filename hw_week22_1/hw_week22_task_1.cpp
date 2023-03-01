/* �������� �������������� ������� �����������. 
��������� ������ ������������ ���� ������, 
�������������� ������ ����������, �������� ����������, 
����� ���������� �� �������, ����� ���������� ��� 
���� �����������, ���������� ��������, ��� ������� 
������� ���������� �� ��������� �����. ����������� 
����������� ���������� ��������� ���������� � ����. 
����� ���� ������ ����������� ����������� � ���� 
(��� ������ �� ��������� � �������������, � 
�������� ���������� ��������� � �� ������� ������������). 
��� ������ ��������� ���������� �������� ������ �����������
�� ���������� ������������� �����.*/

#include <iostream>
#include <windows.h>
using namespace std;

struct Employee {
	char firstname[40] {0};
	char lastname[40] {0};
	int age;
	
	explicit Employee(char f_name, char l_name, int num) : firstname{f_name}, lastname{l_name}, age{num} {}

	explicit Employee() : Employee{' ', ' ', 0} {}

	~Employee() {}

	void read()
	{
		cout << "\n������� ��� ����������: ";
		cin >> firstname;
		cout << "������� ������� ����������: ";
		cin >> lastname;
		cout << "������� ������� ����������: ";
		cin >> age;
		
		return;
	}

	void write_in_file(FILE* file)
	{
		if (firstname != " ")
			fprintf(file, "%s %s %d\n", firstname, lastname, age);

		return;
	}

	void print()
	{
		cout << "���: " << firstname << endl
			<< "�������: " << lastname << endl
			<< "�������: " << age << endl;
		cout << endl;
		return;
	}
};


int menu();

int employee_number();

char* employee_lastname();

int add_employee(Employee*& worker, int size);

int delete_employee(Employee*& worker, int key, int size);

void find_employee(Employee*& worker, char* key, int size);

int read_from_file(Employee*& worker, int size, FILE* file);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* workers_file = nullptr;

	const char* path = R"(C:\Users\Evgeniy\Desktop\putfile1.txt)";

	FILE* enter_file = nullptr;

	char enter_path[100];

	int employee_amount = 0;
	Employee* workers = new Employee[employee_amount]();

	bool skipEnterFile = false;
	int answer, employee_num;
	char* tmp_lastname;
	
	if (!skipEnterFile) {
		cout << "������ ��������� ������ ����������� �� �����?[0 - ���/1 - ��]: ";
		cin >> skipEnterFile;
		cout << endl;
	}

	if (skipEnterFile) {
		cout << "������� ���� � �����, �� �������� ����� ��������� ������\n> ";
		cin >> enter_path;
		cout << endl;


		if ((fopen_s(&enter_file, enter_path, "r")) != NULL)
			cout << "This file is not exist!";

		else {
			while (!feof(enter_file))
				employee_amount = read_from_file(workers, employee_amount, enter_file);

			cout << "\n\t������ ��������� �� �����\n\n";
			fclose(enter_file);
		}
	}

	do {
		
		answer = menu();

		switch (answer)
		{
		case 0:
			if ((fopen_s(&workers_file, path, "w")) != NULL)
				cout << "This file is not exist!";

			else {
				for (int i = 0; i < employee_amount; i++)
					workers[i].write_in_file(workers_file);

				cout << "\n\n\t��������� ���������\n" << endl;
				fclose(workers_file);
			}
			break;

		case 1:
			cout << "\t���������� ������ ����������" << endl;

			employee_amount = add_employee(workers, employee_amount);
			cout << endl;
			break;

		case 2:
			employee_num = employee_number();
			cout << "\t�������������� ���������� #" << employee_num << endl;

			workers[employee_num - 1].read();
			cout << endl;
			break;

		case 3:
			employee_num = employee_number();
			
			employee_amount = delete_employee(workers, employee_num, employee_amount);

			cout << "\t�������� ���������� #" << employee_num << " ���������" << endl;
			cout << endl;
			break;

		case 4:
			cout << "\n\t����� ���������� �� �������\n";
			tmp_lastname = employee_lastname();

			find_employee(workers, tmp_lastname, employee_amount);

			cout << endl;
			break;

		case 5:
			cout << "\n\t������ �����������\n";

			for (int i = 0; i < employee_amount; i++) {
				cout << "\n��������� #" << i + 1 << endl;
				workers[i].print();
			}

			cout << endl;
			break;

		case 6:
			if ((fopen_s(&workers_file, path, "w")) != NULL)
				cout << "This file is not exist!";

			else {
				for (int i = 0; i < employee_amount; i++)
					workers[i].write_in_file(workers_file);

				cout << "\n\n\t��������� ���������\n\n" << endl;
				fclose(workers_file);
			}
			break;

		default:
			break;
		}

	} while (answer != 0);

	return 0;
}

int menu()
{
	int answer;
	cout << "\t�������������� ������� ''����������''\n"
		<< "1 - ������ ������ ����������\n"
		<< "2 - �������������� ������ ����������\n"
		<< "3 - ������� ����������\n"
		<< "4 - ����� ���������� �� �������\n"
		<< "5 - ����� ���������� ��� ���� �����������\n"
		<< "6 - ��������� ���������� � �����������\n"
		<< "0 - ����� �� ���������\n> ";
	cin >> answer;

	cout << endl;
	return answer;
}

int employee_number() 
{
	int answer;
	cout << "\n\t�������� ����� �������� ��� ��������������: ";
	cin >> answer;

	cout << endl;
	return answer;
}

char* employee_lastname() 
{
	char tmp_lastname[40];
	cout << "������� ������� ��� ������ ����������: ";
	cin >> tmp_lastname; 

	cout << endl;
	return tmp_lastname;
}

int add_employee(Employee* &worker, int size)  
{
	Employee* tmp_worker = new Employee[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_worker[i] = worker[i];

	tmp_worker[size].read();

	delete[] worker;
	worker = tmp_worker;

	return size + 1;
}

int delete_employee(Employee*& worker, int key, int size) 
{
	for (int i = 0; i < size; i++) {
		if (i == key - 1) {
			for (int j = i; j < size - 1; j++)
				swap(worker[j], worker[j + 1]);

			size--;
			break;
		}
	}
	return size;
}

void find_employee(Employee*& worker, char* key, int size) 
{
	bool isEqual = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen(key); j++) {
			if (worker[i].lastname[j] == key[j])
				isEqual = true;

			else {
				isEqual = false;
				break;
			}
		}

		if (isEqual) {
			cout << "��������� #" << i + 1 << endl;
			worker[i].print();
			isEqual = false;
		}

	}
	return;
}

int read_from_file(Employee*& worker, int size, FILE* file)
{
	Employee* tmp_worker = new Employee[size + 1]();

	for (int i = 0; i < size; i++)
		tmp_worker[i] = worker[i];

	fscanf_s(file, "%s", tmp_worker[size].firstname, sizeof(tmp_worker[size].firstname));
	fscanf_s(file, "%s", &tmp_worker[size].lastname, sizeof(tmp_worker[size].lastname));
	fscanf_s(file, "%d\n", &tmp_worker[size].age);


	delete[] worker;
	worker = tmp_worker;

	return size + 1;
}