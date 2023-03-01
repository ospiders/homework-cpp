/*Создайте абстрактный класс Shape дл¤ рисования плоских фигур.
Определите виртуальные методы:
-	 Show() - вывод на экран информации о фигуре,
-	 Save() - сохранение фигуры в файл,
-	 Load() - считывание фигуры из файла.
Определите производные классы:
-	 Square - квадрат, который характеризуетс¤ координатами левого верхнего угла и длиной стороны;
-	 Rectangle - прямоугольник с заданными координатами
верхнего левого угла и размерами;
-	 Circle - окружность с заданными координатами центра и радиусом;
-	 Ellipse - эллипс с заданными координатами верхнего угла описанного вокруг него пр¤моугольника со сторонами,
параллельными осям координат, и размерами этого прямоугольника.
Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой из фигур.*/

#include <iostream>
#include <fstream>

class Shape {
public:
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
	virtual ~Shape() {};
};

class Square : public Shape
{
public:
	int _side;
	char** _square;
	std::string path = "square.txt";
	std::fstream fs;

	Square() : _side{ 0 }, _square{ nullptr } {};

	Square(int side) : _side{ side }
	{
		Alloc();
		Fill();
	};

	~Square()
	{ 
			fs.close(); 

			for (int i = 0; i < _side; i++)
				delete[] _square[i];

			delete[] _square; 
	}

	void Alloc() 
	{
		_square = new char* [_side];
		for (int i = 0; i < _side; i++)
			_square[i] = new char[_side];

		return;
	}

	void Fill() 
	{
		for (int i = 0; i < _side; i++)
			for (int j = 0; j < _side; j++)
				_square[i][j] = '*';

		return;
	}

	void Show()
	{
		for (int i = 0; i < _side; i++) {
			for (int j = 0; j < _side; j++)
				std::cout << _square[i][j] << " ";

			std::cout << std::endl;
		}

		std::cout << "Сторона квадрата равна " << _side << "\n\n";
		return;
	}

	void Save() 
	{
		fs.open(path, std::ios_base::out);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			for (int i = 0; i < _side; i++) {
				for (int j = 0; j < _side; j++)
					fs << _square[i][j] << " ";

				fs << "\n";
			}
		}
		fs.close();
		return;
	}

	void Load() 
	{
		char buf[128]{};

		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			fs.getline(buf, 127, '\n');
			_side = strlen(buf) / 2;
			Alloc();
			Fill();
		}
		fs.close();
		return;
	}
};

class Rectangle : public Shape
{
public:
	int _width, _height;
	char** _rectangle;

	std::string path = "rectangle.txt";
	std::fstream fs;

	Rectangle() : _width{ 0 }, _height{ 0 }, _rectangle{ nullptr } {}

	Rectangle(int _width, int _height) : _width{ _width }, _height{ _height } {
		Alloc();
		Fill();
	}
	~Rectangle()
	{
		fs.close();

		for (int i = 0; i < _height; i++)
			delete[] _rectangle[i];

		delete[] _rectangle;
	}

	void Alloc() 
	{
		_rectangle = new char* [_height];
		for (int i = 0; i < _height; i++)
			_rectangle[i] = new char[_width];

		return;
	}

	void Fill() 
	{
		for (int i = 0; i < _height; i++)
			for (int j = 0; j < _width; j++)
				_rectangle[i][j] = '*';

		return;
	}

	void Show()
	{
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++)
				std::cout << _rectangle[i][j] << " ";

			std::cout << std::endl;
		}

		std::cout << "Высота прямоугольника равна " << _height << std::endl;
		std::cout << "Ширина прямоугольника равна " << _width << "\n\n";

		return;
	}

	void Save() 
	{
		fs.open(path, std::ios_base::out);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			for (int i = 0; i < _height; i++) {
				for (int j = 0; j < _width; j++)
					fs << _rectangle[i][j] << " ";

				fs << "\n";
			}
		}

		fs.close();
		return;
	}

	void Load() {
		char buf[128]{};
		int count = 0;

		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else
		{
			fs.getline(buf, 127, '\n');
			_width = strlen(buf) / 2;

			while (fs.good()) {
				fs.getline(buf, 127, '\n');
				count++;
			}
			_height = count;
			Alloc();
			Fill();
		}
		fs.close();
		return;
	}

};

class Circle : public Shape
{
public:
	int _side, _radius;
	char** _circle;

	std::string path = "circle.txt";
	std::fstream fs;

	Circle() : _side{ 0 }, _radius{ 0 }, _circle{ nullptr } {}

	Circle(int radius) : _radius{ radius }
	{
		_side = 2 * radius + 1;

		Alloc();
		Fill();
	}

	~Circle()
	{
		fs.close();

		for (int i = 0; i < _side; i++)
			delete[] _circle[i];

		delete[] _circle;
	}

