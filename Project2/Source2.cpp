#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct player
{
	char name[80];
	int teamNo;
	int age;
	double height;
	double weight;
};

void playerPrint(player player);
player createPlayer(char* name, int teamNo, int age, double height, double weight);

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	system("pause");
	return 0;

}

void playerPrint(player player)
{
	cout << player.name << endl;
	cout << player.teamNo << endl;
	cout << player.age << endl;
	cout << player.height << endl;
	cout << player.weight << endl;
}

player createPlayer(char* name, int teamNo, int age, double height, double weight)
{
	return player;
}


/*
��� �������������� ������ � ����, ������� �� ����������, ������ �� �������.

������������� ��� ���� ������� ����������� ������� ������� � �������� ������������ ������� (��� ���������� ������).

������������� �������������� �������� ��� ������ � ������ � ��� ����� ������������ ��������. ����� ��������� ���������� ������� ��������� � ������� ����.

������� ��� ������ �� ������ ������� �������, ��������� ��� Ũ ������� � ���� ������ �������� ������. ����������� � ������� �������� ��������.
*/