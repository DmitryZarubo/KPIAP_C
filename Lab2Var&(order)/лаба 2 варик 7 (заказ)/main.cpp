#include <iostream>
#include <cmath>
#include <iomanip>
namespace FIGURS {
	class Center {				//класс для центра
	private:
		int x;
		int y;
	public:
		Center(const int& x1 = 0, const int& y1 = 0) :x(x1), y(y1) {};
		void set_x(const int& x1) { x = x1; };
		void set_y(const int& y1) { y = y1; };
		const int& get_x() const { return x; };
		const int& get_y() const { return y; };
	};

	class Figure {  //абстрактный базовый класс для фигур
	protected:
		Center center;
	public:

		Figure(const int& x1 = 0, const int& y1 = 0) :center(x1, y1) {};
		/*перемещение в указанные координаты*/
		void Move(const int& nx1, const int ny1) { center.set_x(nx1); center.set_y(ny1); }
		/*чисто виртуальная функция*/
		virtual void Scale(const double& n) {};
		virtual void Scale(const double& n1, const double& n2) {};
		virtual double Area()const { return double();  };
		virtual void Show() const = 0 { std::cout << "Center's position:" << std::setw(5) << "(" << center.get_x() << "," << center.get_y() << ")\n"; };
		virtual void Rotate(const double& ang) {};
		
		virtual ~Figure() {};
	};

	class Circle : public Figure {
	private:
		double	radius;
	public:
		Circle(const int& x1 = 0, const int& y1 = 0, const double& _radius = 0) :Figure(x1, y1), radius(_radius) {};

		void Scale(const double& n) { radius *= n; };
		const double& get_radius() { return radius; };
		void set_radius(const double& rad) { radius = rad; };
		double Area() const { return 3.14 * pow(radius, 2); };
		void Show() const override { std::cout << "\nCIRCLE:\n"; Figure::Show(); std::cout << "Area:" << std::setw(22) << Area() << "\n" << "Radius :" << std::setw(17) << radius << "\n"; };
	};

	class Square : public Figure {
	protected:
		double length;
		double angle;
		void show()const { Figure::Show(); std::cout << "Area:" << std::setw(22) << Area() << "\nDiagonal:" << std::setw(17) << get_diagonal() << "\nAngle:" << std::setw(22) << angle << "\nLength:" << std::setw(17) << length << "\n"; };
	public:
		Square(const int& x1 = 0, const int& y1 = 0, const double& _length = 0, const double& _angle = 0) : Figure(x1, y1), length(_length), angle(_angle) {};
		virtual double get_diagonal() const { return sqrt(2) * length; };
		virtual void Scale(const double& n) { length *= n; };
		virtual double Area() const { return pow(length, 2); };
		void Show() const override { std::cout << "\nSQUARE:\n"; show(); };
		void Rotate(const double& ang) { angle += ang; };
		void set_length(const double& len) { length = len; };
		void set_angle(const double& ang) { angle = ang; };
		double get_angle()const { return angle; };
		double get_length()const { return length; };
		virtual ~Square() {};
	};

	class Rectangle : public Square {
	private:
		double width;
	public:
		Rectangle(const int& x1 = 0, const int& y1 = 0, const double& _length = 0, const double& _width = 0, const double& _angle = 0) : Square(x1, y1, _length, _angle), width(_width) {};
		double get_diagonal() const override { return sqrt(pow(length, 2) + pow(width, 2)); };
		void Scale(const double& n1, const double& n2) { length *= n1; width *= n2; };
		void Scale(const double& n) override { length *= n; width *= n; };
		double Area() const override { return length * width; };
		void Show() const  override { std::cout << "\nRECTANGLE:\n"; Square::show(); std::cout << "Width:" << std::setw(17) << width << "\n"; };
		void set_width(double wid) { width = wid; };
		double get_width() const { return width; };
	};
}
int main(void)
{
	const int N = 3;
	FIGURS::Figure* array[N];
	FIGURS::Circle a(2, 4, 10);
	FIGURS::Square b(5, 15, 6, 0);
	FIGURS::Rectangle c(-12, -20, 4, 7,60);
	array[0] = &a;
	array[1] = &b;
	array[2] = &c;
	std::cout << "\n\tBEFORE:\n";
	
	for(int i =0;i<N;i++)
			array[i]->Show();

	array[0]->Move(60,-12);
	array[1]->Move(60, -12);
	array[2]->Move(60, -12);
	array[0]->Scale(4);
	array[1]->Scale(0.5);
	array[2]->Scale(2,1);
	array[1]->Rotate(50);
	array[2]->Rotate(-60);
	
	std::cout << "\n\tAFTER:\n";
	for (int i = 0; i < N; i++)
		array[i]->Show();

	return 0;
}