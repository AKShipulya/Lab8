#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

const int MAX = 30;

struct player
{
	char name[80];
	int teamNo;
	int age;
	double height;
	double weight;
};

void print(const char* message)
{
	//black color message
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (WORD)((8 << 4) | 0));
	printf(message);
	printf("\n");
	return;
}

void error(const char* message)
{
	//red color message
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (WORD)((8 << 4) | 4));
	printf(message);
	printf("\n");
	SetConsoleTextAttribute(console, (WORD)((8 << 4) | 0));
	return;
}

void printPlayer(player& player)
{
	cout << player.name << " - ��� ������" << endl;
	cout << player.teamNo << " - ����� �������" << endl;
	cout << player.age << " - ������� ������" << endl;
	cout << player.height << " - ���� ������" << endl;
	cout << player.weight << " - ��� ������" << endl;
}

bool createPlayer(player* p, int n)
{
	char otvet[80];
	player player;
	int number;
	double doubleNumber;

	print("������� ��� ������: ");
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return false;
	strcpy_s(player.name, otvet);

	while (true)
	{
		print("������� ����� ������� (1-999) ��� ������� Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) <= 0 && strlen(otvet) > 999)
			return false;

		number = atoi(otvet);
		if (number >= 1 && number <= 999)
		{
			player.teamNo = number;
			break;
		}
		else
		{
			error("������, ����� ������ ���� �� 1 �� 999");
			continue;
		}
	}

	while (true)
	{
		print("������� ������� ������");
		gets_s(otvet, 79);

		if (strlen(otvet) <= 0 && strlen(otvet) > 99)
			return false;
		number = atoi(otvet);
		if (number > 0 && number <= 99)
		{
			player.age = number;
			break;
		}
		else
		{
			error("������ ����� ��������");
			continue;
		}
	}

	while (true)
	{
		print("������� ���� ������");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;
		doubleNumber = atoi(otvet);
		if (doubleNumber >= 0 && doubleNumber <= 1000)
		{
			player.height = doubleNumber;
			break;
		}
		else
			error("������ ����� �����");
	}

	while (true)
	{
		print("������� ��� ������");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;
		doubleNumber = atoi(otvet);
		if (doubleNumber >= 0 && doubleNumber <= 300)
		{
			player.weight = doubleNumber;
			break;
		}
		else
			error("������ ����� ����");
	}

	p[n] = player;
	return true;
}

void add(player* p)
{
	print("�������� ������: ");
	int ins = -1;
	for (int i = 0; i < MAX; i++)
	{
		if (p[i].name[0] == '\0')
		{
			ins = i;
			break;
		}
	}
	if (ins == -1)
	{
		error("������������ �����");
		return;
	}
	if (createPlayer(p, ins))
	{
		print("����� ��������");
	}
}

void sort(player* p)
{
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (p[i].age < p[j].age)
			{
				player temp = p[i];
				p[i] = p[j];
				p[i] = temp;
			}
		}
	}
}

void printAll(player p[])
{
	bool f1 = false;
	for (int i = 0, n = 1; i < MAX; i++)
	{
		player current = p[i];
		if (p[i].name[0] == '\0')
			continue;
		printf("%3d) ", n++);

		printPlayer(p[i]);
		f1 = true;
	}
	if (f1 == false)
	{
		error("������ ����");
	}
}

void clearAll(player* p)
{
	for (int i = 0; i < MAX; i++)
	{
		p[i].name[0] = '\0';
	}
}

void taskAge(player p[])
{
	char otvet[80];
	int number;

	int result = 0;
	int ageSum = 0;
	int counter = 0;
	int weightSum = 0;
	int heightRes = 0;
	while (true)
	{
		print("������� ����� ������� ��� Enter ��� �������� � ������� ����: ");
		gets_s(otvet, 79);
		if (strlen(otvet) == 0)
		{
			break;
		}
		number = atoi(otvet);

		for (int i = 0; i < MAX; i++)
		{
			if (number == p[i].teamNo)
			{

				if (p[i].age >= 0 && p[i].age <= 99)
				{
					ageSum += p[i].age;
					counter++;
					result = ageSum / counter;
				}
				if (p[i].weight >= 0 && p[i].weight <= 300)
				{
					weightSum += p[i].weight;
				}
				if (p[i].height >= 0 && p[i].height <= 1000)
				{
					int max = p[0].height;
					if (p[i].height > max)
					{
						max = p[i].height;
						heightRes = max;
					}
				}
			}
		}
		cout << "----------------------------------------------------------" << endl;
		cout << "            ���������� �������, ������� 19: " << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << " - ������� ������� �������: " << result << endl;
		cout << " - ��� ���� ������� �������: " << weightSum << endl;
		cout << " - ���� ������ �������� ������ �������: " << heightRes << endl;
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("color 80"); //grey color
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	player list[MAX];
	clearAll(list);
	while (true)
	{
		print(" ");
		print("  ������� ����: ");
		print("1 - �������� �������");
		print("2 - �������� ������");
		print("3 - ���������� �������");
		print("0 - �����");

		char otvet[80];
		gets_s(otvet, 79);
		switch (otvet[0])
		{
		case '1': printAll(list); break;
		case '2': add(list); break;
		case '3': taskAge(list); break;
		case '0': return;

		default: error("������ �����");
		}
	}
	system("pause");
}





/*
��� �������������� ������ � ����, ������� �� ����������, ������ �� �������.

������������� ��� ���� ������� ����������� ������� ������� � �������� ������������ ������� (��� ���������� ������).

������������� �������������� �������� ��� ������ � ������ � ��� ����� ������������ ��������. ����� ��������� ���������� ������� ��������� � ������� ����.

������� ��� ������ �� ������ ������� �������, ��������� ��� Ũ ������� � ���� ������ �������� ������. ����������� � ������� �������� ��������.
*/