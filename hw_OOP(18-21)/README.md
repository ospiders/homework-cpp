Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай». С помощью 
конструктора установить имя каждого животного и его 
характеристики.

Задание 2. 
Описать базовый класс «Строка».
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра 
C-строку (заканчивается нулевым байтом);
3) конструктор копирования;
4) оператор присваивания;
5) получение длины строки;
6) очистка строки (сделать строку пустой);
7) деструктор;
8) конкатенация строк (перегрузить операторы + и +=);
9) проверка на равенство (= =) и на неравенство (!=).
Описать класс «Битовая строка» производный от 
класса «Строка» 
(Строки данного класса могут содержать только символы ‘0’ и ‘1’). Если в основе инициализирующей строки\
встретятся любые символы, отличные от допустимых, то 
«Битовая строка» становится пустой. Содержимое строки 
рассматривается как двоичное представление целого числа 
со знаковым разрядом. Отрицательные числа хранятся 
в дополнительном коде.
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра 
C-строку;
3) конструктор копирования;
4) оператор присваивания;
4) деструктор;
5) изменение знака числа (перевод числа в дополнительный код).
8) сложение битовых строк (перегрузить операторы + 
и +=);
9) проверка на равенство (= =) и на неравенство (!=)

Задание 1.
Добавьте механизм виртуального наследования в задание 
1 и 2 из самостоятельной работы.

Задание 2.
Используя механизм шаблонного наследования создайте 
иерархию классов. Базовый класс под названием base
имеет следующие переменные-члены:
1. T1 value1; // некоторое значение.
2. T2 value2; // некоторое значение.
Потомок под названием child содержит дополнительные 
переменные-члены:
1. T3 value3.
2. T4 value4.
Потомок под названием child2 добавляет такие переменные-члены:
1. T5 value5.
2. T6 value6.
Каждый класс имеет необходимый набор конструкторов, 
деструкторов, функций-членов для работы со структурой 
класса.
В main протестировать работу класса.

Задание.
Создайте иерархию классов по работе с файлами. Базовый 
класс умеет открывать файл и отображать его содержимое в консоль, первый класс потомка открывает файл 
и отображает содержимое в виде ASCII-кодов символов, 
расположенных в файле, второй класс потомка открывает 
файл и показывает его содержимое в двоичном виде и т.д.
Для отображения содержимого файла в базовом классе 
определена виртуальная функция 
•	 void Display(const char * path);
•	 path — путь к файлу.
Потомки создают свою реализацию виртуальной функции.

Задание 1.
Создать абстрактный базовый класс с виртуальной функцией — корни уравнения. Создать производные классы: 
класс линейных уравнений и класс квадратных уравнений. 
Определить функцию вычисления корней уравнений.

Задание 2.
Создайте абстрактный класс Shape для рисования плоских 
фигур. Определите виртуальные методы:
•	 Show() — вывод на экран информации о фигуре,
•	 Save() — сохранение фигуры в файл,
•	 Load() — считывание фигуры из файла.
Определите производные классы: 
•	 Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны;
•	 Rectangle — прямоугольник с заданными координатами 
верхнего левого угла и размерами;
•	 Circle — окружность с заданными координатами центра и радиусом;
•	 Ellipse — эллипс с заданными координатами верхнего 
угла описанного вокруг него прямоугольника со сторонами, параллельными осям координат, и размерами 
этого прямоугольника.
Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой 
из фигур