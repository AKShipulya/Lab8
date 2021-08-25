#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct square
{
	double a;
};
struct cube
{
	double a;
};

double perimeter(square s);
double perimeter(cube c);
double area(square s);
double area(cube c);
double volume(cube c);

void print(square s);
void print(cube c);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

			square sq;
			cout << "Создаем квадрат" << endl;
			cout << "Введите сторону квадрата (double): ";
			cin >> sq.a;
			print(sq);
			cout << "Периметр квадрата = " << perimeter(sq) << endl;
			cout << "Площадь квадрата = " << area(sq) << endl;

			cout << "------------------------------------------------" << endl;

			cube cube;
			cout << "Создаем куб" << endl;
			cout << "Введите сторону куба (double): ";
			cin >> cube.a;
			print(cube);
			cout << "Периметр куба = " << perimeter(cube) << endl;
			cout << "Площадь куба = " << area(cube) << endl;
			cout << "Объем куба = " << volume(cube) << endl;

			cout << "------------------------------------------------" << endl;

			system("pause");
			return 0;
		
}

double perimeter(square s)
{
	return 4 * s.a;
}

double perimeter(cube c)
{
	return 12 * c.a;
}

double area(square s)

{
	return s.a * s.a;
}

double area(cube c)
{
	return 6 * c.a * c.a;
}

double volume(cube c)
{
	return c.a * c.a * c.a;
}

void print(square s)
{
	cout << "Квадрат. Стороны a = " << s.a << endl;
}

void print(cube c)
{
	cout << "Куб. Ребра a = " << c.a << endl;
}