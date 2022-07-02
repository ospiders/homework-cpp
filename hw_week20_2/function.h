/*
a) описать прототипы всех функций;
b) сделать проверку определена ли константа, указывающая на тип данных (#ifdef INTEGER);
c) создать обобщающие имена функции, которым будет определена функция соответствующего типа в 
зависимости от константы, указанной в файле prog.
cpp (# define show ShowInt)*/
#pragma once

#ifdef INTEGER
void Fill_Random_ValuesInt(int arr[], int size);
void Show_ArrInt(int arr[], int size);
void Find_Min_Max_ValueInt(int arr[], int size);
void Sort_ArrInt(int arr[], int size);
void Replace_Value_In_ArrInt(int arr[], int size);

#define Fill_Random_Values Fill_Random_ValuesInt
#define Show_Array Show_ArrInt
#define Find_Min_Max_Value Find_Min_Max_ValueInt
#define Sort_Arr Sort_ArrInt
#define Replace_Value_In_Arr Replace_Value_In_ArrInt
#endif


#ifdef DOUBLE
void Fill_Random_ValuesDouble(double arr[], int size);
void Show_ArrDouble(double arr[], int size);
void Find_Min_Max_ValueDouble(double arr[], int size);
void Sort_ArrDouble(double arr[], int size);
void Replace_Value_In_ArrDouble(double arr[], int size);

#define Fill_Random_Values Fill_Random_ValuesDouble
#define Show_Array Show_ArrDouble
#define Find_Min_Max_Value Find_Min_Max_ValueDouble
#define Sort_Arr Sort_ArrDouble
#define Replace_Value_In_Arr Replace_Value_In_ArrDouble
#endif


#ifdef CHAR
void Fill_Random_ValuesChar(char arr[], int size);
void Show_ArrChar(char arr[], int size);
void Find_Min_Max_ValueChar(char arr[], int size);
void Sort_ArrChar(char arr[], int size);
void Replace_Value_In_ArrChar(char arr[], int size);

#define Fill_Random_Values Fill_Random_ValuesChar
#define Show_Array Show_ArrChar
#define Find_Min_Max_Value Find_Min_Max_ValueChar
#define Sort_Arr Sort_ArrChar
#define Replace_Value_In_Arr Replace_Value_In_ArrChar
#endif





