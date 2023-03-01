/*
Написать игру «Быки и коровы».
Программа "загадывает" четырёхзначное число
и играющий должен угадать его.
После ввода пользователем числа программа сообщает,
сколько цифр числа угадано (быки) и
сколько цифр угадано и стоит на нужном месте (коровы).
После отгадывания числа на экран необходимо
вывести количество сделанных пользователем попыток.
*/

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

bool game(int s_n, int u_n);
bool num_check(int number);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int secret_num = rand() % 9000 + 1000;
    int user_num;
    int count = 0;

    cout << "<< Начало игры Быки и Коровы >>" << endl;
    do {
        cout << "Введите четырехзначное число: ";
        cin >> user_num;

        count++;

    } while (!game(user_num, secret_num));
    cout << "Количество попыток: " << count << endl;

    return 0;
}

bool game(int usr_n, int scrt_n) {

    if (!num_check(usr_n))
        return false;

    if (usr_n == scrt_n) {
        cout << "Вы победили" << endl;
        return true;
    }

    int user1 = usr_n / 1000;
    int user2 = usr_n / 100 % 10;
    int user3 = usr_n / 10 % 10;
    int user4 = usr_n % 10;

    int secret1 = scrt_n / 1000;
    int secret2 = scrt_n / 100 % 10;
    int secret3 = scrt_n / 10 % 10;
    int secret4 = scrt_n % 10;

    int rightNumbers = 0;
    int absolutNumbers = 0;

    if (secret1 == user4 || secret1 == user3 || secret1 == user2 || secret1 == user1)
        rightNumbers++;

    if (secret2 == user4 || secret2 == user3 || secret2 == user2 || secret2 == user1)
        rightNumbers++;

    if (secret3 == user4 || secret3 == user3 || secret3 == user2 || secret3 == user1)
        rightNumbers++;

    if (secret4 == user4 || secret4 == user3 || secret4 == user2 || secret4 == user1)
        rightNumbers++;

    if (user1 == secret1)
        absolutNumbers++;

    if (user2 == secret2)
        absolutNumbers++;

    if (user3 == secret3)
        absolutNumbers++;

    if (user4 == secret4)
        absolutNumbers++;

    cout << "Быки: " << rightNumbers << "\t"
         << "Коровы: " << absolutNumbers << endl;

    return false;
}

bool num_check(int number)
{
    if (number < 0 || (number > 0 && number < 1000) || number > 9999) {
        cout << "Ошибка ввода, необходимо 4 числа" << endl;
        return false;
    }
    return true;
}