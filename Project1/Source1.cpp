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
			cout << "������� �������" << endl;
			cout << "������� ������� �������� (double): ";
			cin >> sq.a;
			print(sq);
			cout << "�������� �������� = " << perimeter(sq) << endl;
			cout << "������� �������� = " << area(sq) << endl;

			cout << "------------------------------------------------" << endl;

			cube cube;
			cout << "������� ���" << endl;
			cout << "������� ������� ���� (double): ";
			cin >> cube.a;
			print(cube);
			cout << "�������� ���� = " << perimeter(cube) << endl;
			cout << "������� ���� = " << area(cube) << endl;
			cout << "����� ���� = " << volume(cube) << endl;

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
	cout << "�������. ������� a = " << s.a << endl;
}

void print(cube c)
{
	cout << "���. ����� a = " << c.a << endl;
}