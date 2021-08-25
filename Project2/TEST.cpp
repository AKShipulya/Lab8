#include <iostream>
#include <Windows.h>
using namespace std;

const int MAX = 20;  // count of members
struct employee
{
	char name[50];
	int personnelnumber;
	int workhours;
	int rate;
	int salary;
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
void clearAll(employee* e)
{
	for (int i = 0; i < MAX; i++)
	{
		e[i].name[0] = '\0';
	}
}

void printEmployee(employee& e)
{
	printf("%20s - %3d (number) - %5d (hours) - %5d (rate) \n", e.name, e.personnelnumber, e.workhours, e.rate);
}
void printAll(employee e[])
{
	bool f1 = false;
	for (int i = 0, n = 1; i < MAX; i++)
	{
		employee current = e[i];
		if (e[i].name[0] == '\0')
			continue;
		printf("%3d) ", n++);

		printEmployee(e[i]);
		f1 = true;
	}
	if (f1 == false)
	{
		error("Empty list");
	}
}

bool addemployee(employee* e, int n)
{
	char otvet[80];
	employee a;
	int number;

	print("Write name (FIO) or Enter: ");
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return false;
	strcpy_s(a.name, otvet);

	while (true)
	{
		print("Write the Personal number (100-999) or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;

		number = atoi(otvet);
		if (number >= 100 && number <= 999)
		{
			a.personnelnumber = number;
			break;
		}
		else
		{
			error("error personal number");
			continue;
		}
	}

	while (true)
	{
		print("Write work hours in month or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;
		number = atoi(otvet);
		if (number >= 0 && number <= 320)
		{
			a.workhours = number;
			break;
		}
		else
		{
			error("error work hours");
			continue;
		}
	}

	while (true)
	{
		print("Write rate for employee or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			return false;
		number = atoi(otvet);
		if (number >= 0 && number <= 1000)
		{
			a.rate = number;
			break;
		}
		else
			error("error rates");
	}

	e[n] = a;
	return true;
}
void add(employee* e)
{
	print("Add employee: ");
	int ins = -1;
	for (int i = 0; i < MAX; i++)
	{
		if (e[i].name[0] == '\0')
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
	if (addemployee(e, ins))
	{
		print("added employee");
	}
}

void save(employee* e)
{
	FILE* file;
	char otvet[80];
	print("Enter file name (without extention): ");
	gets_s(otvet, 79);
	strcat_s(otvet, ".bin");
	if (fopen_s(&file, otvet, "wb"))
	{
		error("Error file write");
		return;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (e[i].name[0] != '\0')
			fwrite(&e[i], sizeof(employee), 1, file);
	}
	fclose(file);
	print("list is saved");
}

void load(employee* e)
{
	FILE* file;
	char otvet[80];
	print("Enter file name (without extention): ");
	gets_s(otvet, 79);
	strcat_s(otvet, ".bin");
	clearAll(e);
	if (fopen_s(&file, otvet, "rb"))
	{
		error("Error file read");
		return;
	}
	fread(e, sizeof(employee), MAX, file);

	fclose(file);
	print("list is full");
}
void del(employee* e)
{
	printAll(e);
	print("------------------------------");
	print("Enter index for delete");

	char otvet[80];
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return;
	int number = atoi(otvet);
	if (number < 0 || number >= MAX)
	{
		error("Error index");
		return;
	}
	for (int i = 0, n = 1; i < MAX; i++)
	{
		if (e[i].name[0] != '\0')
		{
			if (n == number)
			{
				e[i].name[0] = '\0';
				print("employee delete");
				return;
			}
			n++;
		}
	}
	error("Error index");
}
bool editEmployee(employee& e)
{
	char otvet[80];
	int number;
	bool f1 = false;
	printEmployee(e);

	print("Write new name (FIO) or Enter: ");
	gets_s(otvet, 79);
	if (strlen(otvet) > 0)
	{
		strcpy_s(e.name, otvet);
		f1 = true;
	}

	while (true)
	{
		print("Write New the Personal number (100-999) or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			break;

		number = atoi(otvet);
		if (number >= 100 && number <= 999)
		{
			e.personnelnumber = number;
			f1 = true;
			break;
		}
		else
		{
			error("error personal number");
			continue;
		}
	}

	while (true)
	{
		print("Write New work hours in month or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			break;

		number = atoi(otvet);
		if (number >= 0 && number <= 320)
		{
			e.workhours = number;
			f1 = true;
			break;
		}
		else
		{
			error("error work hours");
			continue;
		}
	}

	while (true)
	{
		print("Write new rate for employee or Enter");
		gets_s(otvet, 79);

		if (strlen(otvet) == 0)
			break;

		number = atoi(otvet);
		if (number >= 0 && number <= 1000)
		{
			e.rate = number;
			f1 = true;
			break;
		}
		else
			error("error rates");
	}
	return f1;
}

void edit(employee* e)
{
	printAll(e);
	print("------------------------------");
	print("Enter index for edit");

	char otvet[80];
	gets_s(otvet, 79);
	if (strlen(otvet) == 0)
		return;
	int number = atoi(otvet);
	if (number < 0 || number >= MAX)
	{
		error("Error index");
		return;
	}

	for (int i = 0, n = 1; i < MAX; i++)
	{
		if (e[i].name[0] != '\0')
		{
			if (n == number)
			{
				if (editEmployee(e[i]))
					printf("Employee edited");
				else
					printf("Employee not edit");
				return;
			}
			n++;
		}
	}
	error("Error index");
}

void sort(employee* e)
{
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (e[i].salary < e[j].salary)
			{
				employee temp = e[i];
				e[i] = e[j];
				e[i] = temp;
			}
		}
	}
}

void task(employee* e)
{
	print("Salary of employees: ");
	print("---------------------------------");

	for (int i = 0; i < MAX; i++)
	{
		employee a = e[i];
		if (a.name[0] == '\0')
			continue;

		if (a.workhours >= 0 && a.workhours < 144)
		{
			a.salary = (a.workhours) * ((a.rate) - (a.rate) * 0.1);
		}
		else
			a.salary = 144 * ((a.rate) - (a.rate) * 0.1) + ((a.workhours) - 144) * (2 * (a.rate) - (a.rate) * 0.1);
	}
	sort(e);
	for (int i = 0; i < MAX; i++)
	{
		printf("%20s - %10d", e[i].name, e[i].salary);
	}
	save(e);
}

void main()
{
	system("color 80"); //grey color
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	employee list[MAX];
	clearAll(list);
	while (true)
	{
		print(" ");
		print("  Main menu: ");
		print("1 - View employees");
		print("2 - Load from file");
		print("3 - Save in file");
		print("4 - Add employee");
		print("5 - Remove employee");
		print("6 - Edit employee");
		print("7 - Salary of employee");
		print("0 - Exit");

		char otvet[80];
		gets_s(otvet, 79);
		switch (otvet[0])
		{
		case '1': printAll(list); break;
		case '2': load(list);  break;
		case '3': save(list);  break;
		case '4': add(list); break;
		case '5': del(list);  break;
		case '6': edit(list); break;
		case '7': task(list); break;
		case '0': return;

		default: error("Error enter");
		}
	}
	system("pause");
}
