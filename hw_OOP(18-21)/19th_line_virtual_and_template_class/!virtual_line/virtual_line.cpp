/*Добавьте механизм виртуального наследования в задание 
1 и 2 из самостоятельной работы*/
#include <iostream>

class Line {

	std::string _line;

public:

	Line(std::string line) : _line{ line } { _line[_line.length()] = '\0'; }
	Line() : Line("\0") {}
	Line(const Line& object) : Line(object._line) {}

	const virtual Line operator= (const Line& object) { _line = object._line; return *this; }
	const Line operator= (std::string line) { _line = line; return *this; }

	int get_Length() { return _line.length(); }

	void erase_Line() { _line = '\0'; return; }

	~Line() {}

	const virtual Line operator+ (const Line& object) const { return Line{ _line + object._line }; }
	const Line operator+ (std::string line) const { return Line{ _line + line }; }

	const virtual Line operator+= (const Line& object) { return Line{ _line += object._line }; }
	const Line operator+= (std::string line) { return Line{ _line += line }; }

	friend bool operator==(Line& l_object, Line& r_object) { return (l_object._line == r_object._line); }
	friend bool operator==(Line& l_object, std::string line) { return (l_object._line == line); }

	friend bool operator!=(Line& l_object, Line& r_object) { return !(l_object == r_object); }
	friend bool operator!=(Line& l_object, std::string line) { return !(l_object == line); }

	friend std::ostream& operator<< (std::ostream& output, const Line& object) { output << object._line; return output; }

	std::string get_Line() const { return _line; }
	void set_Line(std::string line) { _line = line;  return; }
};

//----------BIT LINE-----------///

class BitLine : public virtual Line {

public:
	BitLine(std::string line) : Line(line)
	{
		for (int i = 0; i < line.length(); i++)
			if (line[i] != 0 || line[i] != 1)
				line = "\0";
	}

	BitLine() : BitLine("\0") {}

	BitLine(const BitLine& object) : Line(object) {}

	const virtual BitLine operator= (const BitLine& object) { this->set_Line(object.get_Line()); return *this; }
	const BitLine operator= (std::string line) { this->set_Line(line); return *this; }

	~BitLine() {}

	const BitLine to_TwosCode() const
	{
		std::string binary = get_Line();
		int size = binary.length();
		int increase_flag = 0;

		if (binary[0] == '0')
			return BitLine(binary);

		//прибавляем к первой единице с правой стороны еще одну единицу
		for (int i = size - 1; i >= 0; i--) {
			if (binary[i] == '1' && increase_flag == 0)
				binary[i] = '0';

			else if (binary[i] == '0' && increase_flag == 0) {
				binary[i] = '1';
				increase_flag = 1;
			}
		}
		binary[size] = '\0';

		return BitLine(binary);
	}

	const virtual BitLine operator+ (const BitLine object)
	{
		this->to_TwosCode();
		object.to_TwosCode();

		std::string l_binary = get_Line();
		int size1 = l_binary.length() - 1;

		std::string r_binary = object.get_Line();
		int size2 = r_binary.length() - 1;

		std::string result = "";

		int temp = 0;

		while (size1 >= 0 || size2 >= 0 || temp == 1) {
			temp += ((size1 >= 0) ? l_binary[size1] - '0' : 0); // 1 или 0 в ячейке левой строки 
			temp += ((size2 >= 0) ? r_binary[size2] - '0' : 0); // 1 или 0 в ячейке правой строки 
			result = char(temp % 2 + '0') + result; // если 2 единицы в temp, то записываем 0 (1 + 1 = 0), если 1, то записываем 1 (1 + 0 = 1)
			temp /= 2; // если 2 единицы в темп, то  2 / 2 = 1 (1 + 1 = 0) + 1  в следующий разр¤д
			size1--; size2--;
		}

		return BitLine(result);
	}
	const BitLine operator+ (std::string line) { return BitLine{ *this + BitLine{line} }; }

	const virtual BitLine operator+= (const BitLine& object) { *this = BitLine{ *this + BitLine{object} }; return *this; }
	const BitLine operator+= (std::string line) { return *this += BitLine{ line }; }
};


int main() {
	std::setlocale(LC_ALL, "");

	Line str1("marat");
	Line str2("marat");
	Line str3("rarat");

	if (str1 == str2)
		std::cout << str1 << " == " << str2 << "\n";
	if (str1 != str3)
		std::cout << str1 << " != " << str3 << "\n\n";

	std::cout << str1 << " + " << str3 << " = " << (str1 + str3) << "  str1: " << str1 << "\n";
	std::cout << str1; std::cout << " += " << str3 << " = " << (str1 += str3) << "  str1: " << str1 << "\n\n";

	std::cout << str1 << " + " << "warat" << " = " << (str1 + "warat") << "  str1: " << str1 << "\n";
	std::cout << str1; std::cout << " += " << "warat" << " = " << (str1 += "warat") << "  str1: " << str1 << "\n\n";

	std::cout << str1 << " = " << str3 << "\n";
	str1 = str3;
	std::cout << str1 << "\n\n";

	std::cout << str1 << " = " << "darat" << "\n";
	str1 = "darat";
	std::cout << str1 << "\n\n";


	///---------BINARY---------///


	BitLine b_str1("100101");
	BitLine b_str2("100101");
	BitLine b_str3("101001");


	if (b_str1 == b_str2)
		std::cout << b_str1 << " == " << b_str2 << "\n";
	if (str1 != str3)
		std::cout << b_str1 << " != " << b_str3 << "\n\n";

	std::cout << b_str1 << " + " << b_str3 << " = " << (b_str1 + b_str3) << "  b_str1: " << b_str1 << "\n";
	std::cout << b_str1; std::cout << " += " << b_str3 << " = " << (b_str1 += b_str3) << "  b_str1: " << b_str1 << "\n\n";

	std::cout << b_str1 << " + " << "011010" << " = " << (b_str1 + "011010") << "  b_str1: " << b_str1 << "\n";
	std::cout << b_str1; std::cout << " += " << "011010" << " = " << (b_str1 += "011010") << "  b_str1: " << b_str1 << "\n\n";

	std::cout << b_str2 << " - " << b_str2.to_TwosCode() << "\n";
	std::cout << b_str3 << " - " << b_str3.to_TwosCode() << "\n\n";

	std::cout << b_str1 << " = " << b_str3 << "\n";
	b_str1 = b_str3;
	std::cout << b_str1 << "\n\n";

	std::cout << b_str1 << " = " << "111100" << "\n";
	b_str1 = "111100";
	std::cout << b_str1 << "\n\n";

	return 0;
}