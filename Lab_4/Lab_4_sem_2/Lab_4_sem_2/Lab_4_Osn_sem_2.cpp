//Основа. Вариант 9. 
//	Студенты. 
//	Ф.И.О., дата поступления, специальность, группа, факультет, средний балл. Выбор по фамилии.
#include <iostream>                  
#include <stdio.h>  
#include <fstream>
#include <windows.h>
# define _CRT_SECURE_NO_WARNINGS
# define str_len 30                               
# define size 30  
using namespace std;
//Функции:
void enter_new();//	Ввод элементов структуры с клавиатуры
void out();// Вывод элементов структуры в консольное окно
void del();// Удаление заданной структурированной переменной
void search();//Поиск информации
void out_file();//	Запись информации в файл
void in_file();// Чтение данных из файла
//Функции проверок:
float Correct_Input_Float();//Корректный ввод только не целыз чисел
int Correct_Input_Integer();//Корректный ввод только целых чисел

struct Student
{
	char name_familiya[str_len];
	char name[str_len];
	char name_otchestvo[str_len];
	char receipt_date[str_len];
	char speciality[str_len];
	int group;
	char faculty[str_len];
	float GPA;
};
struct Student list_of_student[size];
struct Student bad;// Для удаления
int current_size = 0; 
int choice;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		printf("-------------------------------------------------------\n");
		printf("1-Ввод элементов структуры с клавиатуры.\n");
		printf("2-Вывод элементов структуры в консольное окно.\n");
		printf("3-Удаление заданной структурированной переменной.\n");
		printf("4-Поиск информации.\n");
		printf("5-Запись информации в файл.\n");
		printf("6-Чтение данных из файла.\n");
		printf("7-Выход.\n");
		printf("-------------------------------------------------------\n");
		printf("Ввод: ");
		do {
			choice = Correct_Input_Integer();
			if (choice <= 0 || choice >= 8)
				printf("Такого варианта нет!\nВведите ещё раз: ");
		} while (choice <= 0 || choice >= 8);
		switch (choice)
		{
		case 1:  enter_new(); break;
		case 2:  out(); break;
		case 3:  del(); break;
		case 4:  search(); break;
		case 5:  out_file(); break;
		case 6:  in_file();	break;
		}
	} while (choice != 7);
}
void enter_new()
{
	bool pr = false;
	printf("Ввод информации:\n");
	if (current_size < size)
	{
		printf("Студент номер %d", current_size + 1);
		printf("\nФамилия: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name_familiya);
			for (int k = 0; k < strlen(list_of_student[current_size].name_familiya); k++)
				if ((list_of_student[current_size].name_familiya[k] < 'A' || list_of_student[current_size].name_familiya[k] > 'Z') && 
					(list_of_student[current_size].name_familiya[k] < 'a' || list_of_student[current_size].name_familiya[k] > 'z') && 
					(list_of_student[current_size].name_familiya[k] < 'А' || list_of_student[current_size].name_familiya[k] > 'я') && 
					(list_of_student[current_size].name_familiya[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name_familiya[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Имя: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name);
			for (int k = 0; k < strlen(list_of_student[current_size].name); k++)
				if ((list_of_student[current_size].name[k] < 'A' || list_of_student[current_size].name[k] > 'Z') && 
					(list_of_student[current_size].name[k] < 'a' || list_of_student[current_size].name[k] > 'z') && 
					(list_of_student[current_size].name[k] < 'А' || list_of_student[current_size].name[k] > 'я') && 
					(list_of_student[current_size].name[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Отчество: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name_otchestvo);
			for (int k = 0; k < strlen(list_of_student[current_size].name_otchestvo); k++)
				if ((list_of_student[current_size].name_otchestvo[k] < 'A' || list_of_student[current_size].name_otchestvo[k] > 'Z') &&
					(list_of_student[current_size].name_otchestvo[k] < 'a' || list_of_student[current_size].name_otchestvo[k] > 'z') &&
					(list_of_student[current_size].name_otchestvo[k] < 'А' || list_of_student[current_size].name_otchestvo[k] > 'я') &&
					(list_of_student[current_size].name_otchestvo[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name_otchestvo[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Дата поступления. ");
		int year, month, day;
		bool proverka = true;
		int data_int = 0;
		while (proverka)
		{
			printf("Введите дату поступления в формате ДДММГГГГ: ");
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].receipt_date);
			if (list_of_student[current_size].receipt_date[8] == '\0')
			{
				if ((list_of_student[current_size].receipt_date[0] >= '0' || list_of_student[current_size].receipt_date[0] < '4') &&
					(list_of_student[current_size].receipt_date[1] >= '0' || list_of_student[current_size].receipt_date[1] <= '9') &&
					(list_of_student[current_size].receipt_date[2] >= '0' || list_of_student[current_size].receipt_date[2] < '1') &&
					(list_of_student[current_size].receipt_date[3] >= '0' || list_of_student[current_size].receipt_date[3] <= '9') &&
					(list_of_student[current_size].receipt_date[4] >= '0' || list_of_student[current_size].receipt_date[4] <= '9') &&
					(list_of_student[current_size].receipt_date[5] >= '0' || list_of_student[current_size].receipt_date[5] <= '9') &&
					(list_of_student[current_size].receipt_date[6] >= '0' || list_of_student[current_size].receipt_date[6] <= '9') &&
					(list_of_student[current_size].receipt_date[7] >= '0' || list_of_student[current_size].receipt_date[7] <= '9'))
				{
					data_int = atoi(list_of_student[current_size].receipt_date);
					if (data_int >= 1010001 && data_int <= 31129999)
					{
						year = data_int % 10000;
						month = (data_int / 10000) % 100;
						day = data_int / 1000000;
						if (month < 13 && month > 0)
						{
							if (year % 4 == 0 && year % 100 != 0)
							{
								if ((month == 2 && day < 30) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("Некорректная дата\n");
							}
							else
							{
								if ((month == 2 && day < 29) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("Некорректная дата\n");
							}
						}
						else
							printf("Некорректная дата\n");
					}
					else
						printf("Некорректная дата\n");
				}
			}
			else
				printf("Некорректная дата\n");
		}
		printf("Специальность: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].speciality);
			for (int k = 0; k < strlen(list_of_student[current_size].speciality); k++)
				if ((list_of_student[current_size].speciality[k] < 'A' || list_of_student[current_size].speciality[k] > 'Z') &&
					(list_of_student[current_size].speciality[k] < 'a' || list_of_student[current_size].speciality[k] > 'z') &&
					(list_of_student[current_size].speciality[k] < 'А' || list_of_student[current_size].speciality[k] > 'я') &&
					(list_of_student[current_size].speciality[k] != ' '))
					pr = true;
			if (list_of_student[current_size].speciality[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Группа: ");
		list_of_student[current_size].group = Correct_Input_Integer();
		printf("Факультет: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].faculty);
			for (int k = 0; k < strlen(list_of_student[current_size].faculty); k++)
				if ((list_of_student[current_size].faculty[k] < 'A' || list_of_student[current_size].faculty[k] > 'Z') &&
					(list_of_student[current_size].faculty[k] < 'a' || list_of_student[current_size].faculty[k] > 'z') &&
					(list_of_student[current_size].faculty[k] < 'А' || list_of_student[current_size].faculty[k] > 'я') &&
					(list_of_student[current_size].faculty[k] != ' '))
					pr = true;
			if (list_of_student[current_size].faculty[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Средний балл(Только 2 знака после запятой): ");
		list_of_student[current_size].GPA = Correct_Input_Float();
		current_size++;
	}
	else
		printf("Введено максимальное кол-во строк.");
	printf("Что дальше?\n");
}
void out()
{
	int sw, n;
	bool pr = true;
	printf("1-вывод одной строки.\n2-вывод всех строк.\n");
	do {
		scanf_s("%d", &sw);
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("Неправильный выбор! Повторите попытку: ");
	} while (pr == true);
	if (sw == 1)
	{
		printf("Номер выводимой строки ");
		n = Correct_Input_Integer();
		if (n > 0 && n <= current_size) {
			printf("*****************************************************\n");
			printf("Фамилия: %s\n", list_of_student[n - 1].name_familiya);
			printf("Имя: %s\n", list_of_student[n - 1].name);
			printf("Отчество: %s\n", list_of_student[n - 1].name_otchestvo);
			printf("Дата поступления: %s\n", list_of_student[n - 1].receipt_date);
			printf("Специальность: %s\n", list_of_student[n - 1].speciality);
			printf("Группа: %d\n", list_of_student[n - 1].group);
			printf("Факультет: %s\n", list_of_student[n - 1].faculty);
			printf("Средний балл: %0.2f\n", list_of_student[n - 1].GPA);
			printf("*****************************************************\n");
		}
		else
			printf("Нет такой строки.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			printf("*****************************************************\n");
			printf("Студент номер %d\n", i + 1);
			printf("Фамилия: %s\n", list_of_student[i].name_familiya);
			printf("Имя: %s\n", list_of_student[i].name);
			printf("Отчество: %s\n", list_of_student[i].name_otchestvo);
			printf("Дата поступления: %s\n", list_of_student[i].receipt_date);
			printf("Специальность: %s\n", list_of_student[i].speciality);
			printf("Группа: %d\n", list_of_student[i].group);
			printf("Факультет: %s\n", list_of_student[i].faculty);
			printf("Средний балл: %0.2f\n", list_of_student[i].GPA);
			printf("*****************************************************\n");
		}
	}
	printf("Что дальше?\n");
}
void del()
{
	int d;
	bool pr = true;
	printf("\nНомер студента, данные которого нужно удалить (для удаления данных всех студентов нажать 99): ");
	do {
		d = Correct_Input_Integer();
		if (d > 0 && d <= current_size || d == 99)
			pr = false;
		else
			printf("Такой строки нет!\nПовторите попытку: ");
	} while (pr == true);
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
		printf("Были удаленны данные студента номер %d", d);
	}
	if (d == 99) {
		for (int i = 0; i < size; i++)
			list_of_student[i] = bad;
		printf("Были удаленные данные всех студентов.\n");
	}
	printf("Что дальше?\n");
}
void search() {
	char search_familiya[str_len];
	char search_name[str_len];
	bool o = false;
	printf("Введите Имя и Фамилию искомого студента.\n");
	printf("Имя: ");
	cin >> search_name;
	printf("Фамилия: ");
	cin >> search_familiya;
	for (int i = 0; i < current_size; i++)
		if ((strcmp(list_of_student[i].name_familiya, search_familiya) == 0) && (strcmp(list_of_student[i].name, search_name) == 0))
		{
			printf("Это студент номер %d.\n", i + 1);
			o = true;
		}
	if (o == false)
		printf("Студент не найден.\n");
	printf("Что дальше?\n");
}
void out_file() {
	char naz[10] = "";
	int sw, n;
	printf("Введите название файла(С расширением!): ");
	cin >> naz;

	ofstream fout(naz);
	
	bool pr = true;
	printf("1-вывод одной строки.\n2-вывод всех строк.\n");
	do {
		sw = Correct_Input_Integer();
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("Неправильный выбор! Повторите попытку: ");
	} while (pr == true);

	if (sw == 1)
	{
		printf("Номер выводимой строки ");
		n = Correct_Input_Integer();
		if (n > 0 && n <= current_size) {
			fout << "Фамилия: " << list_of_student[n - 1].name_familiya << endl;
			fout << "Имя: " << list_of_student[n - 1].name << endl;
			fout << "Отчество: " << list_of_student[n - 1].name_otchestvo << endl;
			fout << "Дата поступления: " << list_of_student[n - 1].receipt_date << endl;
			fout << "Специальность: " << list_of_student[n - 1].speciality << endl;
			fout << "Группа: " << list_of_student[n - 1].group << endl;
			fout << "Факультет: " << list_of_student[n - 1].faculty << endl;
			fout << "Средний балл: " << list_of_student[n - 1].GPA << endl;
			printf("Строка номер %d была записана.\n", n);
		}
		else
			printf("Нет такой строки.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			fout << "Фамилия: " << list_of_student[i].name_familiya << endl;
			fout << "Имя: " << list_of_student[i].name << endl;
			fout << "Отчество: " << list_of_student[i].name_otchestvo << endl;
			fout << "Дата поступления: " << list_of_student[i].receipt_date << endl;
			fout << "Специальность: " << list_of_student[i].speciality << endl;
			fout << "Группа: " << list_of_student[i].group << endl;
			fout << "Факультет: " << list_of_student[i].faculty << endl;
			fout << "Средний балл: " << list_of_student[i].GPA << endl;
		}
		printf("Все строки были записанны.\n");
	}
	fout.close();
	printf("Что дальше?\n");
}

void in_file() {
	char naz[15] = "";
	printf("Введите название файла(С расширением!): ");
	cin >> naz;

	ifstream fin(naz);

	char buff[50];

	if (!fin.is_open())
		printf("Файл не может быть открыт!\n");
	else
	{
		for (int i = 0; i < 8; i++)
		{
			fin.getline(buff, 50); // считывание строки из файла
			if (i == 0) {
				cout << "Фамилия ";
				cout << buff << endl;
			}
			if (i == 1) {
				cout << "Имя: ";
				cout << buff << endl;
			}
			if (i == 2) {
				cout << "Отчество: ";
				cout << buff << endl;
			}
			if (i == 3) {
				cout << "Дата поступления: ";
				cout << buff << endl;
			}
			if (i == 4) {
				cout << "Специальност: ";
				cout << buff << endl;
			}
			if (i == 5) {
				cout << "Группа: ";
				cout << buff << endl;
			}
			if (i == 6) {
				cout << "Факультет: ";
				cout << buff << endl;
			}
			if (i == 7) {
				cout << "Средний балл: ";
				cout << buff << endl;
			}
		}
	}
	fin.close();
	printf("Что дальше?\n");
}


//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}

float Correct_Input_Float() {
	float value;
	int proverka = 0, proverka_2 = 0;
	char ch[30];

	while (proverka != 1) 
	{
		proverka_2 = 0;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[4] == '\0')
			if (ch[1] == '.')
				if ((ch[0] >= '0' && ch[0] <= '9') && (ch[2] >= '0' && ch[2] <= '9') && (ch[3] >= '0' && ch[3] <= '9'))
					proverka_2 = 1;
		cin.clear();
		if (proverka_2 == 0 || atof(ch) < 0 || atof(ch) > 10)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 1 && atof(ch) >= 0 && atof(ch) <= 10)
			proverka = 1;
	}
	value = atof(ch);
	return value;
}