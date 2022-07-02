/*Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
*/
#include <iostream>
#include <windows.h>
using namespace std;

template<typename T1> T1 func(T1 n1, T1 n2) { // шаг 1. 90 24  |  шаг 4. 24 18  |  шаг 7. 18 6  |  шаг 10. 6 0 
    if (n2 == 0)  // шаг 11. true
        return n1;
    if (n1 > n2) // шаг 2. true  |  шаг 5. true  |  шаг 8. true 
        return func(n2, n1 % n2); // шаг 3. 24  90 % 24 == 18  |  шаг 6. 18  24 % 18 == 6  |  шаг 9. 6  18 % 6 == 0
    else
        return func(n1, n2 % n1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n1, n2;
    int exit;

    do {
        do {
            cout << "Введите первое число: ";
            cin >> n1;
        } while (n1 == 0 || n1 < 0);

        do {
            cout << "Введите второе число: ";
            cin >> n2;
        } while (n2 == 0 || n2 < 0);


        cout << "Наибольший общий знаменатель: " << func(n1, n2) << endl;

        cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
        cin >> exit; cout << endl;

    } while (exit != 0);
    return 0;
}