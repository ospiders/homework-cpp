#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
using namespace std;

class PrintTask
{
	enum PRIORITY { LOW, MEDIUM, HIGH, MEGAHIGH };

	string _department;
	string _printTime;
	string _priority;
	int _time_count = -1;

public:

	PrintTask(string dep, string time, int timer) : _department(dep), _printTime(time), _time_count(timer)
	{
		if (dep == "Admin")
			_priority = MEGAHIGH;
		else if (dep == "Secretary")
			_priority = HIGH;
		else if (dep == "Quartermaster")
			_priority = MEDIUM;
		else
			_priority = LOW;
	}
	PrintTask() {}

	int PrintTask::getTimePrint() { return timePrint; }

	inline void PrintTask::setTimePrint(int t) { timePrint = t; }

	friend ostream& operator <<(ostream& out, const PrintTask& obj);
};

ostream& operator<<(ostream& out, const PrintTask& obj)
{
	out << left << setw(19) << obj.fileName << setw(15) << obj.department << setw(5) << obj.timePrint;
	return out;
}


class QueuePriority
{
	int* Wait;
	int* Pri;
	int MaxQueueLength;
	int QueueLength;
public:

	QueuePriority(int m);
	~QueuePriority();

	void Add(int c, int p);
	int Extract();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();
};

void QueuePriority::Show() {
	cout << "\n-----------------------------------\n";

	for (int i = 0; i < QueueLength; i++)
		cout << Wait[i] << " - " << Pri[i] << "\n\n";

	cout << "\n-----------------------------------\n";
}

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	MaxQueueLength = m;

	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];

	QueueLength = 0;
}

void QueuePriority::Clear()
{
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
	if (!IsFull()) {
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	if (!IsEmpty()) {
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++)
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
		return temp1;
	}
	else return -1;
}