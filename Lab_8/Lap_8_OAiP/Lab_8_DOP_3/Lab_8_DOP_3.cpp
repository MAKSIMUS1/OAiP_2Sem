//Вариант 2
//Создать очередь для целых чисел и функции для ввода, вывода и удаления очереди. 
//Найти количество элементов между максимальным и минимальным элементами очереди. 
#include "Header_DOP_3.h"
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
	int numb_min, numb_max;
	int min = INT_MAX; 
	int max = INT_MIN;
	void* rc;
	if (!s.isEmpty() && s.Tail > 1)
	{

		for (int i = 0; i < (s.Tail); i++) {
			rc = s.Data[i];
			if (((myQue*)rc)->b > max) {
				max = ((myQue*)rc)->b;
				numb_max = i;
			}
			if (((myQue*)rc)->b < min) {
				min = ((myQue*)rc)->b;
				numb_min = i;
			}
		}
		cout << "Максимальный элемент: " << max << endl;
		cout << "Минимальный элемент: " << min << endl;
		cout << "Количество элементов между максимальным и минимальным элементами очереди: " << abs(numb_max - numb_min) - 1 << endl;
	}
	else
		cout << "Очередь пуста или нужно больше 1 эелемента! " << endl;
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
		cout << "3 - для удаления очереди" << endl;
		cout << "4 - найти количество элементов между максимальным и минимальным элементами очереди" << endl;
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
			clearQueue(q1);
			numberofel = 0;
			break;
		case 4:
			delthreeel(q1);
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
