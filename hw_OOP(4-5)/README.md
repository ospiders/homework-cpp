Задание. 
Создайте программу, имитирующую многоквартирный 
дом. Необходимо иметь классы “Человек”, “Квартира”, 
“Дом”. Класс “Квартира” содержит динамический массив 
объектов класса “Человек”. Класс “Дом” содержит массив 
объектов класса “Квартира”. 
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области 
класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для 
ФИО в классе “Человек”. Не забывайте обеспечить классы 
различными конструкторами (конструктор копирования 
обязателен), деструкторами. В main протестировать работу полученного набора классов.

Задание. 
Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название». Класс должен содержать: 
конструктор по умолчанию, конструктор с параметрами, 
при необходимости реализовать деструктор и конструктор копирования.
Добавить методы для:
1. Определения приблизительного объема (ширина*длина*максимальная глубина);
2. Определения площади водной поверхности;
3. Метод для проверки относятся ли водоемы к одному 
типу (море-море; бассейн-пруд);
4. Для сравнения площади водной поверхности водоемов 
одного типа;
5. Для копирования объектов;
6. Остальные методы на усмотрение разработчика (методы set и get).
Написать интерфейс для работы с классом. Реализовать 
динамический массив объектов класса с возможностью 
добавления, удаления объектов из массива. Реализовать 
возможность записи информации об объектах массива 
в текстовый файл, бинарный файл.
Используйте explicit конструктор и константные функциичлены (например, для отображения данных о водоёме и т.д.)