	void Alloc() 
	{
		_circle = new char* [_side];
		for (int i = 0; i < _side; i++)
			_circle[i] = new char[_side];

		return;
	}

	void Fill()
	{
		int x, y;

		for (int i = 0; i < _side; i++) {
			for (int j = 0; j < _side; j++) {
				//начало крайней точки левого угла относительно середины фигуры
				x = i - _radius;
				y = j - _radius;

				//если точка внутри круга x^2 + y^2 <= r^2(+1.5 для отрисовывания более округлой формы)
				if (x * x + y * y <= _radius * _radius + 1.5)
					_circle[i][j] = '*';
				else
					_circle[i][j] = ' ';
			}
		}
		return;
	}

	void Show() 
	{
		for (int i = 0; i < _side; i++) {
			for (int j = 0; j < _side; j++)
				std::cout << _circle[i][j] << " ";

			std::cout << std::endl;
		}
		std::cout << "Радиус круга равен " << _radius << "\n\n";

		return;
	}

	void Save() 
	{
		fs.open(path, std::ios_base::out);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			for (int i = 0; i < _side; i++) {
				for (int j = 0; j < _side; j++)
					fs << _circle[i][j] << " ";

				fs << "\n";
			}
		}
		fs.close();
		return;
	}

	void Load() 
	{
		char buf[128]{};

		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			fs.getline(buf, 127, '\n');
			_side = strlen(buf) / 2;
			_radius = _side / 2;
			
			Alloc();
			Fill();
		}
		fs.close();
		return;
	}
};

class Ellipse : public Shape {
public:
	int _width_radius, _height_radius, _w_side, _h_side;
	char** _ellipse;

	std::string path = "ellipse.txt";
	std::fstream fs;

	Ellipse() : _width_radius(0), _height_radius(0), _w_side{ 0 }, _h_side{ 0 }, _ellipse{ nullptr } {}

	Ellipse(int _width, int _height) : _width_radius(_width), _height_radius(_height) {
		_w_side = _width_radius * 2 + 1;
		_h_side = _height_radius * 2 + 1;
		Alloc();
		Fill();
	}
	~Ellipse()
	{
		fs.close();

		for (int i = 0; i < _h_side; i++)
			delete[] _ellipse[i];

		delete[] _ellipse;
	}

	void Alloc()
	{
		_ellipse = new char* [_h_side];
		for (int i = 0; i < _h_side; i++)
			_ellipse[i] = new char[_w_side];

		return;
	}

	int checkpoint(float x, float y, float a, float b) 
	{
		return (x * x) / (a * a) + (y * y) / (b * b);
	}

	void Fill()
	{
		int x, y, a, b;

		for (int i = 0; i < _h_side; i++) {
			for (int j = 0; j < _w_side; j++) {
				x = i - _height_radius;
				y = j - _width_radius;
				 
				a = _height_radius;
				b = _width_radius;
				 
				if(checkpoint(x,y, a - a / 3.5, b - 1.5) <= 1)
					_ellipse[i][j] = '*';
				else
					_ellipse[i][j] = ' ';
			}
		}
		return;
	}

	void Show()
	{
		for (int i = 0; i < _h_side; i++) {
			for (int j = 0; j < _w_side; j++)
				std::cout << _ellipse[i][j] << " ";

			std::cout << std::endl;
		}

		std::cout << "Большой радиус эллипса равен ";
			(_height_radius > _width_radius) ? std::cout << _height_radius : std::cout << _width_radius; std::cout << std::endl;
		std::cout << "Малый радиус эллипса равен ";
			(_height_radius < _width_radius) ? std::cout << _height_radius : std::cout << _width_radius; std::cout << "\n\n";

		return;
	}

	void Save()
	{
		fs.open(path, std::ios_base::out);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			for (int i = 0; i < _h_side; i++) {
				for (int j = 0; j < _w_side; j++)
					fs << _ellipse[i][j] << " ";

				fs << "\n";
			}
		}
		fs.close();
		return;
	}

	void Load()
	{
		char buf[128]{};
		int count = 0;

		fs.open(path, std::ios_base::in);

		if (!fs.is_open()) {
			std::cout << "Error!";
			return;
		}
		else {
			fs.getline(buf, 127, '\n');
			_w_side = strlen(buf) / 2;
			_width_radius = _w_side / 2;
		
			while (fs.good()) {
				fs.getline(buf, 127, '\n');
				count++;
			}
			_h_side = count;
			_height_radius = _h_side / 2;

			Alloc();
			Fill();
		}
		fs.close();
		return;
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	Shape* s = new Square(5);
	s->Save();
	s->Load();
	s->Show();

	Shape* r = new Rectangle(7, 5);
	r->Save();
	r->Load();
	r->Show();

	Shape* c = new Circle(5);
	c->Save();
	c->Load();
	c->Show();

	Shape* e = new Ellipse(8, 6);
	e->Save();
    e->Load();
	e->Show();
	
	return 0;
}