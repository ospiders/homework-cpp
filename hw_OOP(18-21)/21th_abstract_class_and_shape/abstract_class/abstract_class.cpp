/*Создать абстрактный базовый класс с виртуальной функцией — корни уравнения.
Создать производные классы: класс линейных уравнений и класс квадратных уравнений.
Определить функцию вычисления корней уравнений.*/

#include <iostream>

class Abstract {
public:
	virtual void getAnswer(float a, float b, float c) = 0;

	virtual ~Abstract() {};
};

class LinearEquation : virtual public Abstract
{
    float a{}, b{}, c{}, res{};
public:
	virtual void getAnswer(float a, float b, float c) {
		res = (c - b) / a;
		std::cout << "\nРезультат линейного уравнения: " << res << "\n\n";
	}
};

class SquareEquation : virtual public Abstract
{
    float a{}, b{}, c{}, x1{}, x2{}, D{}, sqrt_D{};
public:
     virtual void getAnswer(float a, float b, float c) {
        D = (b * b) - (4 * a * c);
        if (D < 0)
            std::cout << "Уравнение не имеет корней, т.к. D = " << D << "\n\n";
        else if (D == 0)
        {
            x1 = (0 - b) / (2 * a);
            std::cout << "Уравнение имеет 1 корень: " << x1 << "\n\n";
        }
        else
        {
            sqrt_D = sqrt(D);
            x1 = ((0 - b) + sqrt_D) / (2 * a);
            x2 = ((0 - b) - sqrt_D) / (2 * a);
            std::cout << "Уравнение имеет 2 корня: " << std::endl;
            std::cout << "x1 = " << x1 << std::endl << "x2 = " << x2 << "\n\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int temp;
    float a, b, c;
    Abstract* linear = new LinearEquation;
    Abstract* square = new SquareEquation;

    std::cout << "Ведите коэфициенты уравнения (a * x + b = c):" << "\n";
    std::cout << "Введите по очереди a , b , c" << "\n";
    std::cin >> a >> b >> c;
    linear->getAnswer(a, b, c);

    std::cout << "Ведите коэфициенты уравнения (a * (x^2) + b * x + c = 0):" << "\n";
    std::cout << "Введите по очереди a , b , c" << "\n";
    std::cin >> a >> b >> c;
    square->getAnswer(a, b, c);

    return 0;
}