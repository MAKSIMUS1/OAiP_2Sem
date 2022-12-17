//Вариант 8
//Создать очередь для целых чисел и функции для ввода, вывода, удаления и определения размера очереди.
//Разработать функцию, которая удаляет из очереди первый отрицательный элемент, если такой есть.
#include "Header_DOP_2.h"
#include <iostream>
using namespace std;

struct myQue
{
	int a;
	int b;
};
void printQueue(Queue& s)    // Вывод на экран    
{
	if (s.isEmpty())
		cout << "Очередь пуста!" << endl;
	else {
		Queue cpys = s;
		while (!(cpys.isEmpty()))
		{
			cout << ((myQue*)peekQueue(cpys))->b << endl;
			delQueue(cpys);
		}
	}
}
void delthreeel(Queue& s)
{
	bool pr = false;
	int numb;
	int chis;
	void* rc;
	if (!s.isEmpty())
	{
		for (int i = 0; i < (s.Tail); i++) {
			rc = s.Data[i];
			if (((myQue*)rc)->b < 0) {
				pr = true;
				numb = i;
				break;
			}
		}
		if (pr == true) {
			for (int i = numb; i < s.Tail; i++)
				s.Data[i] = s.Data[i + 1];
			s.Tail--;
		}
		else
			printf("Такого элемента нет.\n");
	}
	else
		cout << "Очередь пуста!" << endl;
}
bool lasteq(Queue& q)
{
	return (((myQue*)peekQueue(q))->b == ((myQue*)peeklastQueue(q))->b);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int sizeofque, numberofel = 0;
	cout << "Введите размер очереди: ";
	do {
		sizeofque = Correct_Input_Integer();
		if (sizeofque <= 0)
			printf("Нужно больше 0.\nВведите ещё раз: ");
	} while (sizeofque <= 0);
	Queue q1 = createQueue(sizeofque);
	int choice;
	for (;;)
	{
		cout << "-------------------------------------------" << endl;
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в очередь" << endl;
		cout << "2 - Вывод очереди" << endl;
		cout << "3 - Размер очереди" << endl;
		cout << "4 - для удаления очереди" << endl;
		cout << "5 - удаляет из очереди первый отрицательный элемент, если такой есть" << endl;
		cout << "9 - Выход" << endl;
		cin >> choice;
		cout << "-------------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			int symb;
			if (numberofel == sizeofque) {
				cout << "Очередь заполнена!" << endl;
				break;
			}
			else {
				cout << "Введите число: ";
				symb = Correct_Input_Integer();
				myQue* a = new myQue;
				a->a = numberofel + 1;
				a->b = symb;
				enQueue(q1, a);
				numberofel++;
				break;
			}
		case 2: printQueue(q1);
			break;
		case 3: 
			cout << "Размер очереди: " << sizeofque << endl;
			cout << "Занимаемый размер очереди информацией: " << numberofel << endl;
			break;
		case 4:
			clearQueue(q1);
			numberofel = 0;
			break;
		case 5:
			delthreeel(q1);
			numberofel--;
			break;
		case 9: 
			return 0;
			break;
		default:   cout << "Неправильный выбор" << endl;
			cin.clear();
			break;
		}
	}
}
