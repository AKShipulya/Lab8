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

	print("Укажите имя игрока: ");
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return false;
	strcpy_s(player.name, otvet);

	while (true)
	{
		print("Укажите номер команды (1-999) или нажмите Enter");
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
			error("Ошибка, номер должен быть от 1 до 999");
			continue;
		}
	}

	while (true)
	{
		print("Укажите возраст игрока");
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
			error("Ошибка ввода возраста");
			continue;
		}
	}

	while (true)
	{
		print("Введите рост игрока");
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
			error("Ошибка ввода роста");
	}

	while (true)
	{
		print("Введите вес игрока");
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
			error("Ошибка ввода веса");
	}

	p[n] = player;
	return true;
}

void add(player* p)
{
	print("Добавить игрока: ");
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
		error("Недостаточно места");
		return;
	}
	if (createPlayer(p, ins))
	{
		print("Игрок добавлен");
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
		error("Список пуст");
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
		print("Введите номер команды или Enter для возврата в главное меню: ");
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
		cout << "            Выполнение задания, вариант 19: " << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << " - Средний возраст игроков: " << result << endl;
		cout << " - Вес всех игроков команды: " << weightSum << endl;
		cout << " - Рост самого высокого игрока команды: " << heightRes << endl;
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
		print("  Главное меню: ");
		print("1 - Просмотр игроков");
		print("2 - Добавить игрока");
		print("3 - Выполнение задания");
		print("0 - Выход");

		char otvet[80];
		gets_s(otvet, 79);
		switch (otvet[0])
		{
		case '1': printAll(list); break;
		case '2': add(list); break;
		case '3': taskAge(list); break;
		case '0': return;

		default: error("Ошибка ввода");
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