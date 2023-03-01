/*Создайте иерархию классов по работе с файлами.
Базовый класс умеет открывать файл и отображать его содержимое в консоль,
первый класс потомка открывает файл и отображает содержимое в виде ASCII-кодов символов, 
расположенных в файле, второй класс потомка открывает файл и показывает его содержимое в двоичном виде и т.д.
Для отображения содержимого файла в базовом классе определена виртуальна¤ функция
Х	 void Display(const char * path);
Х	 path - путь к файлу.
Потомки создают свою реализацию виртуальной функции.*/

#include <iostream>
#include <fstream>
#include <string>

class File {
public:
	std::fstream fs;

	virtual ~File() { fs.close(); }

	virtual void Display(const char* path) 
	{
		fs.open(path, std::ios_base::in);

		if(!fs.is_open()) {
			std::cout << "Error!";
			return;
		}

		std::string tmp;
		std::cout << "File: \n";

		while (!fs.eof()) {
			std::getline(fs, tmp, '\n');
			std::cout << tmp << std::endl;
		}	
		return;
	}
};

class FileAscii : public virtual File {
public:

	virtual void Display(const char* path) 
	{
		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}

		std::string tmp;
		std::cout << "FileAscii: \n";

		while (!fs.eof()) {
			std::getline(fs, tmp, '\n');

			for (int i = 0; i < tmp.size(); i++)
				std::cout << (int)tmp[i] << " ";

			std::cout << std::endl;
		}
		return;
	}
};

class FileBinary : public File {
private:
	std::string char_ToBinary(char c)
	{
		std::string bin{};

		int val = int(c);

		while (val > 0)
		{
			(val % 2) ? bin.push_back('1') : bin.push_back('0');
			val /= 2;
		}

		reverse(bin.begin(), bin.end());

		return bin;
	}

public:
	FileBinary() {}

	virtual void Display(const char* path)
	{
		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}

		std::string tmp;
		std::cout << "FileBinary: \n";

		while (!fs.eof()) {
			std::getline(fs, tmp, '\n');

			for (int i = 0; i < tmp.size(); i++)
				std::cout << char_ToBinary(tmp[i]) << " ";

			std::cout << std::endl;
		}
		return;
	}

};

int main() {
	setlocale(LC_ALL, "");

	File d;
	d.Display("data.txt");
	
	std::cout << "\n\n";

	FileAscii r;
	r.Display("data.txt");

	std::cout << "\n\n";

	FileBinary g;
	g.Display("data.txt");

	return 0;
}