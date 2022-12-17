#include <iostream>
#include "myStack_3.h"
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;
void push(int x, Stack* myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле e 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед
}
int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else
	{
		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
		int a = myStk->head->data;   //запись числа из поля data в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}
void show(Stack* myStk)    //Вывод стека
{
	Stack* e = myStk->head;    //объявляется указатель на вершину стека
	bool work = false;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;          //запись значения в переменную a 
		cout << a << "-->";
		e = e->next;
		work = true;
	}
	if (work)
		cout << "Конец стека!" << endl;
}
void clear(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
	}
	else
	{
		while (myStk->head != NULL) {
			Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
			int a = myStk->head->data;   //запись числа из поля data в переменную a 
			myStk->head = myStk->head->next; //перенос вершины
			delete e;//удаление временной переменной
		}
	}
	cout << "Очистка завершена!" << endl;
}
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2)
{
	while (myStk1->head != NULL) {
		Stack* e1 = myStk1->head;   //е - переменная для хранения адреса элемента
		int a = myStk1->head->data;   //запись числа из поля data в переменную a 
		myStk1->head = myStk1->head->next; //перенос вершины
		delete e1;//удаление временной переменной
	}
	/////////////////
	while (myStk2->head != NULL) {
		Stack* e2 = myStk2->head;   //е - переменная для хранения адреса элемента
		int a = myStk2->head->data;   //запись числа из поля data в переменную a 
		myStk2->head = myStk2->head->next; //перенос вершины
		delete e2;//удаление временной переменной
	}
	if (myStk->head == NULL)
		printf("Стек пуст.\n");
	else
	{
		Stack* e = myStk->head;    //объявляется указатель на вершину стека
		bool work = false;
		int a;
		while (e != NULL)
		{
			a = e->data;          //запись значения в переменную a
			if (a > 0) {	// Stack1 из четных элементов

				Stack* e1 = new Stack;    //выделение памяти для нового элемента
				e1->data = a;             //запись элемента x в поле e 
				e1->next = myStk1->head;   //перенос вершины на следующий элемент 
				myStk1->head = e1;         //сдвиг вершины на позицию вперед
			}
			if (a < 0) {	// Stack2 из нечетных

				Stack* e2 = new Stack;    //выделение памяти для нового элемента
				e2->data = a;             //запись элемента x в поле e 
				e2->next = myStk2->head;   //перенос вершины на следующий элемент 
				myStk2->head = e2;         //сдвиг вершины на позицию вперед
			}
			e = e->next;
		}
		printf("Построение завершенно.\n");
	}
}
void show_stacks(Stack* myStk1, Stack* myStk2) {
	Stack* e1 = myStk1->head;    //объявляется указатель на вершину стека
	bool work = false;
	int a;
	if (e1 == NULL)
		cout << "Стек Stack1 пуст!" << endl;
	while (e1 != NULL)
	{
		a = e1->data;          //запись значения в переменную a 
		cout << a << "-->";
		e1 = e1->next;
		work = true;
	}
	if (work)
		cout << "Конец стека Stack1!" << endl;
	/////////////////////////////////////////
	Stack* e2 = myStk2->head;    //объявляется указатель на вершину стека
	work = false;
	if (e2 == NULL)
		cout << "Стек Stack2 пуст!" << endl;
	while (e2 != NULL)
	{
		a = e2->data;          //запись значения в переменную a 
		cout << a << "-->";
		e2 = e2->next;
		work = true;
	}
	if (work)
		cout << "Конец стека Stack2!" << endl;
}

void toFile(Stack* myStk)
{
	Stack* e = myStk->head;
	fout.open("file.txt");
	if (fout.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	if (e == NULL)
		cout << "Стек пуст! В файл ничего записано не будет!" << endl;
	while (e != NULL)
	{
		fout << e->data << " ";
		e = e->next;
	}
	fout.close();
	cout << "Запись в файл завершена успешно!" << endl;
}
int fromFile(Stack* myStk)
{
	fin.open("file.txt");
	int value;
	fin >> value;
	if (fin.eof()) {
		fin.close();
		return -1;
	}
	Stack* Stkfile = new Stack;
	Stkfile->data = value;
	myStk->head = Stkfile;
	while (true) {
		fin >> value;
		if (fin.eof()) {
			break;
		}
		Stkfile->next = new Stack;
		Stkfile = Stkfile->next;
		Stkfile->data = value;
	}
	Stkfile->next = NULL;
	fin.close();
	return 1;
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