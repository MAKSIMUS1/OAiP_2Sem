#include "Header.h"
#include <iostream>
#include <iomanip>
using namespace std;


void AAA::Print()
{
	std::cout << x;
}
int AAA::GetPriority()
{
	return x;
}

namespace heap
{
	Heap Create(int maxsize, CMP(*f)(void*, void*))	//Создание кучи
	{
		return *(new Heap(maxsize, f));
	}

	int Heap::Left(int ix)		//Левая ветка
	{
		return (2 * ix + 1 >= Size) ? -1 : (2 * ix + 1);
	}

	int Heap::Right(int ix)		//Правая ветка
	{
		return (2 * ix + 2 >= Size) ? -1 : (2 * ix + 2);
	}

	int Heap::Parent(int ix)	//Родитель
	{
		return (ix + 1) / 2 - 1;
	}

	void Heap::Swap(int i, int j)	//Меняем местами
	{
		void* buf = Storage[i];
		Storage[i] = Storage[j];
		Storage[j] = buf;
	}

	void Heap::Heapify(int ix)	//Упорядочивание кучи
	{
		int l = Left(ix), r = Right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(Storage[l], Storage[ix]))
				irl = l;

			if (r > 0 && isGreat(Storage[r], Storage[irl]))

				irl = r;

			if (irl != ix)
			{
				Swap(ix, irl);
				Heapify(irl);
			}
		}
	}

	void Heap::Insert(void* x)	//Вставка элемента
	{
		int i;
		if (!isFull())
		{
			i = Size;
			Storage[i] = x;
			Size++;
			while (i > 0 && isLess(Storage[Parent(i)], Storage[i]))
			{
				Swap(Parent(i), i);
				i = Parent(i);
			}
		}
	}

	void* Heap::ExtractMax()	//Извлечение максимального
	{
		void* rc = NULL;
		if (!isEmpty())
		{
			rc = Storage[0];
			Storage[0] = Storage[Size - 1];
			Size--;
			Heapify(0);
		}
		Heapify(0);
		return rc;
	}

	void Heap::Scan(int i)		//Вывод кучи
	{
		int probel = 20;
		std::cout << '\n';
		if (Size == 0)
			std::cout << "Куча пуста!";
		for (int u = 0, y = 0, level = 1; u < Size; u++)

		{
			cout << setw(probel + 10) << setfill(' ');

			((AAA*)Storage[u])->Print();
			if (u == y)
			{
				level++;
				cout << '\n';
				if (y == 0)
					y = 2;
				else y = pow(2, level) - 2;
			}
			probel /= 2;
		}
		cout << '\n';
	}

	void Heap::DeleteHeap()		//Полное очищение кучи
	{
		if (!isEmpty())
		{
			Size = 0;
			this->~Heap();
		}
	}


	void* Heap::ExtractMin()	//Извлечение минимального
	{
		void* rc = NULL;
		if (Size > 0)
		{
			int j = Size / 2;
			for (int i = Size / 2; i < Size; i++)

			{
				if (Compare(Storage[i], Storage[j]) == LESS)
				{
					j = i;
				}
			}
			rc = Storage[j];
			Swap(j, Size - 1);
			Size--;
		}
		Heapify(0);
		return rc;
	}


	void* Heap::ExtractI(int i)	//Извлечение i-того элемента
	{
		void* rc = NULL;
		if (Size > 0 && i >= 0 && i < Size)
		{
			rc = Storage[i];
			Swap(i, Size - 1);
			Size--;
		}
		Heapify(0);
		return rc;
	}


	void Heap::Union(Heap& h2)	//Объединение куч
	{
		while (!h2.isEmpty())
			Insert(h2.ExtractMax());

	}
}

//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[20];

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