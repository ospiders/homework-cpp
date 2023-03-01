/*Реализовать структуру «Автомобиль» (длина, 
клиренс (высота посадки), объем двигателя, мощность 
двигателя, диаметр колес, цвет, тип коробки передач). 
Создайте функции для задания значений, отображения 
значений, поиска значений.*/
#include <iostream>
using namespace std;

struct Car
{
    int car_length;
    int car_ground_clearance;
    double car_engine_volume;
    int car_wheel_diameter;
    char car_color[20];
    short car_gearbox_type;


    Car(int length, int ground_clearance, double engine_volume, int wheel_diameter, char color, short gearbox_type)
        : car_length{ length }, car_ground_clearance{ ground_clearance }, car_engine_volume{engine_volume}, 
        car_wheel_diameter{ wheel_diameter }, car_color{ color }, car_gearbox_type{ gearbox_type } {}


    Car() : Car{ 0, 0, 0, 0, ' ', 0} {}

    ~Car() {}

    void read()
    {
        cout << "Укажите длинну автомобиля(в сантиметрах): ";
        cin >> car_length;
        cout << "Укажите дорожный просвет автомобиля(в сантиметрах): ";
        cin >> car_ground_clearance;
        cout << "Укажите объем двигателя автомобиля(в литрах): ";
        cin >> car_engine_volume;
        cout << "Укажите диаметр колес автомобиля(в сантиметрах): ";
        cin >> car_wheel_diameter;
        cout << "Укажите цвет автомобиля: ";
        cin >> car_color;
        do {
            cout << "Укажите тип коробки передач автомобиля(0 - АКПП, 1 - МКПП): ";
            cin >> car_gearbox_type;
        } while (car_gearbox_type != 0 && car_gearbox_type != 1);
        cout << endl;

        return;
    }

    void print()
    {
        cout << "Длинна автомобиля: " << car_length << " (см)\n"
            << "Дорожный просвет автомобиля: " << car_ground_clearance << " (см)\n"
            << "Объем двигателя автомобиля: " << car_engine_volume << " (л)\n"
            << "Диаметр колес автомобиля: " << car_wheel_diameter << " (см)\n"
            << "Цвет автомобиля: " << car_color << endl
            << "Тип коробки передач автомобиля: " << (car_gearbox_type == 0 ? "АКПП" : "МКПП") << endl;
        cout << endl;
        return;
    }
};

int menu()
{
    int answer;
    cout << "\tМеню Автомобиля\n"
        << "1 - Указать параметры автомобиля\n"
        << "2 - Показать параметры автомобиля\n"
        << "3 - Поиск по параметрам автомобиля\n"
        << "0 - Выход из программы\n"; 
    cin >> answer;
    cout << endl;
   
    return answer;
}

int settings_car_menu()
{
    int answer;
    cout << "\tПараметры автомобиля\n"
        << "1 - Длинна автомобиля\n"
        << "2 - Дорожный просвет автомобиля\n"
        << "3 - Объем двигателя автомобиля\n"
        << "4 - Диаметр колес автомобиля\n"
        << "5 - Цвет автомобиля\n"
        << "6 - Тип коробки передач автомобиля\n"
        << "7 - Выход из меню\n";
    cin >> answer;
    cout << endl;

    return answer;
}


int main() {
    setlocale(LC_ALL, "");

    Car first_car;
    int answer;

    do {
        answer = menu();

        switch (answer) {
        case 0:
            break;
        case 1:
            first_car.read();
            break;
        case 2:
            first_car.print();
            break;
        case 3:
            do {
                answer = settings_car_menu();

                switch (answer) {
                
                case 1:
                    cout << "Длинна автомобиля: " << first_car.car_length << " (см)\n";
                    cout << endl;
                    break;
                case 2:
                    cout << "Дорожный просвет автомобиля: " << first_car.car_ground_clearance << " (см)\n";
                    cout << endl;
                    break;
                case 3:
                    cout << "Объем двигателя автомобиля: " << first_car.car_engine_volume << " (л)\n";
                    cout << endl;
                    break;
                case 4:
                    cout << "Диаметр колес автомобиля: " << first_car.car_wheel_diameter << " (см)\n";
                    cout << endl;
                    break;
                case 5:
                    cout << "Цвет автомобиля: " << first_car.car_color << endl;
                    cout << endl;
                    break;
                case 6:
                    cout << "Тип коробки передач автомобиля: " << (first_car.car_gearbox_type == 0 ? "АКПП" : "МКПП") << endl;
                    cout << endl;
                    break;
                case 7:
                    break;
                default:
                    break;
                }
            } while (answer != 7);
            break;
        default:
            break;
        }
    } while (answer != 0);

    return 0;
}