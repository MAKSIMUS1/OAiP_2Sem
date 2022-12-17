#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;

struct list
{
	int number;
	list* next;
};

ofstream fout;
ifstream fin;

int Correct_Input_Integer();
void insert(list*& p, int value); //Добавление символа в начало списка
void printList(list* p);	       //Вывод списка 
void toFile(list*&);             //Запись в файл
void fromFile(list*&);           //Считывание из файла
void menu(void);                   //Вывод меню 
char del(list*& p, int value);    //Удаление символа
bool IsEmpty(list*);		       //Список пустой?
void find(list* p, int value);	   //Поиск
void sum(list* p, int value);	   //Найти сумму положительных двухзначных элементов или выдать сообщение, что таких элементов нет. 
void negsum(list* p, int value);   //Найти сумму отрицательных двухзначных элементов или выдать сообщение, что таких элементов нет.
void negsum_three(list* p, int value);//Найти сумму отрицательных элементов, у которых последняя цифра 3 или выдать сообщение, что таких элементов нет. 

int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice, value;
	menu();    // вывести меню 
	cout << " ? ";
	choice = Correct_Input_Integer();
	while (choice != 10)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите число целого типа: ";
			value = Correct_Input_Integer();
			insert(first, value);
			break;
		case 2:
			if (!IsEmpty(first)) // удалить число из списка
			{
				cout << "Введите число, которое хотите удалить: ";
				cin >> value;
				if (del(first, value))
					cout << "Цифра удалена " << value << endl;
				else
					cout << "Цифра не найдена!" << endl;
			}
			else
				cout << "Список пуст" << endl;
			break;
		case 3:    printList(first);
			break;
		case 4:
			cout << "Введите число, которое хотите найти: ";
			value = Correct_Input_Integer();
			find(first, value);
			cout << endl;
			break;
		case 5:
			toFile(first);
			break;
		case 6:
			fromFile(first);
			break;
		case 7:
			sum(first, value);
			break;
		case 8:
			negsum(first, value);
			break;
		case 9:
			negsum_three(first, value);
			break;
		default:   
			cout << "Неправильный выбор" << endl;
			cin.clear();
			break;
		}
		cout << "?  ";
		choice = Correct_Input_Integer();
	}
	return 0;
}

void insert(list*& p, int value) //Добавление символа в начало списка
{
	list* newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* first = p;
	list buf;
	fout.open("Var5.txt");
	if (fout.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			fout << p->number << " ";
			p = p->next;
		}
	}
	fout.close();
	cout << endl << "Список записан в файл Var5.txt" << endl;
	p = first;
}

void fromFile(list*& p)          //Считывание из файла
{
	fin.open("Var5.txt");
	int value;
	fin >> value;
	if (fin.eof()) {
		p = NULL;
		fin.close();
		return;
	}

	list* first = new list;
	first->number = value;
	p = first;

	while (true) {
		fin >> value;
		if (fin.eof()) {
			break;
		}
		first->next = new list;
		first = first->next;
		first->number = value;
	}
	first->next = NULL;
	fin.close();
	cout << endl << "Список считан из файла Var5.txt" << endl;
}

void menu(void)     //Вывод меню 
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа" << endl;
	cout << " 2 - Удаление числа" << endl;
	cout << " 3 - Вывести числа" << endl;
	cout << " 4 - Поиск числа" << endl;
	cout << " 5 - Запись списка в файл" << endl;
	cout << " 6 - Вывод списка из файла" << endl;
	cout << " 7 - Найти сумму положительных двухзначных элементов (Вариант 5) " << endl;
	cout << " 8 - Найти сумму отрицательных двухзначных элементов (Вариант 6)" << endl;
	cout << " 9 - Найти сумму отрицательных элементов, у которых последняя цифра 3 (Вариант 7)" << endl;
	cout << " 10 - Выход" << endl;
}

char del(list*& p, int value)	//Удаление символа
{
	while (p != NULL) {
		list* previous, * current, * temp;
		if (value == p->number) {	//(*p).number==value)
			temp = p;
			p = p->next;    // отсоединить узел 
			delete temp;      //освободить отсоединенный узел 
			return value;
		}
		else
		{
			previous = p;
			current = p->next;
			while (current != NULL && current->number != value)
			{
				previous = current;
				current = current->next; // перейти к следующему 
			}
			if (current != NULL)
			{
				temp = current;
				previous->next = current->next;
				delete temp;
				return value;
			}
		}
		return 0;
	}
	return 0;
}

bool IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
	return p == NULL;
}

void find(list* p, int value) {
	bool work = false;
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if (p->number == value) {
				cout << endl << "Элемент \"" << p->number << "\" найден.";
				work = true;
				break;
			}
			p = p->next;
		}
	}
	if (!work) {
		cout << endl << "Элемент не найден!" << endl;
	}
}

void sum(list* p, int value) {
	int sum = 0;
	bool work = false;
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if (p->number > 9 && p->number < 100) {
				sum += (p->number);
				work = true;
			}
			p = p->next;
		}
	}
	if (!work) {
		cout << endl << "Нет двухзначных элементов!" << endl;
	}
	else {
		cout << "Сумма двухзначных элементов = " << sum << endl;
	}
}

void negsum(list* p, int value) {
	int sum = 0;
	bool work = false;
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if (p->number < -9 && p->number > -100) {
				sum += (p->number);
				work = true;
			}
			p = p->next;
		}
	}
	if (!work) {
		cout << endl << "Нет отрицательных двухзначных элементов!" << endl;
	}
	else {
		cout << "Сумма отрицательных двухзначных элементов = " << sum << endl;
	}
}

void negsum_three(list* p, int value) {
	int sum = 0;
	bool work = false;
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if ((p->number < 0 && p->number % 10 == -3) || (p->number < 0 && p->number / 3 == -1)) {
				sum += (p->number);
				work = true;
			}
			p = p->next;
		}
	}
	if (!work) {
		cout << endl << "Нет отрицательных элементов, у которых последняя цифра 3!" << endl;
	}
	else {
		cout << "Сумма отрицательных элементов, у которых последняя цифра 3 = " << sum << endl;
	}
}
//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		proverka_2 = 0;
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
				proverka_2 = 1;
				break;
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) 
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
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