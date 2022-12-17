#include "Header_DOP_2.h"
#include <iostream>
using namespace std;
Queue createQueue(int n)          // Выделить ресурс для очереди
{
	return *(new Queue(n));
};
Queue createQueue(const Queue& pq)   // Создать очередь 
{
	Queue* rc = new Queue(pq.Size - 1);
	rc->Head = pq.Head;
	rc->Tail = pq.Tail;
	for (int i = 0; i < pq.Size; i++)
		rc->Data[i] = pq.Data[i];
	return *rc;
}
bool Queue::isFull() const         // Очередь заполненa?
{
	return (Head % Size == (Tail + 1) % Size);
}
bool Queue::isEmpty() const         // Очередь пустa?
{
	return (Head % Size == Tail % Size);
}
bool enQueue(Queue& q, void* x)      // Добавить элемент x 
{
	bool rc = true;
	if (rc = !q.isFull())
	{
		q.Data[q.Tail] = x;
		q.Tail = (q.Tail + 1) % q.Size;
	}
	else
		rc = false;
	return rc;
};

void* delQueue(Queue& q)               // Удалить элемент 
{
	void* rc = (void*)MYQUEUE1_EQE;
	if (!q.isEmpty())
	{
		rc = q.Data[q.Head];
		q.Head = (q.Head + 1) % q.Size;
	}
	else
		rc = nullptr;
	return rc;
}

void* peekQueue(Queue& q)  // Получить первый элемент очереди
{
	void* rc = (void*)MYQUEUE1_EQE;
	if (!q.isEmpty())
		rc = q.Data[q.Head];
	else
		rc = nullptr;
	return rc;
}

int  clearQueue(Queue& q)       // Очистить очередь
{
	int rc = (q.Tail - q.Head) >= 0 ? q.Tail - q.Head : (q.Size - q.Head + q.Tail + 1);
	q.Tail = q.Head = 0;
	return rc;     // колич. элементов до очистки
}
void releaseQueue(Queue& q)     // Освободить ресурсы очереди
{
	delete[] q.Data;
	q.Size = 1;
	q.Head = q.Tail = 0;
}
void* peeklastQueue(Queue& q)  // Получить первый элемент очереди
{
	void* rc = (void*)MYQUEUE1_EQE;
	if (!q.isEmpty())
		rc = q.Data[q.Tail - 1];
	else
		rc = nullptr;
	return rc;
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