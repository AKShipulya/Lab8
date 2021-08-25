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
	cout << player.name << " - Имя игрока" << endl;
	cout << player.teamNo << " - Номер команды" << endl;
	cout << player.age << " - Возраст игрока" << endl;
	cout << player.height << " - Рост игрока" << endl;
	cout << player.weight << " - Вес игрока" << endl;
}

bool createPlayer(player* p, int n)
{
	char otvet[80];
	player player;
	int number;
	double doubleNumber;

	print("Write name of a player: ");
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return false;
	strcpy_s(player.name, otvet);

	while (true)
	{
		print("Write the team number (1-999) or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;

		number = atoi(otvet);
		if (number >= 1 && number <= 999)
		{
			player.teamNo = number;
			break;
		}
		else
		{
			error("team number error");
			continue;
		}
	}

	while (true)
	{
		print("Write age of the player");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;
		number = atoi(otvet);
		if (number >= 0 && number <= 99)
		{
			player.age = number;
			break;
		}
		else
		{
			error("age error");
			continue;
		}
	}

	while (true)
	{
		print("Write a height of the player");
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
			error("height error");
	}

	while (true)
	{
		print("Write a weight of the player");
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
			error("weight error");
	}

	p[n] = player;
	return true;
}

void add(player* p)
{
	print("Add player: ");
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
		error("no place in the list");
		return;
	}
	if (createPlayer(p, ins))
	{
		print("player added");
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
		error("Empty list");
	}
}

void clearAll(player* p)
{
	for (int i = 0; i < MAX; i++)
	{
		p[i].name[0] = '\0';
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
		print("  Main menu: ");
		print("1 - View players");
		//print("2 - Load from file");
		//print("3 - Save in file");
		print("4 - Add player");
		//print("5 - Remove player");
		//print("6 - Edit player");
		//print("7 - Salary of player");
		print("0 - Exit");

		char otvet[80];
		gets_s(otvet, 79);
		switch (otvet[0])
		{
		case '1': printAll(list); break;
		//case '2': load(list);  break;
		//case '3': save(list);  break;
		case '4': add(list); break;
		//case '5': del(list);  break;
		//case '6': edit(list); break;
		//case '7': task(list); break;
		case '0': return;

		default: error("Error enter");
		}
	}

	system("pause");

}





/*
При редактировании данных – поля, которые не изменяются, заново не вводить.

Предусмотреть для всех пунктов возможность пустого массива и контроль переполнения массива (при добавлении данных).

Предусмотреть исключительные ситуации для работы с файлом и при вводе некорректных значений. После обработки исключения следует вернуться в главное меню.

ВЫВЕСТИ ДЛЯ КАЖДОЙ ИЗ КОМАНД СРЕДНИЙ ВОЗРАСТ, СУММАРНЫЙ ВЕС ЕЁ ИГРОКОВ И РОСТ САМОГО ВЫСОКОГО ИГРОКА. Сортировать в порядке убывания возраста.
*/