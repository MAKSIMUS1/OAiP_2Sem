////Вокзал.
////Номер поезда, пункт назначения, день следования, время прибытия, время отправления.
////Выбор по пункту назначения.
////Дни следования реализовать с помощью перечисления.
////Время выбытия и прибытия  реализовать с помощью битового поля(часы, минуты).
#include <iostream>
#include <string>
using namespace std;
string foo();
int add_client();
int out();
int delete_client();
int find_client();
//Функции корректного ввода:
int Correct_Input_Integer();
int Correct_Input_Retirement_Time();
int Correct_Input_Departure_Time();
enum FOLLOWING_DAYS {//Дни следования
	MONDAY = 1, 
	TUESDAY, 
	WEDNESDAY,
	THURSDAY, 
	FRIDAY, 
	SATURDAY, 
	SUNDAY,
} foll_d;
struct RAILWAY
{
	unsigned int NumberTrain;
	char Destination[28];
	unsigned int Following_day;
	unsigned int Retirement_time_hours : 5;
	unsigned int Retirement_time_minutes : 6;
	unsigned int Departure_time_hours : 5;
	unsigned int Departure_time_minutes : 6;
};
struct RAILWAY railwaybase[30];
int choice, current_size = 0;
int scheta[30];
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	printf("Введите:\n");
	printf("1-Добавление поезда в базу\n");
	printf("2-Вывод поездов\n");
	printf("3-Удаление поезда\n");
	printf("4-Поиск поезда\n");
	printf("0-Выход\n");
	do
	{
		do {
			choice = Correct_Input_Integer();
			if (choice < 0 || choice > 4)
				printf("Такого варианта нет!\nВведите ещё раз: ");
		} while (choice <  0 || choice > 4);
		switch (choice)
		{
			case 1:  add_client();	break;
			case 2:  out();  break;
			case 3:  delete_client();  break;
			case 4:  find_client();	break;
		}
	} while (choice != 0);
}
int add_client()
{
	if (current_size < 20) {
		cin.clear();
		printf("**********************************************************\n");
		printf("Поезда №%d:\n", current_size + 1);
		printf("Введите номер поезда: ");
		bool prov_schet = true;
		do {
			prov_schet = true;
			railwaybase[current_size].NumberTrain = Correct_Input_Integer();
			for (int i = 0; i < current_size; i++)
				if (railwaybase[current_size].NumberTrain == scheta[i]) {
					prov_schet = false;
					printf("Такой номер поезда уже есть.\nВведите заново: ");
				}
			scheta[current_size] = railwaybase[current_size].NumberTrain;
		} while (prov_schet == false);
		printf("Введите пункт назначения: ");
		cin >> railwaybase[current_size].Destination;
		printf("День следования(1 - Понедельник, 2 - Вторник, и т.д.): ");
		do {
			railwaybase[current_size].Following_day = Correct_Input_Integer();
			if (railwaybase[current_size].Following_day < 1 || railwaybase[current_size].Following_day > 7)
				printf("Такого дня нет!\nВведите ещё раз: ");
		} while (railwaybase[current_size].Following_day < 1 || railwaybase[current_size].Following_day > 7);
		printf("Время прибытия(В формате ЧЧ:ММ): ");
		Correct_Input_Retirement_Time();
		printf("Время отправления(В формате ЧЧ:ММ): ");
		Correct_Input_Departure_Time();
		printf("**********************************************************\n");
		current_size++;
		return 0;
	}
	else {
		printf("Введено максимальное количество поездов!\n");
		return 0;
	}
}
int out()
{
	for (int i = 0; i < current_size; i++) {
		printf("--------------------------Поезд номер %d-------------------------------------------\n", i + 1);
		printf("Номер поезда: %d\n", railwaybase[i].NumberTrain);
		printf("Пункт назначения: %s\n", railwaybase[i].Destination);
		printf("День следования: ");
		if (railwaybase[i].Following_day == MONDAY)
			printf("Понедельник\n");
		if (railwaybase[i].Following_day == TUESDAY)
			printf("Вторник\n");
		if (railwaybase[i].Following_day == WEDNESDAY)
			printf("Среда\n");
		if (railwaybase[i].Following_day == THURSDAY)
			printf("Четверг\n");
		if (railwaybase[i].Following_day == FRIDAY)
			printf("Пятница\n");
		if (railwaybase[i].Following_day == SATURDAY)
			printf("Суббота\n");
		if (railwaybase[i].Following_day == SUNDAY)
			printf("Воскресенье\n");
		printf("Время прибытия: %d:%d\n", railwaybase[i].Retirement_time_hours, railwaybase[i].Retirement_time_minutes);
		printf("Время отправления: %d:%d\n", railwaybase[i].Departure_time_hours, railwaybase[i].Departure_time_minutes);
	}
	printf("---------------------------------------------------------------------\n");
	return 0;
}
int delete_client()
{
	int d;
	printf("**********************************************************\n");
	printf("Введите номер поезда по счету(1-20): ");
	do {
		d = Correct_Input_Integer();
		if (d < 1 || d > current_size)
			printf("Такого номера нет!\nВведите ещё раз: ");
	} while (d < 1 || d > current_size);
	for (int de1 = (d - 1); de1 < current_size; de1++)
		railwaybase[de1] = railwaybase[de1 + 1];
	current_size = current_size - 1;
	printf("Удаление завершено.\n");
	printf("**********************************************************\n");
	return 0;
}
int find_client()
{
	printf("**********************************************************\n");
	printf("Введите номер поезда: ");
	int numb;
	bool pr = true;
	numb = Correct_Input_Integer();
	for (int i = 0; i < current_size; i++) {
		if (numb == railwaybase[i].NumberTrain) {
			printf("---------------------------------------------------------------------\n");
			printf("Номер поезда: %d\n", railwaybase[i].NumberTrain);
			printf("Пункт назначения: %s\n", railwaybase[i].Destination);
			printf("День следования: ");
			if (railwaybase[i].Following_day == MONDAY)
				printf("Понедельник\n");
			if (railwaybase[i].Following_day == TUESDAY)
				printf("Вторник\n");
			if (railwaybase[i].Following_day == WEDNESDAY)
				printf("Среда\n");
			if (railwaybase[i].Following_day == THURSDAY)
				printf("Четверг\n");
			if (railwaybase[i].Following_day == FRIDAY)
				printf("Пятница\n");
			if (railwaybase[i].Following_day == SATURDAY)
				printf("Суббота\n");
			if (railwaybase[i].Following_day == SUNDAY)
				printf("Воскресенье\n");
			printf("Время прибытия: %d:%d\n", railwaybase[i].Retirement_time_hours, railwaybase[i].Retirement_time_minutes);
			printf("Время отправления: %d:%d\n", railwaybase[i].Departure_time_hours, railwaybase[i].Departure_time_minutes);
			printf("---------------------------------------------------------------------\n");
			pr = false;
		}
	}
	if (pr == true)
		printf("Такого поезда нет.\n");
	return 0;
}
//Функции корректного ввода:
//Корректный ввод времени
int Correct_Input_Retirement_Time() {
	bool prov = true;
	char ch[30];
	char chHours[3];
	char chMinutes[3];
	while (prov) {
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[5] == '\0') {
			if (ch[0] == '0' || ch[0] == '1')
				if (ch[1] >= '0' && ch[1] <= '9')
					if (ch[2] == ':')
						if ((ch[3] >= '0' && ch[3] <= '5' && ch[4] >= '0' && ch[4] <= '9'))
							prov = false;
			if (ch[0] == '2')
				if (ch[1] >= '0' && ch[1] <= '3')
					if (ch[2] == ':')
						if ((ch[3] >= '0' && ch[3] <= '5' && ch[4] >= '0' && ch[4] <= '9'))
							prov = false;
		}
		if (prov == true)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (prov == false) {
			chHours[0] = ch[0];
			chHours[1] = ch[1];
			chHours[2] = '\0';
			chMinutes[0] = ch[3];
			chMinutes[1] = ch[4];
			chMinutes[2] = '\0';
		}
	}
	railwaybase[current_size].Retirement_time_hours = atoi(chHours);
	railwaybase[current_size].Retirement_time_minutes = atoi(chMinutes);
	return 0;
}
int Correct_Input_Departure_Time() {
	bool prov = true;
	char ch[30];
	char chHours[3];
	char chMinutes[3];
	while (prov == true) {
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[5] == '\0') {
			if (ch[0] == '0' || ch[0] == '1')
				if (ch[1] >= '0' && ch[1] <= '9')
					if (ch[2] == ':')
						if ((ch[3] >= '0' && ch[3] <= '5' && ch[4] >= '0' && ch[4] <= '9'))
							prov = false;
			if (ch[0] == '2')
				if (ch[1] >= '0' && ch[1] <= '3')
					if (ch[2] == ':')
						if ((ch[3] >= '0' && ch[3] <= '5' && ch[4] >= '0' && ch[4] <= '9'))
							prov = false;
		}
		if (prov == true)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (prov == false) {
			chHours[0] = ch[0];
			chHours[1] = ch[1];
			chHours[2] = '\0';
			chMinutes[0] = ch[3];
			chMinutes[1] = ch[4];
			chMinutes[2] = '\0';
		}
	}
	railwaybase[current_size].Departure_time_hours = atoi(chHours);
	railwaybase[current_size].Departure_time_minutes = atoi(chMinutes);
	return 0;
}
//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[30];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		proverka_2 = 0;
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
				if (ch[i] >= '0' && ch[i] <= '9' && proverka_2 != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka_2 != 1) {
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
