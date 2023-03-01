/*Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер,
у каждого из которых есть свой приоритет. 
Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди. 
Предусмотреть вывод статистики на экран.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
using namespace std;

class LogQueue
{
	string* _printLog;
	int MaxQueueLength;
	int QueueLength;  

public:

	LogQueue(int size)
	{
		MaxQueueLength = size;
		_printLog = new string[MaxQueueLength];
		QueueLength = 0;
	}

	~LogQueue() { delete[] _printLog; }

	void Show()
	{
		cout << "\tЛоги сотрудников\n"
		<< "\n-----------------------------------\n";

		for (int i = 0; i < QueueLength; i++)
			cout << _printLog[i] << endl;

		return;
	}

	void Clear() { QueueLength = 0; }

	bool IsEmpty() { return QueueLength == 0; }

	bool IsFull() {	return QueueLength == MaxQueueLength; }

	int GetCount() { return QueueLength; }

	void Add(string log)
	{
		if (!IsFull())
			_printLog[QueueLength++] = log;

		return;
	}
};
 

class PrintQueue
{
	enum PRIORITY { LOW, MEDIUM, HIGH, MEGAHIGH };

	string* _print_wait;
	int* _priority;
	string* _work_pos;

	int _maxQueueLength;
	int _queueLength;

	string _curr_print;
	int _timer = 5;


public:
	PrintQueue(int size)
	{
		_maxQueueLength = size;

		_print_wait = new string[_maxQueueLength];
		_priority = new int[_maxQueueLength];
		_work_pos = new string[_maxQueueLength];

		_queueLength = 0;
 	}


	~PrintQueue()
	{
		delete[]_print_wait;
		delete[]_priority;
		delete[]_work_pos;
	}

	void PrintOrder()
	{
		system("cls");

		cout << "\tОчередь на печать\n"
			<< "\n-----------------------------------\n";

		for (int i = 0; i < _queueLength; i++)
			cout << _print_wait[i] << " - " << _work_pos[i] << "\n\n";

		return;
	}

	void PrintCurrentElement()
	{
		if (_timer != 0)
			_timer -= 1;


		cout << "\tПечать документа\n"
			<< "\n-----------------------------------\n";

		(_timer != 0) ?
			cout << getCurrentPrint() << " " << _timer << "\n\n" : cout << endl;


		if (!IsEmpty() && _timer == 0)
			Extract();

		return;
	}

	void Clear() { _queueLength = 0; }

	bool IsEmpty() { return _queueLength == 0; }

	bool IsFull() {	return _queueLength == _maxQueueLength; }

	int GetCount() { return _queueLength; }

	void Add(string c, string p)
	{
		if (!IsFull()) {
			_print_wait[_queueLength] = c;

			if (p == "Admin")
				_priority[_queueLength] = MEGAHIGH;
			else if (p == "Secretary")
				_priority[_queueLength] = HIGH;
			else if (p == "Quartermaster")
				_priority[_queueLength] = MEDIUM;
			else
				_priority[_queueLength] = LOW;

			_work_pos[_queueLength] = p;

			_queueLength++;
		}
	}

	string getCurrentPrint()
	{
		int max_pri = _priority[0];
		int pos_max_pri = 0;
		for (int i = 1; i < _queueLength; i++) {
			if (max_pri < _priority[i]) {
				max_pri = _priority[i];
				pos_max_pri = i;
			}
		}

		return _print_wait[pos_max_pri] + " - " + _work_pos[pos_max_pri];
	}

	void Extract()
	{
		if (!IsEmpty()) {
			int max_pri = _priority[0];
			int pos_max_pri = 0;

			for (int i = 1; i < _queueLength; i++) {
				if (max_pri < _priority[i]) {
					max_pri = _priority[i];
					pos_max_pri = i;
				}
			}
			
			for (int i = pos_max_pri; i < _queueLength - 1; i++) {
				_print_wait[i] = _print_wait[i + 1];
				_priority[i] = _priority[i + 1];
				_work_pos[i] = _work_pos[i + 1];
			}
		}

		_queueLength--;
		_timer = 5;

		return;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	srand(time(NULL));
	time_t curr_time;

	PrintQueue PS(25);
	LogQueue LOG(25);

	string docs[]{ "budget.doc", "photo_1.jpg", "logs.txt", "report.ppt" };
	string priority[]{ "Admin", "Secretary", "Quartermaster", "Clerk" };

	for(int i = 0; i < 8; i++)
		PS.Add(docs[rand() % 4], priority[rand() % 4]);

	for(int timer = 0; timer < 60 * 24; timer++) 
	{

		PS.PrintOrder();
		PS.PrintCurrentElement();

		if (timer % 5 == 0) {
			curr_time = time(NULL);
			LOG.Add(PS.getCurrentPrint() + " | " += asctime(localtime(&curr_time)));
		}

		LOG.Show();

		Sleep(1000);
	}

	return 0;
}