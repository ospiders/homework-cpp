/*Создать имитационную модель "остановка маршрутных такси". 
Необходимо вводить следующую информацию: 
-среднее время между появлениями пассажиров на остановке в разное время суток, 
-среднее время между появлениями маршруток на остановке в разное время суток, 
-тип остановки (конечная или нет). 
Необходимо определить: 
-среднее время пребывание человека на остановке, 
-достаточный интервал времени между приходами маршруток, чтобы на остановке находилось не более N людей одновременно. 
Количество свободных мест в маршрутке является случайной величиной. */

#include<iostream>
#include<windows.h>
using namespace std;

class BusStop
{
private:
    int* _wait;
    int _maxQueueLength;
    int _queueLength;
    int _busCapacity;
    int _time_to_next_bus;
    int _time_to_next_people;
    int _endStop;
    static int _timer;

public:
    BusStop(int time_to_next_bus, int time_to_next_passenger, bool end_stop)
    {
        _maxQueueLength = 100;
        _time_to_next_bus = time_to_next_bus;
        _time_to_next_people = time_to_next_passenger;
        _wait = new int[_maxQueueLength]();
        _busCapacity = rand() % 10;
        _endStop = end_stop;
        _queueLength = 0;
    }

    ~BusStop() { delete[] _wait; }

    void Clear() { _queueLength = 0; }

    bool IsEmpty() { return _queueLength == 0; }

    bool IsFull() { return _queueLength == _maxQueueLength; }

    int GetCount() { return _queueLength; }

    int BusCapacity() { return _busCapacity; }

    void Add(int c)
    {
        if (!IsFull())
            _wait[_queueLength++] = c;
    }

    void Show()
    {
        if (!IsEmpty()) {
            int show_timer = 0;
            for (int i = _queueLength; i > 0; i--) {
                cout << "Пассажир#" << i
                     << "\tВремя ожидания:" << show_timer << endl;

                show_timer += _time_to_next_people;
            }
            cout << endl;
        }
        else
            cout << "Пассажир в пути..\n\n";

        return;
    }

    void Extract()
    {
        if (!IsEmpty()) {
            int temp = _wait[0];

            for (int i = 1; i < _queueLength - 1; i++) {
                _wait[i - 1] = _wait[i];
            }

            _wait[_queueLength - 1] = temp;

            _queueLength--;
        }

        return;
    }

    void LoadBus()
    {
        if (!IsEmpty()) {
            for (int i = 0; i < _busCapacity; i++)
                Extract();
        }

        _busCapacity = rand() % 10;

        clearTimer();

        return;
    }

    void BusWait()
    {
        system("cls");

            cout << "Остановка: Октябрьский\n\n";
            Show();
            cout << "Кол-во людей в очереди: " << GetCount() << endl
                 << "Каждые " << _time_to_next_bus << " минут прибывает маршрутка\n"
                 << "Время до появления следующей маршрутки: " << _timer << " минут\n\n";
            _timer++;
        
        return;
    }

    void clearTimer() {  _timer = 1; return; }
};

int BusStop::_timer{ 0 };


int main()
{ 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int t_bus, t_people, end_stop;

    cout << "Введите среднее время между появлениями маршруток: "; // 30min
    cin >> t_bus;
    cout << "Введите среднее время между появлениями пассажиров: "; //5 min
    cin >> t_people;
    do {
        cout << "Конечная ли остановка?[1 - Нет/0 - Да]: "; // 1 or 0
        cin >> end_stop;
    } while (end_stop < 0 || end_stop > 1);


    BusStop BS(t_bus, t_people, end_stop);

    system("cls");

    if (!end_stop)
        cout << "Конечная остановка! Маршрутка отправляется на перерыв.\n";

    for(int t = 0, i = 0; t < 60 * 24 && end_stop == 1; t++) {

       if(t != 0 && t % t_people == 0)
            BS.Add(i++);

        BS.BusWait();

        if (t != 0 && t % t_bus == 0)
        {
            if (BS.BusCapacity())
            {
                cout << "\n\n\tПриехала маршрутка\n"
                     << "\n\tКол-во свободных мест: " << BS.BusCapacity() << endl << endl;

                BS.LoadBus();
                cout << "Пассажиры заняли свободные места, маршрутка уехала.\n";
                i -= BS.BusCapacity();
            }

            else {
                cout << "Маршрутка прибыла без свободных мест, ждем другую.\n";
                BS.LoadBus();
            }

            cout << "1 - Продолжить / 0 - Выход: ";
            cin >> end_stop;
        }
        Sleep(1000);
    }

    return 0;
}