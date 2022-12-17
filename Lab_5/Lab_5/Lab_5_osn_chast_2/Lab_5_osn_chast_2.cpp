//Ученики.
//Ф.И.О., класс(цифра + буква), оценки, средний балл.
//Выбор по фамилии.
#include <iostream>
#include <string>
#include <windows.h>
#define size 30
using namespace std;

void search();
int Correct_Input_Integer();
int Correct_Input_Integer_Class();
int Correct_Input_Integer_Ozenka();

struct Student
{
	string name;
	string name_familiya;
	string name_otchestvo;
	string school_class_bukva;
	int school_class_zifra;
	int ozenki[5];
	float GPA;
}list_of_student[size];

union Ustudents {
	char Uname[30];
	char Uname_familiya[30];
	char Uname_otchestvo[30];
	char Uschool_class_bukva[30];
	int Uschool_class_zifra;
	int Uozenki[5];
	float UGPA;
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
		printf("Класс(Цифра): ");
		list_of_student[current_size].school_class_zifra = Correct_Input_Integer_Class();
		printf("Класс(Буква): ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, list_of_student[current_size].school_class_bukva);
			if ((list_of_student[current_size].school_class_bukva[0] < 'A' || list_of_student[current_size].school_class_bukva[0] > 'Z') &&
				(list_of_student[current_size].school_class_bukva[0] < 'a' || list_of_student[current_size].school_class_bukva[0] > 'z') &&
				(list_of_student[current_size].school_class_bukva[0] < 'А' || list_of_student[current_size].school_class_bukva[0] > 'я') &&
				(list_of_student[current_size].school_class_bukva[0] != ' '))
				pr = true;
			if (list_of_student[current_size].school_class_bukva[0] == '\0' || list_of_student[current_size].school_class_bukva[1] != '\0' || list_of_student[current_size].school_class_bukva[0] == ' ')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только букву!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Оценка по математике: ");
		list_of_student[current_size].ozenki[0] = Correct_Input_Integer_Ozenka();
		printf("Оценка по физике: ");
		list_of_student[current_size].ozenki[1] = Correct_Input_Integer_Ozenka();
		printf("Оценка по русскому языку: ");
		list_of_student[current_size].ozenki[2] = Correct_Input_Integer_Ozenka();
		printf("Оценка по английскому языку: ");
		list_of_student[current_size].ozenki[3] = Correct_Input_Integer_Ozenka();
		printf("Оценка по физической культуре: ");
		list_of_student[current_size].ozenki[4] = Correct_Input_Integer_Ozenka();
		list_of_student[current_size].GPA = ((float)list_of_student[current_size].ozenki[0] + (float)list_of_student[current_size].ozenki[1] +
			(float)list_of_student[current_size].ozenki[2] + (float)list_of_student[current_size].ozenki[3] + (float)list_of_student[current_size].ozenki[4]) / 5;
		printf("Средний балл: %0.2f\n", list_of_student[current_size].GPA);
	}
	if (kol_uchen > 0)
		search();
	return 0;
}
void search() {
	printf("----------------------------------------------------------------\nВыбор по фамилии.\n");
	string search_familiya;
	bool o = false;
	bool pr;
	printf("Введите фамилию искомого студента.\n"); do {
		pr = false;
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, search_familiya);
		for (int k = 0; k < search_familiya.length(); k++)
			if ((search_familiya[k] < 'A' || search_familiya[k] > 'Z') &&
				(search_familiya[k] < 'a' || search_familiya[k] > 'z') &&
				(search_familiya[k] < 'А' || search_familiya[k] > 'я') &&
				(search_familiya[k] != ' '))
				pr = true;
		if (search_familiya[0] == '\0')
			pr = true;
		if (pr == true)
			printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
	} while (pr == true);
	for (int i = 0; i < kol_uchen; i++)
		if (list_of_student[i].name_familiya == search_familiya)
		{
			printf("-----------------------------------------------------------\nЭто студент номер %d.\n", i + 1);
			strcpy_s(Ustud.Uname_familiya, list_of_student[i].name_familiya.c_str());
			printf("Фамилия: %s\n", Ustud.Uname_familiya);
			strcpy_s(Ustud.Uname, list_of_student[i].name.c_str());
			printf("Имя: %s\n", Ustud.Uname);
			strcpy_s(Ustud.Uname_otchestvo, list_of_student[i].name_otchestvo.c_str());
			printf("Отчество: %s\n", Ustud.Uname_otchestvo);
			strcpy_s(Ustud.Uschool_class_bukva, list_of_student[i].school_class_bukva.c_str());
			printf("Класс: %s", Ustud.Uschool_class_bukva);
			Ustud.Uschool_class_zifra = list_of_student[i].school_class_zifra;
			printf("\"%d\"\n", Ustud.Uschool_class_zifra);
			Ustud.Uozenki[0] = list_of_student[i].ozenki[0];
			printf("Оценка по математике: %d\n", Ustud.Uozenki[0]);
			Ustud.Uozenki[1] = list_of_student[i].ozenki[1];
			printf("Оценка по физике: %d\n", Ustud.Uozenki[1]);
			Ustud.Uozenki[2] = list_of_student[i].ozenki[2];
			printf("Оценка по русскому языку: %d\n", Ustud.Uozenki[2]);
			Ustud.Uozenki[3] = list_of_student[i].ozenki[3];
			printf("Оценка по английскому языку: %d\n", Ustud.Uozenki[3]);
			Ustud.Uozenki[4] = list_of_student[i].ozenki[4];
			printf("Оценка по физической культуре: %d\n", Ustud.Uozenki[4]);
			Ustud.UGPA = list_of_student[i].GPA;
			printf("Средний балл: %0.2f\n", Ustud.UGPA);
			o = true;
		}
	if (o == false)
		printf("Студент не найден.\n");
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
int Correct_Input_Integer_Class() {
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
		if (proverka_2 == 1 || atoi(ch) < 1 || atoi(ch) > 11)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 1 && atoi(ch) <= 11)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}
int Correct_Input_Integer_Ozenka() {
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
		if (proverka_2 == 1 || atoi(ch) < 0 || atoi(ch) > 10)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 0 && atoi(ch) <= 10)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}