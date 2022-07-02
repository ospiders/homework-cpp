/*
a) в функции main вызвать все функции через переозначеные 
(обобщенные) имена из файла function.h (show());
b) определить константу, котора€ указывает какой тип 
данных будет использоватьс€. Ќапример INTEGER Ч 
целые данные, CHAR Ч символьные DOUBLE Ч 
насто€щие (#define INTEGER).*/

#include <iostream>
//#define INTEGER int
//#define DOUBLE double
#define CHAR char

#include "function.h"


int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	//int arr1[10];
	//double arr1[10];	
	char arr1[10];

	Fill_Random_Values(arr1, 10);
	Show_Array(arr1, 10);
	Find_Min_Max_Value(arr1, 10);
	Sort_Arr(arr1, 10);
	Show_Array(arr1, 10);
	Replace_Value_In_Arr(arr1, 10);
	Show_Array(arr1, 10);
	
	return 0;
}