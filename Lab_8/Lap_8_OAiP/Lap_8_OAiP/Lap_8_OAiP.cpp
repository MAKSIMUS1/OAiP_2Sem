//Вариант 4
//Создать очередь для символов и функции для ввода, вывода и определения размера очереди.
//Ввести символы с экрана в очередь. 
//В случае совпадения вводимого символа с последним элементом очереди удалить первых три элемента. 
#include "Header.h"
#include <iostream>
using namespace std;

struct myQue
{
	int a;
	char b;
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
	if (!s.isEmpty())
	{
		for (int i = 0; i < (s.Tail - 3); i++)
			s.Data[i] = s.Data[i + 3];
		s.Tail -= 3;
	}
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
		cout << "9 - Выход" << endl;
		cin >> choice;
		cout << "-------------------------------------------" << endl;
		switch (choice)
		{
		case 1: 
			char symb;
			if (numberofel == sizeofque) {
				cout << "Очередь заполнена!" << endl;
				break;
			}
			else {
				cout << "Введите символ: ";
				cin >> symb;
				myQue* a = new myQue;
				a->a = numberofel + 1;
				a->b = symb;
				enQueue(q1, a);
				numberofel++;
				if (numberofel > 3 && lasteq(q1)) {
					delthreeel(q1);
					numberofel -= 3;
				}
				break;
			}
		case 2: printQueue(q1);
			break;
		case 3: cout << "Размер очереди: " << sizeofque << endl;
			cout << "Занимаемый размер очереди информацией: " << numberofel << endl;
			break;
		case 9: return 0;
			break;
		default:   cout << "Неправильный выбор" << endl;
			cin.clear();
			break;
		}
	}
}
