/*Разработайте программу «Библиотека».
Создайте структуру «Книга»(название, автор, издательство,жанр).
Создайте массив из 10 книг.Реализуйте для него следующие возможности:

■ Редактировать книгу;
■ Печать всех книг;
■ Поиск книг по автору;
■ Поиск книги по названию;
■ Сортировка массива по названию книг;
■ Сортировка массива по автору;
■ Сортировка массива по издательству*/

#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

struct Library
{
	string book_title;
	string book_author;
	string book_publishing_office;
	string book_genre;

	Library(string title, string author, string office, string genre) 
		: book_title{ title }, book_author{ author }, 
		book_publishing_office{ office }, book_genre{ genre } {}

	Library() : Library(" ", " ", " ", " ") {}

	~Library() {}

	void read() 
	{
		cout << "\nУкажите название книги: ";
		cin.ignore(); getline(cin, book_title);
		cout << "Укажите автора книги: ";
		getline(cin, book_author);
		cout << "Укажите издательсвто книги: ";
		getline(cin, book_publishing_office);
		cout << "Укажите жанр книги: ";
		getline(cin, book_genre);

		return;
	}

	void print()
	{
		cout << "Название книги: " << book_title << endl
			<< "Автор книги: " << book_author << endl
			<< "Издательство книги: " << book_publishing_office << endl
			<< "Жанр книги: " << book_genre << endl;
		cout << endl;
		return;
	}

};

int menu()
{
	int answer;
	cout << "\tМеню Библеотеки\n"
		<< "1 - Редактировать книгу\n"
		<< "2 - Печать всех книг\n"
		<< "3 - Поиск книг по автору\n"
		<< "4 - Поиск книги по названию\n"
		<< "5 - Сортировка массива по названию книг\n"
		<< "6 - Сортировка массива по автору\n"
		<< "7 - Сортировка массива по издательству\n"
		<< "0 - Выход из программы\n";
	cin >> answer;
	cout << endl;

	return answer;
}

int book_number() {
	int answer;
	cout << "Выберите номер книги для редактирования: ";
	cin >> answer;

	cout << endl;
	return answer;
}

bool compare_title(Library a, Library b)
{
	return a.book_title < b.book_title;
}

bool compare_author(Library a, Library b)
{
	return a.book_author < b.book_author;
}

bool compare_publishing_office(Library a, Library b)
{
	return a.book_publishing_office < b.book_publishing_office;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int LIBRARY_SIZE = 10;
	Library* books = new Library[LIBRARY_SIZE];

	books[0] = { "Введение в язык Си++", "Столяров А.В.", "Москва", "Учебное пособие" };
	books[1] = { "Язык Программирования C++", "Бьёрн Страуструп", "Аддисон Веслей", "Учебное пособие" };
	books[2] = { "Чистый Код", "Роберт Мартин", "Прентис Халл", "Учебное пособие" };
	books[3] = { "Золотой ключик", "Толстой А.Н", "Москва", "Приключение" };
	books[4] = { "Совершенный код", "Стив Макконнелл", "Уэсэй", "Учебное пособие" };
	books[5] = { "Властелин Колец", "Джон Толкин", "Айсити", "Приключение" };
	books[6] = { "Искра Жизни", "Эрих Мария Ремарк", "Айсити", "Роман" };
	books[7] = { "Таинственный остров", "Жюль Верн", "Вече", "Приключение" };
	books[8] = { "Судьба человека", "Шолохов М.А.", "Речь", "Художественный вымысел" };
	books[9] = { "Гарри Поттер", "Джоан Роулинг", "Азбука", "Приключение" };

	int answer, book_num;
	bool isEqual = false;
	string author, title;

	do {
		answer = menu();

		switch (answer) {
		case 0:
			break;
		case 1:
			book_num = book_number();
			cout << "\tРедактирование книги #" << book_num << endl;
			books[book_num - 1].read();
			cout << endl;
			break;
		case 2:
			cout << "\tВсе книги вашей библеотеки\n";

			for (int i = 0; i < LIBRARY_SIZE; i++) {
				if (books[i].book_author != " ") {
					cout << "Книга #" << i + 1 << endl;
					books[i].print();
				}
			}

			cout << endl;
			break;
		case 3:
			cout << "\tПоиск книг по автору\n"
				<< "Укажите автора для поиска книги: ";
			cin.ignore(); getline(cin, author); cout << endl;
			for (int i = 0; i < LIBRARY_SIZE; i++) {
				if (books[i].book_author.length() == author.length()) {
					for (int j = 0; j < author.length(); j++) {
						if (books[i].book_author[j] == author[j])
							isEqual = true;
						else
							isEqual = false;
					}
				}
				if (isEqual) {
					cout << "Книга #" << i + 1 << endl;
					books[i].print();
					isEqual = false;
				}
			}
			break;
		case 4:
			cout << "\tПоиск книг по названию\n"
				<< "Укажите автора для поиска книги: ";
			cin.ignore(); getline(cin, title); cout << endl;
			for (int i = 0; i < LIBRARY_SIZE; i++) {
				if (books[i].book_title.length() == title.length()) {
					for (int j = 0; j < title.length(); j++) {
						if (books[i].book_title[j] == title[j])
							isEqual = true;
						else
							isEqual = false;
					}
				}
				if (isEqual) {
					cout << "Книга #" << i + 1 << endl;
					books[i].print();
					isEqual = false;
				}
			}
			break;
		case 5:
			cout << "\tСортировка книг по названию\n";
		
			sort(books, books + LIBRARY_SIZE, compare_title);

			cout << "\nБиблеотека пересобрана\n";
			cout << endl;
			
			break;
		case 6:
			cout << "\tСортировка книг по автору\n";

			sort(books, books + LIBRARY_SIZE, compare_author);

			cout << "\nБиблеотека пересобрана\n";
			cout << endl;
			break;
		case 7:
			cout << "\tСортировка книг по издателю\n";

			sort(books, books + LIBRARY_SIZE, compare_publishing_office);

			cout << "\nБиблеотека пересобрана\n";
			cout << endl;
			break;
		default:
			break;
		}
	} while (answer != 0);


	return 0;
}