#pragma once
#include <windows.h>
#include<iostream>
using namespace std;

class Phonebook
{
private:

	char* _p_full_name;
	long long _home_phone;
	long long _work_phone;
	long long _mobile_phone;
	char* _p_addition_information;

	void remove();
	
public:
	
	Phonebook(char* &f_name, long long h_phone, long long w_phone, long long m_phone, char* &addit_info);

	~Phonebook();

	Phonebook() = default;


	char* get_Full_Name();
	long long get_Home_Phone();
	long long get_Work_Phone();
	long long get_Mobile_Phone();
	char* get_Addition_Information();

	void set_Full_Name(char* f_name);
	void set_Home_Phone(long long home_ph);
	void set_Work_Phone(long long work_ph);
	void set_Mobile_Phone(long long mobile_ph);
	void set_Addition_Information(char* addit_info);

	
	void read();

	void print();
	
	void write_In_File(FILE* file);

	void deep_Array_Copy(char*& dest, const char* source);
};

void add_Subscriber(Phonebook*& sub, int& size);

void delete_Subscriber(Phonebook*& sub, int key, int& size);

void find_Subscriber(Phonebook*& sub, char* key, int size);

void read_From_File(Phonebook*& sub, int& size, FILE* file);

int menu();

int subscriber_number();