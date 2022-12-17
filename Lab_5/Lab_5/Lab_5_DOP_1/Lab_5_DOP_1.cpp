//Клиенты банка.
// Ф.И.О., тип счета(срочный, льготный и т.д.), номер счета, сумма на счете, дата последнего изменения.
// Выбор по номеру счета.
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void search(); 
int Correct_Input_Integer();
int Correct_Input_Integer_Ch();
enum TYPEOFACCOUNT
{
	CALCULATED = 1,
	LOAN,
	DEPOSIT,
	CARD,
	SPECIAL,
} typeofaccount;

struct BANK
{
	string name;
	string name_f;
	string name_o;
	short type;
	int numb_s;
	int summa;
	string date;
} bankbase[31];

union UBANK {
	char Uname[30];
	char Uname_f[30];
	char Uname_o[30];
	short Utype;
	int Unumb_s;
	int Usumma;
	char Udate[30];
} Ubank;

int kol_bank;
int scheta[30];

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int current_size;
	printf("Введите кол-во клиентов банков(до 30): ");
	kol_bank = Correct_Input_Integer_Ch();
	bool pr = false;
	for (current_size = 0; current_size < kol_bank; current_size++) {
		printf("-------------------------------------------------------\n");
		printf("Клиент номер %d", current_size + 1);
		printf("\nФамилия: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, bankbase[current_size].name_f);
			for (int k = 0; k < bankbase[current_size].name_f.length(); k++)
				if ((bankbase[current_size].name_f[k] < 'A' || bankbase[current_size].name_f[k] > 'Z') &&
					(bankbase[current_size].name_f[k] < 'a' || bankbase[current_size].name_f[k] > 'z') &&
					(bankbase[current_size].name_f[k] < 'А' || bankbase[current_size].name_f[k] > 'я') &&
					(bankbase[current_size].name_f[k] != ' '))
					pr = true;
			if (bankbase[current_size].name_f[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Имя: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, bankbase[current_size].name);
			for (int k = 0; k < bankbase[current_size].name.length(); k++)
				if ((bankbase[current_size].name[k] < 'A' || bankbase[current_size].name[k] > 'Z') &&
					(bankbase[current_size].name[k] < 'a' || bankbase[current_size].name[k] > 'z') &&
					(bankbase[current_size].name[k] < 'А' || bankbase[current_size].name[k] > 'я') &&
					(bankbase[current_size].name[k] != ' '))
					pr = true;
			if (bankbase[current_size].name[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Отчество: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, bankbase[current_size].name_o);
			for (int k = 0; k < bankbase[current_size].name_o.length(); k++)
				if ((bankbase[current_size].name_o[k] < 'A' || bankbase[current_size].name_o[k] > 'Z') &&
					(bankbase[current_size].name_o[k] < 'a' || bankbase[current_size].name_o[k] > 'z') &&
					(bankbase[current_size].name_o[k] < 'А' || bankbase[current_size].name_o[k] > 'я') &&
					(bankbase[current_size].name_o[k] != ' '))
					pr = true;
			if (bankbase[current_size].name_o[0] == '\0')
				pr = true;
			if (pr == true)
				printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
		} while (pr == true);
		printf("Введите тип счета(расчетный(1), ссудный(2), депозитный(3), карточный(4), специальный(5)): ");
		do {
			bankbase[current_size].type = Correct_Input_Integer();
			if (bankbase[current_size].type < 1 || bankbase[current_size].type > 5)
				printf("Такого номера нет!\nВведите ещё раз: ");
		} while (bankbase[current_size].type < 1 || bankbase[current_size].type > 5);
		printf("Номер счета: ");
		bool prov_schet = true;
		do {
			prov_schet = true;
			bankbase[current_size].numb_s = Correct_Input_Integer();
			for (int i = 0; i < current_size; i++)
				if (bankbase[current_size].numb_s == scheta[i]) {
					prov_schet = false;
					printf("Такой номер счёта уже есть.\nВведите заново: ");
				}
			scheta[current_size] = bankbase[current_size].numb_s;
		} while (prov_schet == false);
		printf("Сумма на счете: ");
		bankbase[current_size].summa = Correct_Input_Integer();
		printf("Дата последнего изменения.\n");
		int year, month, day;
		bool proverka = true;
		int data_int = 0;
		char dddaaattteee[30];
		while (proverka)
		{
			printf("Введите дату в формате ДДММГГГГ: ");
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, bankbase[current_size].date);
			if (bankbase[current_size].date[8] == '\0')
			{
				if ((bankbase[current_size].date[0] >= '0' || bankbase[current_size].date[0] < '4') &&
					(bankbase[current_size].date[1] >= '0' || bankbase[current_size].date[1] <= '9') &&
					(bankbase[current_size].date[2] >= '0' || bankbase[current_size].date[2] < '1') &&
					(bankbase[current_size].date[3] >= '0' || bankbase[current_size].date[3] <= '9') &&
					(bankbase[current_size].date[4] >= '0' || bankbase[current_size].date[4] <= '9') &&
					(bankbase[current_size].date[5] >= '0' || bankbase[current_size].date[5] <= '9') &&
					(bankbase[current_size].date[6] >= '0' || bankbase[current_size].date[6] <= '9') &&
					(bankbase[current_size].date[7] >= '0' || bankbase[current_size].date[7] <= '9'))
				{
					strcpy_s(dddaaattteee, bankbase[current_size].date.c_str());
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
	}
	if (kol_bank > 0)
		search();
	return 0;
}

void search() {
	printf("----------------------------------------------------------------\nВыбор по номеру счета.\n");
	string search_familiya;
	int search_schet;
	bool o = false;
	bool pr;
	printf("Введите номер искомого счёта.\n");
	pr = false;
	cin.ignore(cin.rdbuf()->in_avail());
	search_schet = Correct_Input_Integer();
	for (int i = 0; i < kol_bank; i++)
		if (bankbase[i].numb_s == search_schet)
		{
			printf("-----------------------------------------------------------\nЭто клиент номер %d.\n", i + 1);// Ф.И.О., тип счета(срочный, льготный и т.д.), номер счета, сумма на счете, дата последнего изменения.
			strcpy_s(Ubank.Uname_f, bankbase[i].name_f.c_str());
			printf("Фамилия: %s\n", Ubank.Uname_f);
			strcpy_s(Ubank.Uname, bankbase[i].name.c_str());
			printf("Имя: %s\n", Ubank.Uname);
			strcpy_s(Ubank.Uname_o, bankbase[i].name_o.c_str());
			printf("Отчество: %s\n", Ubank.Uname_o);
			printf("Тип счёта: ");
			Ubank.Utype = bankbase[i].type;//расчетный(1), ссудный(2), депозитный(3), карточный(4), специальный(5))
			if (Ubank.Utype == CALCULATED)
				printf("Расчетный\n");
			if (Ubank.Utype == LOAN)
				printf("Ссудный\n");
			if (Ubank.Utype == DEPOSIT)
				printf("Депозитный\n");
			if (Ubank.Utype == CARD)
				printf("Карточный\n");
			if (Ubank.Utype == SPECIAL)
				printf("Специальный\n");
			Ubank.Unumb_s = bankbase[i].numb_s;
			printf("Номер счёта: %d\n", Ubank.Unumb_s);
			Ubank.Usumma = bankbase[i].summa;
			printf("Сумма на счёте: %d\n", Ubank.Usumma);
			strcpy_s(Ubank.Udate, bankbase[i].date.c_str());
			printf("Дата последнего изменения: %s\n", Ubank.Udate);
			o = true;
		}
	if (o == false)
		printf("Клиент не найден.\n");
}
//Корректный ввод integer
int Correct_Input_Integer_Ch() {
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
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[30];

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
		if (proverka_2 == 1 || atoi(ch) < 0)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0 && atoi(ch) >= 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}