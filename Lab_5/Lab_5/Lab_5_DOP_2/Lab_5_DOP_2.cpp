//Студенты. 
//Ф.И.О., дата поступления, специальность, группа, факультет, средний балл. 
//Выбор по среднему баллу.
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void search();
int Correct_Input_Integer(); 
float Correct_Input_Float();

struct Student
{
	string name;
	string name_familiya;
	string name_otchestvo;
	string date;
	string spcl;
	int group;
	string faclt;
	float sr_ball;
}list_of_student[30];

union Ustudents {
	char Uname[30];
	char Uname_familiya[30];
	char Uname_otchestvo[30];
	char Udate[30];
	char Uspcl[30];
	int Ugroup;
	char Ufaclt[30];
	float Usr_ball;
} Ustud;

int kol_uchen;

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current_size;
	printf("Введите кол-во учеников(до 30): ");
	kol_uchen = Correct_Input_Integer();
	bool pr = false;
	for (current_size = 0; current_size < kol_uchen; current_size++) {
		printf("----------------------------------------------------------------\n");
		printf("Ученик номер %d", current_size + 1);
		printf("\nФамилия: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list_of_student[current_size].name_familiya);
			for (int k = 0; k < list_of_student[current_size].name_familiya.length(); k++)
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
			getline(cin, list_of_student[current_size].name);
			for (int k = 0; k < list_of_student[current_size].name.length(); k++)
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
			getline(cin, list_of_student[current_size].name_otchestvo);
			for (int k = 0; k < list_of_student[current_size].name_otchestvo.length(); k++)
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
		int year, month, day;
		bool proverka = true;
		int data_int = 0;
		char dddaaattteee[30];
		while (proverka)
		{
			printf("Введите дату поступления в формате ДДММГГГГ: ");
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list_of_student[current_size].date);
			if (list_of_student[current_size].date[8] == '\0')
			{
				if ((list_of_student[current_size].date[0] >= '0' || list_of_student[current_size].date[0] < '4') &&
					(list_of_student[current_size].date[1] >= '0' || list_of_student[current_size].date[1] <= '9') &&
					(list_of_student[current_size].date[2] >= '0' || list_of_student[current_size].date[2] < '1') &&
					(list_of_student[current_size].date[3] >= '0' || list_of_student[current_size].date[3] <= '9') &&
					(list_of_student[current_size].date[4] >= '0' || list_of_student[current_size].date[4] <= '9') &&
					(list_of_student[current_size].date[5] >= '0' || list_of_student[current_size].date[5] <= '9') &&
					(list_of_student[current_size].date[6] >= '0' || list_of_student[current_size].date[6] <= '9') &&
					(list_of_student[current_size].date[7] >= '0' || list_of_student[current_size].date[7] <= '9'))
				{
					strcpy_s(dddaaattteee, list_of_student[current_size].date.c_str());
					data_int = atoi(dddaaattteee);
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
		//Ф.И.О., дата поступления, специальность, группа, факультет, средний балл. 
		printf("Специальность: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list_of_student[current_size].spcl);
			for (int k = 0; k < list_of_student[current_size].spcl.length(); k++)
				if ((list_of_student[current_size].spcl[k] < 'A' || list_of_student[current_size].spcl[k] > 'Z') &&
					(list_of_student[current_size].spcl[k] < 'a' || list_of_student[current_size].spcl[k] > 'z') &&
					(list_of_student[current_size].spcl[k] < 'А' || list_of_student[current_size].spcl[k] > 'я') &&
					(list_of_student[current_size].spcl[k] != ' '))
					pr = true;
			if (list_of_student[current_size].spcl[0] == '\0')
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
			getline(cin, list_of_student[current_size].faclt);
			for (int k = 0; k < list_of_student[current_size].faclt.length(); k++)
				if ((list_of_student[current_size].faclt[k] < 'A' || list_of_student[current_size].faclt[k] > 'Z') &&
					(list_of_student[current_size].faclt[k] < 'a' || list_of_student[current_size].faclt[k] > 'z') &&
					(list_of_student[current_size].faclt[k] < 'А' || list_of_student[current_size].faclt[k] > 'я') &&
					(list_of_student[current_size].faclt[k] != ' '))
					pr = true;
			if (list_of_student[current_size].faclt[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Средний балл(Только 2 знака после запятой): ");
		list_of_student[current_size].sr_ball = Correct_Input_Float();

	}
	if (kol_uchen > 0)
		search();
	return 0;
}
void search() {
	printf("----------------------------------------------------------------\nВыбор по фамилии.\n");
	float search_sr;
	bool o = false;
	bool pr;
	printf("Введите средний балл искомого студента.\n"); 
		pr = false;
		cin.ignore(cin.rdbuf()->in_avail());
		search_sr = Correct_Input_Float();
	for (int i = 0; i < kol_uchen; i++)
		if (list_of_student[i].sr_ball == search_sr)
		{
			printf("-----------------------------------------------------------\nЭто студент номер %d.\n", i + 1);
			strcpy_s(Ustud.Uname_familiya, list_of_student[i].name_familiya.c_str());
			printf("Фамилия: %s\n", Ustud.Uname_familiya);
			strcpy_s(Ustud.Uname, list_of_student[i].name.c_str());
			printf("Имя: %s\n", Ustud.Uname);
			strcpy_s(Ustud.Uname_otchestvo, list_of_student[i].name_otchestvo.c_str());
			printf("Отчество: %s\n", Ustud.Uname_otchestvo);
			strcpy_s(Ustud.Udate, list_of_student[i].date.c_str());
			printf("Дата поступления: %s", Ustud.Udate);
			strcpy_s(Ustud.Uspcl, list_of_student[i].spcl.c_str());
			printf("Специальность: %s\n", Ustud.Uspcl);
			Ustud.Ugroup = list_of_student[i].group;
			printf("Группа: %d\n", Ustud.Ugroup);
			strcpy_s(Ustud.Ufaclt, list_of_student[i].faclt.c_str());
			printf("Факультет: %s\n", Ustud.Ufaclt);
			Ustud.Usr_ball = list_of_student[i].sr_ball;
			printf("Средний балл: %0.2f\n", Ustud.Usr_ball);
			o = true;
		}
	if (o == false)
		printf("Студента с таким средним баллом не найдено.\n");
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
		if (proverka_2 == 1 || atoi(ch) < 0 || atoi(ch) > 29)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 0 && atoi(ch) <= 29)
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