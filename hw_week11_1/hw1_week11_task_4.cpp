/*Написать функцию, выводящую на экран переданную ей игральную карту*/
#include <iostream>
#include <iomanip>
using namespace std;

void ShowCard(char telo, char num ) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 6; j++) {
            if ((i == 0) || (j == 0) || (i == 15 - 1) || (j == 6 - 1))
                cout << setw(3) << "* "; // вывод "рамки" карты

            else if (((i == 1) && (j == 6 - 2)) || ((i == 15 - 2) && (j == 1))) {
                cout << telo; // вывод масти

                if (num == '0') 
                    cout << "1" << num; // для вывода "10"

                else 
                    cout << num  << " ";
            }

			else
				cout << setw(3) << "| ";
		}
		cout << endl;
	}
}

    int main()
    {
        setlocale(LC_ALL, "Rus");

        int suit_of_cards;
        int card_index;
        char nums_of_card[] = { ' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
        int exit;

        do {
        suit: // 1
            cout << "Укажите масть карты: " << endl
                << "Черви = 3" << endl
                << "Бубны = 4" << endl
                << "Трефы = 5" << endl
                << "Пики = 6" << endl;
            cin >> suit_of_cards;

            if (suit_of_cards < 1 || suit_of_cards > 4) {
                cout << "Ошибка выбора" << endl;
                goto suit; // 1
            }

        index: // 2
            cout << "Выберите индекс карты: " << endl
                << " 1 - туз \t  2 - двойка \t  3 - тройка" << endl
                << " 4 - четверка \t  5 - пятерка \t  6 - шестерка" << endl
                << " 7 - семерка \t  8 - восьмерка   9 - девятка" << endl
                << "10 - десятка \t 11 - валет \t 12 - дама" << endl
                << "13 - король" << endl;
            cin >> card_index;

            if (card_index < 1 || card_index > 13) {
                cout << "Ошибка выбора" << endl;
                goto index; // 2
            }

            ShowCard(suit_of_cards, nums_of_card[card_index]);

            cout << endl << "Если хотите продолжить введите 1, выйти 0: ";
            cin >> exit; cout << endl;

        } while (exit != 0);

	return 0;
}